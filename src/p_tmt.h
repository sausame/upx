/* p_tmt.h --

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2000 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2000 Laszlo Molnar
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

   Markus F.X.J. Oberhumer                   Laszlo Molnar
   markus.oberhumer@jk.uni-linz.ac.at        ml1050@cdata.tvnet.hu
 */


#ifndef __UPX_P_TMT_H
#define __UPX_P_TMT_H


/*************************************************************************
// tmt/adam
**************************************************************************/

class PackTmt : public Packer
{
    typedef Packer super;
public:
    PackTmt(InputFile *f) : super(f) { assert(sizeof(tmt_header_t) == 44); }
    virtual int getVersion() const { return 11; }
    virtual int getFormat() const { return UPX_F_TMT_ADAM; }
    virtual const char *getName() const { return "tmt/adam"; }
    virtual int getCompressionMethod() const;
    virtual const int *getFilters() const;

    virtual void pack(OutputFile *fo);
    virtual void unpack(OutputFile *fo);

    virtual bool canPack();
    virtual int canUnpack();

protected:
    bool readFileHeader();

    unsigned adam_offset;

    struct tmt_header_t
    {
        char _[16];     // signature,linkerversion,minversion,exesize,imagestart
        LE32 imagesize;
        char __[4];     // initial memory
        LE32 entry;
        char ___[12];   // esp,numfixups,flags
        LE32 relocsize;
    } ih,oh;
};


#endif /* already included */


/*
vi:ts=4:et
*/

