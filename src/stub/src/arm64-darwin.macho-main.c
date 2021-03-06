/* arm-darwin.macho-main.c -- loader stub for Mach-o ARMEL

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2015 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2015 Laszlo Molnar
   Copyright (C) 2000-2015 John F. Reiser
   All Rights Reserved.

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

   Markus F.X.J. Oberhumer              Laszlo Molnar
   <markus@oberhumer.com>               <ml1050@users.sourceforge.net>

   John F. Reiser
   <jreiser@users.sourceforge.net>
 */


//#define SIMULATE_ON_DEBIAN_EABI4 1
#undef  SIMULATE_ON_DEBIAN_EABI4

#include "include/darwin.h"


/*************************************************************************
// configuration section
**************************************************************************/

// In order to make it much easier to move this code at runtime and execute
// it at an address different from it load address:  there must be no
// static data, and no string constants.


/*************************************************************************
// "file" util
**************************************************************************/

typedef struct {
    size_t size;  // must be first to match size[0] uncompressed size
    void *buf;
} Extent;


static void
xread(Extent *x, void *buf, size_t count)
{
    unsigned char *p=x->buf, *q=buf;
    size_t j;
    if (x->size < count) {
        exit(127);
    }
    for (j = count; 0!=j--; ++p, ++q) {
        *q = *p;
    }
    x->buf  += count;
    x->size -= count;
}


/*************************************************************************
// util
**************************************************************************/

#if 1  //{  save space
#define ERR_LAB error: exit(127);
#define err_exit(a) goto error
#else  //}{  save debugging time
#define ERR_LAB /*empty*/
static void
err_exit(int a)
{
    (void)a;  // debugging convenience
    exit(127);
}
#endif  //}


/*************************************************************************
// UPX & NRV stuff
**************************************************************************/

struct l_info { // 12-byte trailer for loader (after macho headers)
    unsigned l_checksum;
    unsigned l_magic;  // UPX_MAGIC_LE32
    unsigned short l_lsize;
    unsigned char l_version;
    unsigned char l_format;
};
struct p_info { // 12-byte packed program header
    unsigned p_progid;
    unsigned p_filesize;
    unsigned p_blocksize;
};

struct b_info { // 12-byte header before each compressed block
    unsigned sz_unc;  // uncompressed_size
    unsigned sz_cpr;  //   compressed_size
    unsigned char b_method;  // compression algorithm
    unsigned char b_ftid;  // filter id
    unsigned char b_cto8;  // filter parameter
    unsigned char b_unused;
};

typedef void f_unfilter(
    nrv_byte *,  // also addvalue
    nrv_uint,
    unsigned cto8, // junk in high 24 bits
    unsigned ftid
);
typedef int f_expand(
    const nrv_byte *, nrv_uint,
          nrv_byte *, nrv_uint *, unsigned );

static void
unpackExtent(
    Extent *const xi,  // input
    Extent *const xo,  // output
    f_expand *const f_decompress,
    f_unfilter *f_unf
)
{
    while (xo->size) {
        struct b_info h;
        //   Note: if h.sz_unc == h.sz_cpr then the block was not
        //   compressible and is stored in its uncompressed form.

        // Read and check block sizes.
        xread(xi, (unsigned char *)&h, sizeof(h));
        if (h.sz_unc == 0) {                     // uncompressed size 0 -> EOF
            if (h.sz_cpr != UPX_MAGIC_LE32)      // h.sz_cpr must be h->magic
                err_exit(2);
            if (xi->size != 0)                 // all bytes must be written
                err_exit(3);
            break;
        }
        if (h.sz_cpr <= 0) {
            err_exit(4);
ERR_LAB
        }
        if (h.sz_cpr > h.sz_unc
        ||  h.sz_unc > xo->size ) {
            err_exit(5);
        }
        // Now we have:
        //   assert(h.sz_cpr <= h.sz_unc);
        //   assert(h.sz_unc > 0 && h.sz_unc <= blocksize);
        //   assert(h.sz_cpr > 0 && h.sz_cpr <= blocksize);

        if (h.sz_cpr < h.sz_unc) { // Decompress block
            nrv_uint out_len = h.sz_unc;  // EOF for lzma
            int const j = (*f_decompress)(xi->buf, h.sz_cpr,
                xo->buf, &out_len, h.b_method);
            if (j != 0 || out_len != (nrv_uint)h.sz_unc)
                err_exit(7);
            if (h.b_ftid!=0 && f_unf) {  // have filter
                (*f_unf)(xo->buf, out_len, h.b_cto8, h.b_ftid);
            }
            xi->buf  += h.sz_cpr;
            xi->size -= h.sz_cpr;
        }
        else { // copy literal block
            xread(xi, xo->buf, h.sz_cpr);
        }
        xo->buf  += h.sz_unc;
        xo->size -= h.sz_unc;
    }
}

static void
upx_bzero(unsigned char *p, size_t len)
{
    if (len) do {
        *p++= 0;
    } while (--len);
}
#define bzero upx_bzero


// The PF_* and PROT_* bits are {1,2,4}; the conversion table fits in 32 bits.
#define REP8(x) \
    ((x)|((x)<<4)|((x)<<8)|((x)<<12)|((x)<<16)|((x)<<20)|((x)<<24)|((x)<<28))
#define EXP8(y) \
    ((1&(y)) ? 0xf0f0f0f0 : (2&(y)) ? 0xff00ff00 : (4&(y)) ? 0xffff0000 : 0)
#define PF_TO_PROT(pf) \
    ((PROT_READ|PROT_WRITE|PROT_EXEC) & ( \
        ( (REP8(PROT_EXEC ) & EXP8(PF_X)) \
         |(REP8(PROT_READ ) & EXP8(PF_R)) \
         |(REP8(PROT_WRITE) & EXP8(PF_W)) \
        ) >> ((pf & (PF_R|PF_W|PF_X))<<2) ))

typedef struct {
    unsigned magic;
    unsigned nfat_arch;
} Fat_header;
typedef struct {
    unsigned cputype;
    unsigned cpusubtype;
    unsigned offset;
    unsigned size;
    unsigned align;  /* shift count (log base 2) */
} Fat_arch;
    enum e8 {
        FAT_MAGIC = 0xcafebabe
    };
    enum e9 {
        CPU_TYPE_I386      =          7,
        CPU_TYPE_ARM       =         12,
        CPU_TYPE_POWERPC   = 0x00000012,
        CPU_TYPE_POWERPC64 = 0x01000012
    };

typedef struct {
    unsigned magic;
    unsigned cputype;
    unsigned cpysubtype;
    unsigned filetype;
    unsigned ncmds;
    unsigned sizeofcmds;
    unsigned flags;
} Mach_header;
        enum e0 {
            MH_MAGIC = 0xfeedface
        };
        enum e2 {
            MH_EXECUTE = 2
        };
        enum e3 {
            MH_NOUNDEFS = 1
        };

typedef struct {
    unsigned cmd;
    unsigned cmdsize;
} Mach_load_command;
        enum e4 {
            LC_SEGMENT       = 0x1,
            LC_SEGMENT_64    = 0x19,
            LC_THREAD        = 0x4,
            LC_UNIXTHREAD    = 0x5,
            LC_LOAD_DYLINKER = 0xe
        };

typedef struct {
    unsigned cmd;
    unsigned cmdsize;
    char segname[16];
    unsigned long vmaddr;
    unsigned long vmsize;
    unsigned long fileoff;
    unsigned long filesize;
    unsigned maxprot;
    unsigned initprot;
    unsigned nsects;
    unsigned flags;
} Mach_segment_command;
        enum e5 {
            VM_PROT_READ = 1,
            VM_PROT_WRITE = 2,
            VM_PROT_EXECUTE = 4
        };

typedef struct {
    unsigned long x0,  x1,  x2,  x3;
    unsigned long x4,  x5,  x6,  x7;
    unsigned long x8,  x9,  x10, x11;
    unsigned long x12, x13, x14, x15;
    unsigned long x16, x17, x18, x19;
    unsigned long x20, x21, x22, x23;
    unsigned long x24, x25, x26, x27;
    unsigned long x28, fp,  lr,  sp;
    unsigned long pc;
    unsigned int  cpsr;
} Mach_ARM_thread_state;

typedef struct {
    unsigned cmd;            /* LC_THREAD or  LC_UNIXTHREAD */
    unsigned cmdsize;        /* total size of this command */
    unsigned flavor;
    unsigned count;          /* sizeof(following_thread_state)/4 */
    Mach_ARM_thread_state state;
} Mach_thread_command;
        enum e6 {
            ARM_THREAD_STATE = 1
        };
        enum e7 {
            ARM_THREAD_STATE_COUNT = sizeof(Mach_ARM_thread_state)/4
        };

typedef union {
    unsigned long offset;  /* from start of load command to string */
    char *ptr;
} Mach_lc_str;

#define MAP_FIXED     0x10
#define MAP_PRIVATE   0x02
#define MAP_ANON    0x1000
//#define MAP_ANON  0x20  // x86 DEBUG ONLY
#define PROT_READ      1
#define PROT_WRITE     2
#define PROT_EXEC      4

#define MAP_ANON_FD    -1

extern void *mmap(void *, size_t, unsigned, unsigned, int, off_t);
ssize_t pread(int, void *, size_t, off_t);
extern void bswap(void *, unsigned);

static Mach_ARM_thread_state const *
do_xmap(
    Mach_header const *const mhdr,
    off_t const fat_offset,
    Extent *const xi,
    int const fdi,
    Mach_header **mhdrpp,
    f_expand *const f_decompress,
    f_unfilter *const f_unf
)
{
    Mach_segment_command const *sc = (Mach_segment_command const *)(1+ mhdr);
    Mach_ARM_thread_state const *entry = 0;
    unsigned j;

    for ( j=0; j < mhdr->ncmds; ++j,
        (sc = (Mach_segment_command const *)(sc->cmdsize + (void const *)sc))
    ) if (LC_SEGMENT_64==sc->cmd && sc->vmsize!=0) {
        Extent xo;
        size_t mlen = xo.size = sc->filesize;
        unsigned char  *addr = xo.buf  =        (unsigned char *)sc->vmaddr;
        unsigned char *haddr =           sc->vmsize +                  addr;
        size_t frag = (size_t)addr &~ PAGE_MASK;
        addr -= frag;
        mlen += frag;

        if (0!=mlen && addr != mmap(addr, mlen, VM_PROT_READ | VM_PROT_WRITE,
                MAP_FIXED | MAP_PRIVATE |
                    ((xi || 0==sc->filesize) ? MAP_ANON : 0),
                ((0==sc->filesize) ? MAP_ANON_FD : fdi), sc->fileoff + fat_offset) ) {
            err_exit(8);
        }
        if (xi && 0!=sc->filesize) {
            if (0==sc->fileoff /*&& 0!=mhdrpp*/) {
                *mhdrpp = (Mach_header *)(void *)addr;
            }
            unpackExtent(xi, &xo, f_decompress, f_unf);
        }
        /*bzero(addr, frag);*/  // fragment at lo end
        frag = (-mlen) &~ PAGE_MASK;  // distance to next page boundary
        bzero(mlen+addr, frag);  // fragment at hi end
        if (0!=mlen && 0!=mprotect(addr, mlen, sc->initprot)) {
            err_exit(10);
ERR_LAB
        }
        addr += mlen + frag;  /* page boundary on hi end */
        if (
#if defined(SIMULATE_ON_DEBIAN_EABI4)  /*{*/
            0!=addr &&
#endif  /*}*/
                        addr < haddr) { // need pages for .bss
            if (addr != mmap(addr, haddr - addr, sc->initprot,
                    MAP_FIXED | MAP_PRIVATE | MAP_ANON, MAP_ANON_FD, 0 ) ) {
                err_exit(9);
            }
        }
    }
    else if (LC_UNIXTHREAD==sc->cmd || LC_THREAD==sc->cmd) {
        Mach_thread_command const *const thrc = (Mach_thread_command const *)sc;
        if (ARM_THREAD_STATE      ==thrc->flavor
        &&  ARM_THREAD_STATE_COUNT==thrc->count ) {
            entry = &thrc->state;
        }
    }
    return entry;
}


extern void spin(void *, ...);

/*************************************************************************
// upx_main - called by our entry code
//
**************************************************************************/

Mach_ARM_thread_state const *
upx_main(
    struct l_info const *const li,
    size_t volatile sz_compressed,  // total length
    Mach_header *const mhdr,  // temp char[sz_mhdr] for decompressing
    size_t const sz_mhdr,
    f_expand *const f_decompress,
    f_unfilter *const f_unf,
    Mach_header **const mhdrpp  // Out: *mhdrpp= &real Mach_header
)
{
    Mach_ARM_thread_state const *entry;
    off_t fat_offset = 0;
    Extent xi, xo, xi0;
    xi.buf  = CONST_CAST(unsigned char *, 1+ (struct p_info const *)(1+ li));  // &b_info
    xi.size = sz_compressed - (sizeof(struct l_info) + sizeof(struct p_info));
    xo.buf  = (unsigned char *)mhdr;
    xo.size = ((struct b_info const *)(void const *)xi.buf)->sz_unc;
    xi0 = xi;

    // Uncompress Macho headers
    unpackExtent(&xi, &xo, f_decompress, 0);  // never filtered?

    entry = do_xmap(mhdr, fat_offset, &xi0, MAP_ANON_FD, mhdrpp, f_decompress, f_unf);

  { // Map dyld dynamic loader
    Mach_load_command const *lc = (Mach_load_command const *)(1+ mhdr);
    unsigned j;

    for (j=0; j < mhdr->ncmds; ++j,
        (lc = (Mach_load_command const *)(lc->cmdsize + (void const *)lc))
    ) if (LC_LOAD_DYLINKER==lc->cmd) {
        char const *const dyld_name = ((Mach_lc_str const *)(1+ lc))->offset +
            (char const *)lc;
        int const fdi = open(dyld_name, O_RDONLY, 0);
        if (0 > fdi) {
            err_exit(18);
        }
fat:
        if ((ssize_t)sz_mhdr!=pread(fdi, (void *)mhdr, sz_mhdr, fat_offset)) {
ERR_LAB
            err_exit(19);
        }
        switch (mhdr->magic) {
        case MH_MAGIC: break;
        case FAT_MAGIC: {
            // stupid Apple: waste code and a page fault on EVERY execve
            Fat_header *const fh = (Fat_header *)mhdr;
            Fat_arch *fa = (Fat_arch *)(1+ fh);
            bswap(fh, sizeof(*fh) + (fh->nfat_arch>>24)*sizeof(*fa));
            for (j= 0; j < fh->nfat_arch; ++j, ++fa) {
                if (CPU_TYPE_ARM==fa->cputype) {
                    fat_offset= fa->offset;
                    goto fat;
                }
            }
        } break;
        } // switch
        entry = do_xmap(mhdr, fat_offset, 0, fdi, 0, 0, 0);
        close(fdi);
        break;
    }
  }

    return entry;
}


/*
vi:ts=4:et:nowrap
*/

