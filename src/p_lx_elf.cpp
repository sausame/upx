/* p_lx_elf.cpp --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2000 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2000 Laszlo Molnar
   Copyright (C) 2000 John F. Reiser.  All rights reserved.

   UPX and the UCL library are free software; you can redistribute them
   and/or modify them under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer                   Laszlo Molnar
   markus.oberhumer@jk.uni-linz.ac.at        ml1050@cdata.tvnet.hu

   John F. Reiser
   jreiser@BitWagon.com
 */


#include "conf.h"

#include "file.h"
#include "packer.h"
#include "p_elf.h"
#include "p_unix.h"
#include "p_lx_elf.h"


static const
#include "stub/l_le_n2b.h"
static const
#include "stub/l_le_n2d.h"

PackLinuxI386elf::~PackLinuxI386elf()
{
}

PackLinuxI386elf::PackLinuxI386elf(InputFile *f)
    :super(f)
    ,phdri(0)
{
}

const upx_byte *PackLinuxI386elf::getLoader() const
{
    if (M_IS_NRV2B(opt->method))
        return linux_i386elf_nrv2b_loader;
    if (M_IS_NRV2D(opt->method))
        return linux_i386elf_nrv2d_loader;
    return NULL;
}

int PackLinuxI386elf::getLoaderSize() const
{
    if (0 != lsize) {
        return lsize;
    }
    if (M_IS_NRV2B(opt->method))
        return sizeof(linux_i386elf_nrv2b_loader);
    if (M_IS_NRV2D(opt->method))
        return sizeof(linux_i386elf_nrv2d_loader);
    return 0;
}


static inline off_t min_off_t(off_t a, off_t b)
{
    return a < b ? a : b;
}

static inline off_t max_off_t(off_t a, off_t b)
{
    return a > b ? a : b;
}

static off_t getbrk(Elf_LE32_Phdr const *phdr, int e_phnum)
{
    off_t brka = 0;
    for (int j = 0; j < e_phnum; ++phdr, ++j) if (PT_LOAD==phdr->p_type) {
        brka = max_off_t(brka, phdr->p_vaddr + phdr->p_memsz);
    }
    return brka;
}


void PackLinuxI386elf::updateLoader(OutputFile *fo)
{
#define PAGE_MASK (~0<<12)
    Elf_LE32_Phdr *const phdro = (Elf_LE32_Phdr *)(sizeof(Elf_LE32_Ehdr)+loader);
    off_t const totlen = fo->getBytesWritten();
    phdro->p_filesz = totlen;

    // pre-calculate for benefit of runtime disappearing act via munmap()
    phdro->p_memsz =  PAGE_MASK & (~PAGE_MASK + totlen);

    patchLoaderChecksum();
    fo->seek(0, SEEK_SET);
    fo->rewrite(loader, 0x80);
#undef PAGE_MASK
}

void PackLinuxI386elf::patchLoader()
{
    lsize = getLoaderSize();
    Elf_LE32_Ehdr *const ehdr = (Elf_LE32_Ehdr *)(void *)loader;
    Elf_LE32_Phdr *const phdr = (Elf_LE32_Phdr *)(1+ehdr);

    // stub/scripts/setfold.pl puts address of 'fold_begin' in phdr[1].p_offset
    off_t const fold_begin = phdr[1].p_offset;
    MemBuffer cprLoader(lsize);

    // compress compiled C-code portion of loader
    upx_compress_config_t conf; memset(&conf, 0xff, sizeof(conf));
    conf.c_flags = 0;
    upx_uint result_buffer[16];
    size_t cprLsize;
    upx_compress(
        loader + fold_begin, lsize - fold_begin,
        cprLoader, &cprLsize,
        0,  // progress_callback_t ??
        getCompressionMethod(), 9,
        &conf,
        result_buffer
    );
    set_le32(0+fold_begin+loader, lsize - fold_begin);
    set_le32(4+fold_begin+loader, cprLsize);
    memcpy(  8+fold_begin+loader, cprLoader, cprLsize);
    lsize = 8 + fold_begin + cprLsize;
    patchVersion(loader,lsize);

    // Info for OS kernel to set the brk()
    unsigned const brka = getbrk(phdri, ehdri.e_phnum);
    phdr[1].p_offset = 0xfff&brka;
    phdr[1].p_vaddr = brka;
    phdr[1].p_paddr = brka;
    phdr[1].p_filesz = 0;
    phdr[1].p_memsz =  0;

    // The beginning of our loader consists of a elf_hdr (52 bytes) and
    // two sections elf_phdr (2 * 32 byte), so we have 12 free bytes
    // from offset 116 to the program start at offset 128.
    assert(ehdr->e_phoff == sizeof(*ehdr));
    assert(ehdr->e_ehsize == sizeof(*ehdr));
    assert(ehdr->e_phentsize == sizeof(Elf_LE32_Phdr));
    assert(ehdr->e_phnum == 2);
    assert(ehdr->e_shnum == 0);
    assert(lsize > 128 && lsize < 4096);

    patchLoaderChecksum();
}


bool PackLinuxI386elf::canPack()
{
    unsigned char buf[512];

    fi->readx(buf,512);
    fi->seek(0,0);
    if (0==memcmp(buf, "\x7f\x45\x4c\x46\x01\x01\x01", 7)) { // ELF 32-bit LSB
        Elf_LE32_Ehdr const *const ehdr = (Elf_LE32_Ehdr const *)buf;
        Elf_LE32_Phdr const *phdr = (Elf_LE32_Phdr const *)(ehdr->e_phoff +
            (char const *)ehdr);
        if (ehdr->e_phoff != sizeof(*ehdr)) {// Phdrs not contiguous with Ehdr
            return false;
        }
        // The first PT_LOAD must cover the beginning of the file (0==p_offset).
        for (unsigned j=0; j < ehdr->e_phnum; ++phdr, ++j) {
            if (PT_LOAD==phdr->p_type) {
                if (phdr->p_offset!=0) {
                    return false;
                }
                break;
            }
        }
        return super::canPack();
    }
    return false;
}


void PackLinuxI386elf::packExtent(
    Extent const &x,
    OutputFile *fo,
    unsigned &total_in,
    unsigned &total_out
)
{
    blocksize = opt->unix.blocksize;
    if ((off_t)blocksize > x.size)
        blocksize = x.size;

    fi->seek(x.offset, SEEK_SET);
    for (off_t rest = x.size; 0!=rest; )
    {
        int l = fi->readx(ibuf, min_off_t(rest, blocksize));
        rest -= l;
        if (l == 0)
            break;

        // Note: compression for a block can fail if the
        //       file is e.g. blocksize + 1 bytes long

        // compress
        ph.u_len = l;
        compress(ibuf, obuf);   // ignore return value

        if (ph.c_len < ph.u_len)
        {
            if (!testOverlappingDecompression(obuf, OVERHEAD))
                throwNotCompressible();
        }
        else
        {
            ph.c_len = ph.u_len;
            // must update checksum of compressed data
            ph.c_adler = upx_adler32(ph.c_adler, ibuf, ph.u_len);
        }

        // write block sizes
        unsigned char size[8];
        set_native32(size+0, ph.u_len);
        set_native32(size+4, ph.c_len);
        fo->write(size, 8);

        // write compressed data
        if (ph.c_len < ph.u_len)
        {
            fo->write(obuf, ph.c_len);
            verifyOverlappingDecompression(&obuf, OVERHEAD);
        }
        else
            fo->write(ibuf, ph.u_len);

        total_in += ph.u_len;
        total_out += ph.c_len;
    }
}


void PackLinuxI386elf::pack(OutputFile *fo)
{
    // set options
    opt->unix.blocksize = file_size;
    blocksize = file_size;
    progid = 0;  // not used

    fi->readx(&ehdri, sizeof(ehdri));
    off_t const sz_phdrs = ehdri.e_phnum * ehdri.e_phentsize;

    phdri = new Elf_LE32_Phdr[ehdri.e_phnum];
    fi->seek(ehdri.e_phoff, SEEK_SET);
    fi->readx(phdri, sz_phdrs);

    // prepare loader
    lsize = getLoaderSize();
    loader.alloc(lsize + sizeof(p_info));
    memcpy(loader,getLoader(),lsize);

    // patch loader, prepare header info, write loader + header info
    patchLoader();  // can change lsize by packing upx_main
    p_info *const hbuf = (p_info *)(loader + lsize);
    set_native32(&hbuf->p_progid, progid);
    set_native32(&hbuf->p_filesize, file_size);
    set_native32(&hbuf->p_blocksize, blocksize);
    fo->write(loader, lsize + sizeof(p_info));

    // init compression buffers
    ibuf.alloc(blocksize);
    obuf.allocForCompression(blocksize);

    assert(ehdri.e_phoff == sizeof(Elf_LE32_Ehdr));  // checked by canPack()
    Extent x;
    unsigned k;

    // count
    total_passes = 0;
    off_t ptload0hi=0, ptload1lo=0;
    int nx = 0;
    for (k = 0; k < ehdri.e_phnum; ++k) {
        if (PT_LOAD==phdri[k].p_type) {
            x.offset = phdri[k].p_offset;
            x.size   = phdri[k].p_filesz;
            if (0==ptload0hi) {
                ptload0hi = x.size + x.offset;
            }
            else if (0==ptload1lo) {
                ptload1lo =          x.offset;
            }
            total_passes++;
        } else {
            if (nx++ == 0)
                total_passes++;
        }
    }
    if (ptload0hi < ptload1lo)
        total_passes++;

    // compress extents
    unsigned total_in = 0;
    unsigned total_out = 0;

    x.offset = 0;
    x.size = sizeof(Elf_LE32_Ehdr) + sz_phdrs;
    pass = -1;
    packExtent(x, fo, total_in, total_out);
    pass = 0;

    nx = 0;
    for (k = 0; k < ehdri.e_phnum; ++k) if (PT_LOAD==phdri[k].p_type) {
        x.offset = phdri[k].p_offset;
        x.size   = phdri[k].p_filesz;
        if (0==nx) {
            x.offset += sizeof(Elf_LE32_Ehdr) + sz_phdrs;
            x.size   -= sizeof(Elf_LE32_Ehdr) + sz_phdrs;
        }
        packExtent(x, fo, total_in, total_out);
        ++nx;
    }
    if (ptload0hi < ptload1lo) { // alignment hole?
        x.offset = ptload0hi;
        x.size   = ptload1lo - ptload0hi;
        packExtent(x, fo, total_in, total_out);
    }
    if ((off_t)total_in < file_size) {  // non-PT_LOAD stuff
        x.offset = total_in;
        x.size = file_size - total_in;
        packExtent(x, fo, total_in, total_out);
    }

    if ((off_t)total_in != file_size)
        throw EOFException();

    // write block end marker (uncompressed size 0)
    fo->write("\x00\x00\x00\x00", 4);

    // update header with totals
    ph.u_len = total_in;
    ph.c_len = total_out;

    // write header
    const int hsize = ph.getPackHeaderSize();
    set_le32(obuf, ph.magic);               // note: always le32
    putPackHeader(obuf, hsize);
    fo->write(obuf, hsize);

    // write overlay offset (needed for decompression)
    set_native32(obuf, lsize);
    fo->write(obuf, 4);

    updateLoader(fo);

    // finally check compression ratio
    if (!super::checkCompressionRatio(fo->getBytesWritten(), ph.u_len))
        throwNotCompressible();
}


void PackLinuxI386elf::unpackExtent(unsigned wanted, OutputFile *fo,
    unsigned &total_in, unsigned &total_out,
    unsigned &c_adler, unsigned &u_adler)
{
    while (wanted) {
        fi->readx(ibuf, 8);
        int const sz_unc = ph.u_len = get_native32(ibuf+0);
        int const sz_cpr = ph.c_len = get_native32(ibuf+4);

        if (sz_unc == 0) { // must never happen while 0!=wanted
            throwCompressedDataViolation();
            break;
        }
        if (sz_unc <= 0 || sz_cpr <= 0)
            throwCompressedDataViolation();
        if (sz_cpr > sz_unc || sz_unc > (int)blocksize)
            throwCompressedDataViolation();

        int j = blocksize + OVERHEAD - sz_cpr;
        fi->readx(ibuf+j, sz_cpr);
        // update checksum of compressed data
        c_adler = upx_adler32(c_adler, ibuf + j, sz_cpr);
        // decompress
        if (sz_cpr < sz_unc)
        {
            decompress(ibuf+j, ibuf, false);
            j = 0;
        }
        // update checksum of uncompressed data
        u_adler = upx_adler32(u_adler, ibuf + j, sz_unc);
        total_in  += sz_cpr;
        total_out += sz_unc;
        // write block
        if (fo)
            fo->write(ibuf + j, sz_unc);
        wanted -= sz_unc;
    }
}


bool PackLinuxI386elf::canUnpackFormat(int format) const
{
    return UPX_F_LINUX_ELF_i386==format || UPX_F_LINUX_SEP_i386==format;
}

void PackLinuxI386elf::unpack(OutputFile *fo)
{
#define MAX_ELF_HDR 512
    char bufehdr[MAX_ELF_HDR];
    Elf_LE32_Ehdr *const ehdr = (Elf_LE32_Ehdr *)bufehdr;
    Elf_LE32_Phdr const *phdr = (Elf_LE32_Phdr *)(1+ehdr);

    fi->seek(overlay_offset, SEEK_SET);
    p_info hbuf;
    fi->readx(&hbuf, sizeof(hbuf));
    unsigned orig_file_size = get_native32(&hbuf.p_filesize);
    blocksize = get_native32(&hbuf.p_blocksize);
    if (file_size > (off_t)orig_file_size || blocksize > orig_file_size)
        throwCantUnpack("file header corrupted");

    ibuf.alloc(blocksize + OVERHEAD);
    fi->readx(ibuf, 2*4);
    ph.u_len = get_native32(0+ibuf);
    ph.c_len = get_native32(4+ibuf);

    // Uncompress Ehdr and Phdrs.
    fi->readx(ibuf, ph.c_len);
    decompress(ibuf, (upx_byte *)ehdr, false);

    unsigned total_in = 0;
    unsigned total_out = 0;
    unsigned c_adler = upx_adler32(0, NULL, 0);
    unsigned u_adler = upx_adler32(0, NULL, 0);
    off_t ptload0hi=0, ptload1lo=0;

    // decompress PT_LOAD
    fi->seek(-(2*4 + ph.c_len), SEEK_CUR);
    for (unsigned j=0; j < ehdr->e_phnum; ++phdr, ++j) {
        if (PT_LOAD==phdr->p_type) {
            if (0==ptload0hi) {
                ptload0hi = phdr->p_filesz + phdr->p_offset;
            }
            else if (0==ptload1lo) {
                ptload1lo = phdr->p_offset;
            }
            if (fo)
                fo->seek(phdr->p_offset, SEEK_SET);
            unpackExtent(phdr->p_filesz, fo, total_in, total_out, c_adler, u_adler);
        }
    }

    if (ptload0hi < ptload1lo) {  // alignment hole?
        if (fo)
            fo->seek(ptload0hi, SEEK_SET);
        unpackExtent(ptload1lo - ptload0hi, fo, total_in, total_out, c_adler, u_adler);
    }
    if (total_out != orig_file_size) {  // non-PT_LOAD stuff
        if (fo)
            fo->seek(0, SEEK_END);
        unpackExtent(orig_file_size - total_out, fo, total_in, total_out, c_adler, u_adler);
    }

    // check for end-of-file
    fi->readx(ibuf, 2*4);
    unsigned const sz_unc = ph.u_len = get_native32(ibuf+0);

    if (sz_unc == 0) { // uncompressed size 0 -> EOF
        // note: magic is always stored le32
        unsigned const sz_cpr = get_le32(ibuf+4);
        if (sz_cpr != UPX_MAGIC_LE32)  // sz_cpr must be h->magic
            throwCompressedDataViolation();
    }
    else { // extra bytes after end?
        throwCompressedDataViolation();
    }

    // update header with totals
    ph.c_len = total_in;
    ph.u_len = total_out;

    // all bytes must be written
    if (total_out != orig_file_size)
        throw EOFException();

    // finally test the checksums
    if (ph.c_adler != c_adler || ph.u_adler != u_adler)
        throwChecksumError();
#undef MAX_ELF_HDR
}


/*
vi:ts=4:et
*/

