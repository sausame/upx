;  l_lx_exec86.asm -- Linux program entry point & decompressor (kernel exec)
;
;  This file is part of the UPX executable compressor.
;
;  Copyright (C) 1996-2001 Markus Franz Xaver Johannes Oberhumer
;  Copyright (C) 1996-2001 Laszlo Molnar
;  Copyright (C) 2000-2001 John F. Reiser
;  All Rights Reserved.
;
;  UPX and the UCL library are free software; you can redistribute them
;  and/or modify them under the terms of the GNU General Public License as
;  published by the Free Software Foundation; either version 2 of
;  the License, or (at your option) any later version.
;
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU General Public License for more details.
;
;  You should have received a copy of the GNU General Public License
;  along with this program; see the file COPYING.
;  If not, write to the Free Software Foundation, Inc.,
;  59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
;
;  Markus F.X.J. Oberhumer   Laszlo Molnar           John F. Reiser
;  markus@oberhumer.com      ml1050@cdata.tvnet.hu   jreiser@BitWagon.com
;


                BITS    32
                SECTION .text

%define         jmps    jmp short
%define         jmpn    jmp near

; /*************************************************************************
; // program entry point
; // see glibc/sysdeps/i386/elf/start.S
; **************************************************************************/

GLOBAL _start
;__LEXEC000__
_start:
;;;;    int3
;; How to debug this code:  Uncomment the 'int3' breakpoint instruction above.
;; Build the stubs and upx.  Compress a testcase, such as a copy of /bin/date.
;; Invoke gdb, and give a 'run' command.  Define a single-step macro such as
;;      define g
;;      stepi
;;      x/i $pc
;;      end
;; and a step-over macro such as
;;      define h
;;      x/2i $pc
;;      tbreak *$_
;;      continue
;;      x/i $pc
;;      end
;; Step through the code; remember that <Enter> repeats the previous command.
;;
%if 0
                ; personality(PER_LINUX)
                mov     eax, 136            ; syscall_personality
                xor     ebx, ebx            ; PER_LINUX
                int     0x80
%endif

        call main  ; push address of decompress subroutine
decompress:

; /*************************************************************************
; // C callable decompressor
; **************************************************************************/

%define         INP     dword [esp+8*4+8]
%define         INS     dword [esp+8*4+12]
%define         OUTP    dword [esp+8*4+16]
%define         OUTS    dword [esp+8*4+20]

;__LEXEC009__
                mov     eax, 'NMRU'  ; free slot in following 'pusha'
;__LEXEC010__
                pusha
                push    byte '?'  ; cto8 (sign extension does not matter)
                ; cld

                mov     esi, INP
                mov     edi, OUTP

                or      ebp, byte -1
;;;             align   8

%include      "n2b_d32.ash"
%include      "n2d_d32.ash"
%include      "macros.ash"
                cjt32 0

;__LEXEC015__
                ; eax is 0 from decompressor code
                ;xor     eax, eax               ; return code

; check compressed size
                mov     edx, INP
                add     edx, INS
                cmp     edx, esi
                jz      .ok
                dec     eax
.ok:
                xchg [8*4 + esp], eax  ; store success/failure, fetch NMRU

; write back the uncompressed size, and prepare for unfilter
                mov edx, OUTS
                mov ecx, edi
                mov edi, OUTP
                sub ecx, edi  ; ecx= uncompressed size
                mov [edx], ecx

                pop edx  ; cto8

;__LEXEC110__  Jcc and/or possible n_mru
                push edi  ; addvalue
                push byte 0x0f
                pop ebx
                mov bh, dl  ; ebx= 0,,cto8,0x0F

;__LEXEC100__  0!=n_mru
                xchg eax, ebx  ; eax= ct08_0f; ebx= n_mru {or n_mru1}

;;LEXEC016 bug in APP: jmp and target must be in same .asx
;;              jmpn lxunf0  ; logically belongs here

                ctojr32
                ckt32   dl
;__LEXEC017__
                popa
                ret

;__LEXEC020__

%define PAGE_MASK (~0<<12)
%define PAGE_SIZE ( 1<<12)

; Decompress the rest of this loader, and jump to it
unfold:
        pop esi  ; &{ sz_uncompressed, sz_compressed, compressed_data...}
        mov ecx, PAGE_MASK
          push esi  ; &dst
        mov ebx, ebp  ; &decompress
        and ebx, ecx  ; &my_elfhdr
        neg ecx  ; ecx= PAGE_SIZE

        cld
        lodsd  ; sz_uncompressed
        lodsd  ; sz_compressed

;; Compressed code now begins at fold_begin.
;; We want decompressed code to begin at fold_begin, too.
;; Move the compressed code to the high end of the page.
;; Assume non-overlapping so that forward movsb is OK.

        lea edi, [ecx + ebx]  ; high end of page
          push eax  ; srclen (of both movsb and decompress)
        sub edi, eax  ; dst of movsb
          push edi  ; &src for decompression (after movsb)
        xchg ecx, eax  ; ecx= len of movsb
        rep movsb
          call ebp  ; decompress(&src, srclen, &dst, &dstlen)
        pop eax  ; discard &src
        pop eax  ; discard srclen
        pop eax  ; &dst == fold_begin

;; icache lookahead of compressed code after "call unfold" is still there.
;; Synchronize with dcache of decompressed code.
        pushf
        push cs
        push eax
        iret  ; back to fold_begin!

main:
        pop ebp  ; &decompress
          push eax  ; sz_uncompressed  (junk, actually)
          push esp  ; &sz_uncompressed
        call unfold

eof:
;       __XTHEENDX__
        section .data
        dd      -1
        dw      eof

; vi:ts=8:et:nowrap
