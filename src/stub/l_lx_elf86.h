/* l_lx_elf86.h -- created from l_lx_elf86.bin, 5030 (0x13a6) bytes

   This file is part of the UPX executable compressor.

   Copyright (C) 1996-2005 Markus Franz Xaver Johannes Oberhumer
   Copyright (C) 1996-2005 Laszlo Molnar
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
   <mfx@users.sourceforge.net>          <ml1050@users.sourceforge.net>
 */


#define LINUX_I386ELF_LOADER_ADLER32 0x24b5b666
#define LINUX_I386ELF_LOADER_CRC32   0x3db5af12

unsigned char linux_i386elf_loader[5030] = {
232,  0,  0,  0,  0, 96,106, 63,139,116, 36, 40,139,124, 36, 48,   /* 0x   0 */
131,205,255,235,  0,164,235,  0,138,  6, 70,136,  7, 71,  1,219,   /* 0x  10 */
117,  7,139, 30,131,238,252, 17,219,114,  0, 49,192, 64,138,  7,   /* 0x  20 */
114,  0,184,  1,  0,  0,  0,  1,219,117,  7,139, 30,131,238,252,   /* 0x  30 */
 17,219, 17,192,  1,219,117,  7,139, 30,131,238,252, 17,219,115,   /* 0x  40 */
  0,  1,219,115,  0,117,  9,139, 30,131,238,252, 17,219,115,  0,   /* 0x  50 */
 49,201,131,232,  3,114, 13,193,224,  8,138,  6, 70,131,240,255,   /* 0x  60 */
116,  0,137,197,  1,219,117,  7,139, 30,131,238,252, 17,219, 17,   /* 0x  70 */
201,  1,219,117,  7,139, 30,131,238,252, 17,219, 17,201,117,  0,   /* 0x  80 */
 65,  1,219,117,  7,139, 30,131,238,252, 17,219, 17,201,  1,219,   /* 0x  90 */
117,  7,139, 30,131,238,252, 17,219,115,  0,  1,219,115,  0,117,   /* 0x  a0 */
  9,139, 30,131,238,252, 17,219,115,  0, 65, 65,131,193,  2,129,   /* 0x  b0 */
253,  0,243,255,255,131,209,  1, 86,141, 52, 47,243,164, 94,233,   /* 0x  c0 */
  0,  0,  0,  0,141, 20, 47,131,253,252,138,  4, 15,118,  0,138,   /* 0x  d0 */
  2, 66,136,  7, 71, 73,117,247,233,  0,  0,  0,  0,139,  2,131,   /* 0x  e0 */
194,  4,137,  7,131,199,  4,131,233,  4,119,241,  1,207,233,  0,   /* 0x  f0 */
  0,  0,  0,235,  0,164,235,  0,138,  6, 70,136,  7, 71,  1,219,   /* 0x 100 */
117,  7,139, 30,131,238,252, 17,219,114,  0, 49,192, 64,138,  7,   /* 0x 110 */
114,  0,184,  1,  0,  0,  0,  1,219,117,  7,139, 30,131,238,252,   /* 0x 120 */
 17,219, 17,192,  1,219,117,  7,139, 30,131,238,252, 17,219,114,   /* 0x 130 */
  0,  1,219,115, 11,117,  0,139, 30,131,238,252, 17,219,114,  0,   /* 0x 140 */
 72,  1,219,117,  7,139, 30,131,238,252, 17,219, 17,192,235,  0,   /* 0x 150 */
 49,201,131,232,  3,114, 17,193,224,  8,138,  6, 70,131,240,255,   /* 0x 160 */
116,  0,209,248,137,197,235, 11,  1,219,117,  7,139, 30,131,238,   /* 0x 170 */
252, 17,219, 17,201,  1,219,117,  7,139, 30,131,238,252, 17,219,   /* 0x 180 */
 17,201,117,  0, 65,  1,219,117,  7,139, 30,131,238,252, 17,219,   /* 0x 190 */
 17,201,  1,219,117,  7,139, 30,131,238,252, 17,219,115,  0,  1,   /* 0x 1a0 */
219,115,  0,117,  9,139, 30,131,238,252, 17,219,115,  0, 65, 65,   /* 0x 1b0 */
131,193,  2,129,253,  0,251,255,255,131,209,  1, 86,141, 52, 47,   /* 0x 1c0 */
243,164, 94,233,  0,  0,  0,  0,141, 20, 47,131,253,252,138,  4,   /* 0x 1d0 */
 15,118,  0,138,  2, 66,136,  7, 71, 73,117,247,233,  0,  0,  0,   /* 0x 1e0 */
  0,139,  2,131,194,  4,137,  7,131,199,  4,131,233,  4,119,241,   /* 0x 1f0 */
  1,207,233,  0,  0,  0,  0,235,  0,164,235,  0,138,  6, 70,136,   /* 0x 200 */
  7, 71,  1,219,117,  7,139, 30,131,238,252, 17,219,114,  0, 49,   /* 0x 210 */
192, 64,138,  7,114,  0,184,  1,  0,  0,  0,  1,219,117,  7,139,   /* 0x 220 */
 30,131,238,252, 17,219, 17,192,  1,219,117,  7,139, 30,131,238,   /* 0x 230 */
252, 17,219,114,  0,  1,219,115, 11,117,  0,139, 30,131,238,252,   /* 0x 240 */
 17,219,114,  0, 72,  1,219,117,  7,139, 30,131,238,252, 17,219,   /* 0x 250 */
 17,192,235,  0,  1,219,117,  7,139, 30,131,238,252, 17,219, 17,   /* 0x 260 */
201,235,  0, 49,201,131,232,  3,114, 17,193,224,  8,138,  6, 70,   /* 0x 270 */
131,240,255,116,  0,209,248,137,197,235, 11,  1,219,117,  7,139,   /* 0x 280 */
 30,131,238,252, 17,219,114,204, 65,  1,219,117,  7,139, 30,131,   /* 0x 290 */
238,252, 17,219,114,190,  1,219,117,  7,139, 30,131,238,252, 17,   /* 0x 2a0 */
219, 17,201,  1,219,117,  7,139, 30,131,238,252, 17,219,115,  0,   /* 0x 2b0 */
  1,219,115,  0,117,  9,139, 30,131,238,252, 17,219,115,  0, 65,   /* 0x 2c0 */
 65,131,193,  2,129,253,  0,251,255,255,131,209,  2, 86,141, 52,   /* 0x 2d0 */
 47,243,164, 94,233,  0,  0,  0,  0,141, 20, 47,131,253,252,138,   /* 0x 2e0 */
  4, 15,118,  0,138,  2, 66,136,  7, 71, 73,117,247,233,  0,  0,   /* 0x 2f0 */
  0,  0,139,  2,131,194,  4,137,  7,131,199,  4,131,233,  4,119,   /* 0x 300 */
241,  1,207,233,  0,  0,  0,  0,185, 84, 69, 88, 76,138,  7, 71,   /* 0x 310 */
 44,232, 60,  1,119,247,128, 63, 63,117,  0,139,  7,138, 95,  4,   /* 0x 320 */
102,193,232,  8,134,196,193,192, 16,134,196, 41,248,128,235,232,   /* 0x 330 */
137,  7,131,199,  5,136,216,226,  0,185, 84, 69, 88, 76,176,232,   /* 0x 340 */
176,233,242,174,117,  0,128, 63, 63,117,  0,139,  7,102,193,232,   /* 0x 350 */
  8,134,196,193,192, 16,134,196, 41,248,171,235,  0,139, 84, 36,   /* 0x 360 */
 40,  3, 84, 36, 44, 57,214,116,  1, 72, 43,124, 36, 48,139, 84,   /* 0x 370 */
 36, 52,137, 58, 90,137, 68, 36, 28, 97,195,235,  0, 90, 88, 89,   /* 0x 380 */
151, 96, 49,219,187, 78, 77, 82, 85,106, 15, 88,138,100, 36, 32,   /* 0x 390 */
106, 15, 91,138,124, 36, 32,138, 84, 36, 32,233,  0,  0,  0,  0,   /* 0x 3a0 */
 15,183, 47, 43,110, 12, 41,221,117,  0,131,237,  1,115,  0,136,   /* 0x 3b0 */
 95,255, 73,136,  7, 71,139,  7,156,102,193,232,  8,193,192, 16,   /* 0x 3c0 */
134,196,157,115,  0,176,  0, 15,200,115,  0,209,232,115,  0,254,   /* 0x 3d0 */
203, 75, 35, 30,125,  2,  3, 30,137,  4,156,235,  0,141, 20, 24,   /* 0x 3e0 */
 15,182,210, 35, 22, 59, 22,114,  2, 43, 22,139,  4,148,254,203,   /* 0x 3f0 */
 75, 35, 30,125,  2,  3, 30,139, 44,156,133,237,117,  0, 80,139,   /* 0x 400 */
 70,  4,254,200, 72, 35,  6,125,  2,  3,  6, 49,237,137, 70,  4,   /* 0x 410 */
135,108,132,  4, 88,137, 44,148,137,  4,156, 41,248,131,233,  4,   /* 0x 420 */
  3, 70, 16,  1,240,137,  7,131,199,  4,235,  0,235,  0, 80,176,   /* 0x 430 */
233,176,232, 80,106,  0, 83,137,230, 94,137,218,178,233,178,232,   /* 0x 440 */
 67,106,  0,254,203, 75,117,  0, 15,183,  7,131,199,  1, 60,128,   /* 0x 450 */
114,  4, 60,143,118,  0, 41,208, 43, 70,  8,131,232,  2,116,  0,   /* 0x 460 */
131,232,  1,114,  0,115,  0,122,  0,123,  0,248,235,  0,131,233,   /* 0x 470 */
  1,127,  0,137,231,185,  4,  1,  0,  0,139, 14,131,193,  5,139,   /* 0x 480 */
 14,131,193,  4, 49,192,243,171,137,252, 86, 97,151, 81, 80, 82,   /* 0x 490 */
195,137,254,235,  0,138,  7,131,199,  1, 60,128,114, 10, 60,143,   /* 0x 4a0 */
119,  6,128,127,254, 15,116,  0, 44,232, 60,  1,119,  0, 56, 23,   /* 0x 4b0 */
117,  0,139,  7,102,193,232,  8,193,192, 16,134,196, 41,248,  1,   /* 0x 4c0 */
240,137,  7,131,199,  4,131,233,  4,138,  7,131,199,  1,226,  0,   /* 0x 4d0 */
131,233,  1,127,  0, 97,195, 94,252,173, 80, 84,184,  0,  0,  0,   /* 0x 4e0 */
  1, 80, 49,201, 81, 81,181, 16,106, 50,106,  7, 81, 80,137,227,   /* 0x 4f0 */
106, 90, 88,205,128,147,183, 16,131,196, 24,173, 80,173, 86,255,   /* 0x 500 */
213, 88, 88,195, 93,232,205,255,255,255,  0,  0, 76, 69, 88, 69,   /* 0x 510 */
 67, 48, 48, 48,  0,  0,  0,  0,  0,  0,  0,  0,  5,  0,  0,  0,   /* 0x 520 */
 76, 69, 88, 69, 67, 48, 50, 48, 45,  0,  0,  0, 76, 69, 88, 69,   /* 0x 530 */
 67, 48, 48, 57,  5,  0,  0,  0, 76, 69, 88, 69, 67, 48, 49, 48,   /* 0x 540 */
  5,  0,  0,  0, 78, 50, 66, 83, 77, 65, 49, 48, 19,  0,  0,  0,   /* 0x 550 */
  0,  0,  0,  0, 21,  0,  0,  0, 78, 50, 66, 68, 69, 67, 49, 48,   /* 0x 560 */
  4,  0,  0,  0, 78, 50, 66, 70, 65, 83, 49, 48, 22,  0,  0,  0,   /* 0x 570 */
  0,  0,  0,  0, 24,  0,  0,  0, 78, 50, 66, 68, 69, 67, 49, 48,   /* 0x 580 */
  4,  0,  0,  0, 78, 50, 66, 70, 65, 83, 49, 49, 24,  0,  0,  0,   /* 0x 590 */
 78, 50, 66, 68, 69, 67, 49, 48, 30,  0,  0,  0, 78, 50, 66, 83,   /* 0x 5a0 */
 77, 65, 50, 48, 41,  0,  0,  0,  0,  0,  0,  0, 43,  0,  0,  0,   /* 0x 5b0 */
 78, 50, 66, 83, 77, 65, 49, 48,  2,  0,  0,  0, 78, 50, 66, 70,   /* 0x 5c0 */
 65, 83, 50, 48, 46,  0,  0,  0,  0,  0,  0,  0, 50,  0,  0,  0,   /* 0x 5d0 */
 78, 50, 66, 70, 65, 83, 49, 49,  0,  0,  0,  0, 78, 50, 66, 68,   /* 0x 5e0 */
 69, 67, 50, 48, 55,  0,  0,  0, 78, 50, 66, 83, 77, 65, 51, 48,   /* 0x 5f0 */
 68,  0,  0,  0,  0,  0,  0,  0, 81,  0,  0,  0, 78, 50, 66, 68,   /* 0x 600 */
 69, 67, 50, 48,  0,  0,  0,  0, 78, 50, 66, 70, 65, 83, 51, 48,   /* 0x 610 */
 81,  0,  0,  0,  0,  0,  0,  0, 85,  0,  0,  0, 78, 50, 66, 68,   /* 0x 620 */
 69, 67, 50, 48,  0,  0,  0,  0,  0,  0,  0,  0, 96,  0,  0,  0,   /* 0x 630 */
 78, 50, 66, 68, 69, 67, 50, 48,  0,  0,  0,  0, 78, 50, 66, 68,   /* 0x 640 */
 69, 67, 51, 48, 96,  0,  0,  0,  0,  0,  0,  0,114,  0,  0,  0,   /* 0x 650 */
 78, 50, 66, 68, 69, 67, 54, 48,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 660 */
144,  0,  0,  0, 78, 50, 66, 68, 69, 67, 53, 48,  0,  0,  0,  0,   /* 0x 670 */
 78, 50, 66, 83, 77, 65, 52, 48,158,  0,  0,  0,  0,  0,  0,  0,   /* 0x 680 */
171,  0,  0,  0, 78, 50, 66, 68, 69, 67, 51, 48, 49,  0,  0,  0,   /* 0x 690 */
 78, 50, 66, 70, 65, 83, 52, 48,171,  0,  0,  0,  0,  0,  0,  0,   /* 0x 6a0 */
175,  0,  0,  0, 78, 50, 66, 68, 69, 67, 51, 48, 49,  0,  0,  0,   /* 0x 6b0 */
  0,  0,  0,  0,186,  0,  0,  0, 78, 50, 66, 68, 69, 67, 51, 48,   /* 0x 6c0 */
 49,  0,  0,  0, 78, 50, 66, 68, 85, 77, 77, 49,186,  0,  0,  0,   /* 0x 6d0 */
 78, 50, 66, 83, 77, 65, 53, 48,186,  0,  0,  0, 78, 50, 66, 70,   /* 0x 6e0 */
 65, 83, 53, 48,188,  0,  0,  0, 78, 50, 66, 68, 69, 67, 53, 48,   /* 0x 6f0 */
191,  0,  0,  0, 78, 50, 66, 83, 77, 65, 54, 48,200,  0,  0,  0,   /* 0x 700 */
  0,  0,  0,  0,212,  0,  0,  0, 78, 50, 66, 68, 69, 67, 49, 48,   /* 0x 710 */
  0,  0,  0,  0, 78, 50, 66, 70, 65, 83, 54, 48,212,  0,  0,  0,   /* 0x 720 */
  0,  0,  0,  0,223,  0,  0,  0, 78, 50, 66, 70, 65, 83, 54, 49,   /* 0x 730 */
  0,  0,  0,  0,  0,  0,  0,  0,237,  0,  0,  0, 78, 50, 66, 68,   /* 0x 740 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 66, 70, 65, 83, 54, 49,   /* 0x 750 */
237,  0,  0,  0,  0,  0,  0,  0,  3,  1,  0,  0, 78, 50, 66, 68,   /* 0x 760 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 66, 68, 69, 67, 54, 48,   /* 0x 770 */
  3,  1,  0,  0, 78, 82, 86, 50, 66, 69, 78, 68,  3,  1,  0,  0,   /* 0x 780 */
 78, 50, 68, 83, 77, 65, 49, 48,  3,  1,  0,  0,  0,  0,  0,  0,   /* 0x 790 */
  5,  1,  0,  0, 78, 50, 68, 68, 69, 67, 49, 48,  4,  0,  0,  0,   /* 0x 7a0 */
 78, 50, 68, 70, 65, 83, 49, 48,  6,  1,  0,  0,  0,  0,  0,  0,   /* 0x 7b0 */
  8,  1,  0,  0, 78, 50, 68, 68, 69, 67, 49, 48,  4,  0,  0,  0,   /* 0x 7c0 */
 78, 50, 68, 70, 65, 83, 49, 49,  8,  1,  0,  0, 78, 50, 68, 68,   /* 0x 7d0 */
 69, 67, 49, 48, 14,  1,  0,  0, 78, 50, 68, 83, 77, 65, 50, 48,   /* 0x 7e0 */
 25,  1,  0,  0,  0,  0,  0,  0, 27,  1,  0,  0, 78, 50, 68, 83,   /* 0x 7f0 */
 77, 65, 49, 48,  2,  0,  0,  0, 78, 50, 68, 70, 65, 83, 50, 48,   /* 0x 800 */
 30,  1,  0,  0,  0,  0,  0,  0, 34,  1,  0,  0, 78, 50, 68, 70,   /* 0x 810 */
 65, 83, 49, 49,  0,  0,  0,  0, 78, 50, 68, 68, 69, 67, 50, 48,   /* 0x 820 */
 39,  1,  0,  0, 78, 50, 68, 83, 77, 65, 51, 48, 52,  1,  0,  0,   /* 0x 830 */
  0,  0,  0,  0, 65,  1,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48,   /* 0x 840 */
 16,  0,  0,  0, 78, 50, 68, 70, 65, 83, 51, 48, 65,  1,  0,  0,   /* 0x 850 */
  0,  0,  0,  0, 71,  1,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48,   /* 0x 860 */
 16,  0,  0,  0,  0,  0,  0,  0, 80,  1,  0,  0, 78, 50, 68, 68,   /* 0x 870 */
 69, 67, 51, 48, 16,  0,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48,   /* 0x 880 */
 80,  1,  0,  0,  0,  0,  0,  0, 96,  1,  0,  0, 78, 50, 68, 68,   /* 0x 890 */
 69, 67, 50, 48,  0,  0,  0,  0,  0,  0,  0,  0,114,  1,  0,  0,   /* 0x 8a0 */
 78, 50, 68, 68, 69, 67, 54, 48,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x 8b0 */
148,  1,  0,  0, 78, 50, 68, 68, 69, 67, 53, 48,  0,  0,  0,  0,   /* 0x 8c0 */
 78, 50, 68, 83, 77, 65, 52, 48,162,  1,  0,  0,  0,  0,  0,  0,   /* 0x 8d0 */
175,  1,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48, 69,  0,  0,  0,   /* 0x 8e0 */
 78, 50, 68, 70, 65, 83, 52, 48,175,  1,  0,  0,  0,  0,  0,  0,   /* 0x 8f0 */
179,  1,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48, 69,  0,  0,  0,   /* 0x 900 */
  0,  0,  0,  0,190,  1,  0,  0, 78, 50, 68, 68, 69, 67, 51, 48,   /* 0x 910 */
 69,  0,  0,  0, 78, 50, 68, 68, 85, 77, 77, 49,190,  1,  0,  0,   /* 0x 920 */
 78, 50, 68, 83, 77, 65, 53, 48,190,  1,  0,  0, 78, 50, 68, 70,   /* 0x 930 */
 65, 83, 53, 48,192,  1,  0,  0, 78, 50, 68, 68, 69, 67, 53, 48,   /* 0x 940 */
195,  1,  0,  0, 78, 50, 68, 83, 77, 65, 54, 48,204,  1,  0,  0,   /* 0x 950 */
  0,  0,  0,  0,216,  1,  0,  0, 78, 50, 68, 68, 69, 67, 49, 48,   /* 0x 960 */
  0,  0,  0,  0, 78, 50, 68, 70, 65, 83, 54, 48,216,  1,  0,  0,   /* 0x 970 */
  0,  0,  0,  0,227,  1,  0,  0, 78, 50, 68, 70, 65, 83, 54, 49,   /* 0x 980 */
  0,  0,  0,  0,  0,  0,  0,  0,241,  1,  0,  0, 78, 50, 68, 68,   /* 0x 990 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 68, 70, 65, 83, 54, 49,   /* 0x 9a0 */
241,  1,  0,  0,  0,  0,  0,  0,  7,  2,  0,  0, 78, 50, 68, 68,   /* 0x 9b0 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 68, 68, 69, 67, 54, 48,   /* 0x 9c0 */
  7,  2,  0,  0, 78, 82, 86, 50, 68, 69, 78, 68,  7,  2,  0,  0,   /* 0x 9d0 */
 78, 50, 69, 83, 77, 65, 49, 48,  7,  2,  0,  0,  0,  0,  0,  0,   /* 0x 9e0 */
  9,  2,  0,  0, 78, 50, 69, 68, 69, 67, 49, 48,  4,  0,  0,  0,   /* 0x 9f0 */
 78, 50, 69, 70, 65, 83, 49, 48, 10,  2,  0,  0,  0,  0,  0,  0,   /* 0x a00 */
 12,  2,  0,  0, 78, 50, 69, 68, 69, 67, 49, 48,  4,  0,  0,  0,   /* 0x a10 */
 78, 50, 69, 70, 65, 83, 49, 49, 12,  2,  0,  0, 78, 50, 69, 68,   /* 0x a20 */
 69, 67, 49, 48, 18,  2,  0,  0, 78, 50, 69, 83, 77, 65, 50, 48,   /* 0x a30 */
 29,  2,  0,  0,  0,  0,  0,  0, 31,  2,  0,  0, 78, 50, 69, 83,   /* 0x a40 */
 77, 65, 49, 48,  2,  0,  0,  0, 78, 50, 69, 70, 65, 83, 50, 48,   /* 0x a50 */
 34,  2,  0,  0,  0,  0,  0,  0, 38,  2,  0,  0, 78, 50, 69, 70,   /* 0x a60 */
 65, 83, 49, 49,  0,  0,  0,  0, 78, 50, 69, 68, 69, 67, 50, 48,   /* 0x a70 */
 43,  2,  0,  0, 78, 50, 69, 83, 77, 65, 51, 48, 56,  2,  0,  0,   /* 0x a80 */
  0,  0,  0,  0, 69,  2,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48,   /* 0x a90 */
 31,  0,  0,  0, 78, 50, 69, 70, 65, 83, 51, 48, 69,  2,  0,  0,   /* 0x aa0 */
  0,  0,  0,  0, 75,  2,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48,   /* 0x ab0 */
 31,  0,  0,  0,  0,  0,  0,  0, 84,  2,  0,  0, 78, 50, 69, 68,   /* 0x ac0 */
 69, 67, 51, 48, 31,  0,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48,   /* 0x ad0 */
 84,  2,  0,  0,  0,  0,  0,  0,100,  2,  0,  0, 78, 50, 69, 68,   /* 0x ae0 */
 69, 67, 50, 48,  0,  0,  0,  0,  0,  0,  0,  0,115,  2,  0,  0,   /* 0x af0 */
 78, 50, 69, 68, 69, 67, 53, 48,  0,  0,  0,  0,  0,  0,  0,  0,   /* 0x b00 */
133,  2,  0,  0, 78, 50, 69, 68, 69, 67, 54, 48,  0,  0,  0,  0,   /* 0x b10 */
 78, 50, 69, 83, 77, 65, 52, 48,179,  2,  0,  0,  0,  0,  0,  0,   /* 0x b20 */
192,  2,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48, 82,  0,  0,  0,   /* 0x b30 */
 78, 50, 69, 70, 65, 83, 52, 48,192,  2,  0,  0,  0,  0,  0,  0,   /* 0x b40 */
196,  2,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48, 82,  0,  0,  0,   /* 0x b50 */
  0,  0,  0,  0,207,  2,  0,  0, 78, 50, 69, 68, 69, 67, 51, 48,   /* 0x b60 */
 82,  0,  0,  0, 78, 50, 69, 68, 85, 77, 77, 49,207,  2,  0,  0,   /* 0x b70 */
 78, 50, 69, 83, 77, 65, 53, 48,207,  2,  0,  0, 78, 50, 69, 70,   /* 0x b80 */
 65, 83, 53, 48,209,  2,  0,  0, 78, 50, 69, 68, 69, 67, 53, 48,   /* 0x b90 */
212,  2,  0,  0, 78, 50, 69, 83, 77, 65, 54, 48,221,  2,  0,  0,   /* 0x ba0 */
  0,  0,  0,  0,233,  2,  0,  0, 78, 50, 69, 68, 69, 67, 49, 48,   /* 0x bb0 */
  0,  0,  0,  0, 78, 50, 69, 70, 65, 83, 54, 48,233,  2,  0,  0,   /* 0x bc0 */
  0,  0,  0,  0,244,  2,  0,  0, 78, 50, 69, 70, 65, 83, 54, 49,   /* 0x bd0 */
  0,  0,  0,  0,  0,  0,  0,  0,  2,  3,  0,  0, 78, 50, 69, 68,   /* 0x be0 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 69, 70, 65, 83, 54, 49,   /* 0x bf0 */
  2,  3,  0,  0,  0,  0,  0,  0, 24,  3,  0,  0, 78, 50, 69, 68,   /* 0x c00 */
 69, 67, 49, 48,  0,  0,  0,  0, 78, 50, 69, 68, 69, 67, 54, 48,   /* 0x c10 */
 24,  3,  0,  0, 78, 82, 86, 50, 69, 69, 78, 68, 24,  3,  0,  0,   /* 0x c20 */
 67, 65, 76, 76, 84, 82, 48, 48, 24,  3,  0,  0, 67, 84, 67, 76,   /* 0x c30 */
 69, 86, 69, 49, 38,  3,  0,  0,  0,  0,  0,  0, 43,  3,  0,  0,   /* 0x c40 */
 67, 65, 76, 76, 84, 82, 48, 48,  5,  0,  0,  0, 67, 65, 76, 76,   /* 0x c50 */
 84, 82, 48, 49, 43,  3,  0,  0, 67, 84, 68, 85, 77, 77, 89, 49,   /* 0x c60 */
 48,  3,  0,  0, 67, 84, 66, 83, 72, 82, 48, 49, 48,  3,  0,  0,   /* 0x c70 */
 67, 84, 66, 82, 79, 82, 48, 49, 52,  3,  0,  0, 67, 84, 66, 83,   /* 0x c80 */
 87, 65, 48, 49, 54,  3,  0,  0, 67, 65, 76, 76, 84, 82, 48, 50,   /* 0x c90 */
 59,  3,  0,  0,  0,  0,  0,  0, 73,  3,  0,  0, 67, 65, 76, 76,   /* 0x ca0 */
 84, 82, 48, 48, 10,  0,  0,  0, 67, 65, 76, 76, 84, 82, 49, 48,   /* 0x cb0 */
 73,  3,  0,  0, 67, 65, 76, 76, 84, 82, 69, 56, 78,  3,  0,  0,   /* 0x cc0 */
 67, 65, 76, 76, 84, 82, 69, 57, 80,  3,  0,  0, 67, 65, 76, 76,   /* 0x cd0 */
 84, 82, 49, 49, 82,  3,  0,  0,  0,  0,  0,  0, 86,  3,  0,  0,   /* 0x ce0 */
 67, 65, 76, 76, 84, 82, 49, 51,  5,  0,  0,  0, 67, 84, 67, 76,   /* 0x cf0 */
 69, 86, 69, 50, 86,  3,  0,  0,  0,  0,  0,  0, 91,  3,  0,  0,   /* 0x d00 */
 67, 65, 76, 76, 84, 82, 49, 49,  0,  0,  0,  0, 67, 65, 76, 76,   /* 0x d10 */
 84, 82, 49, 50, 91,  3,  0,  0, 67, 84, 68, 85, 77, 77, 89, 50,   /* 0x d20 */
 93,  3,  0,  0, 67, 84, 66, 83, 72, 82, 49, 49, 93,  3,  0,  0,   /* 0x d30 */
 67, 84, 66, 82, 79, 82, 49, 49, 97,  3,  0,  0, 67, 84, 66, 83,   /* 0x d40 */
 87, 65, 49, 49, 99,  3,  0,  0, 67, 65, 76, 76, 84, 82, 49, 51,   /* 0x d50 */
104,  3,  0,  0,  0,  0,  0,  0,109,  3,  0,  0, 67, 65, 76, 76,   /* 0x d60 */
 84, 82, 49, 48,  5,  0,  0,  0, 67, 84, 84, 72, 69, 69, 78, 68,   /* 0x d70 */
109,  3,  0,  0, 76, 69, 88, 69, 67, 48, 49, 53,109,  3,  0,  0,   /* 0x d80 */
 76, 88, 85, 78, 70, 48, 48, 48,139,  3,  0,  0,  0,  0,  0,  0,   /* 0x d90 */
141,  3,  0,  0, 76, 88, 85, 78, 70, 48, 49, 48,  5,  0,  0,  0,   /* 0x da0 */
 76, 88, 85, 78, 70, 48, 48, 50,141,  3,  0,  0, 77, 82, 85, 66,   /* 0x db0 */
 89, 84, 69, 48,146,  3,  0,  0, 76, 88, 77, 82, 85, 48, 48, 53,   /* 0x dc0 */
148,  3,  0,  0, 76, 88, 77, 82, 85, 48, 48, 54,153,  3,  0,  0,   /* 0x dd0 */
 76, 88, 77, 82, 85, 48, 48, 55,160,  3,  0,  0, 76, 88, 85, 78,   /* 0x de0 */
 70, 48, 48, 56,167,  3,  0,  0, 76, 88, 85, 78, 70, 48, 49, 48,   /* 0x df0 */
171,  3,  0,  0,  0,  0,  0,  0,176,  3,  0,  0, 76, 88, 85, 78,   /* 0x e00 */
 70, 48, 52, 50,  0,  0,  0,  0, 76, 88, 74, 67, 67, 48, 49, 48,   /* 0x e10 */
176,  3,  0,  0, 76, 88, 77, 82, 85, 48, 52, 53,179,  3,  0,  0,   /* 0x e20 */
 76, 88, 77, 82, 85, 48, 52, 54,182,  3,  0,  0, 76, 88, 74, 67,   /* 0x e30 */
 67, 48, 50, 48,184,  3,  0,  0,  0,  0,  0,  0,186,  3,  0,  0,   /* 0x e40 */
 76, 88, 85, 78, 70, 48, 51, 52,  0,  0,  0,  0, 76, 88, 74, 67,   /* 0x e50 */
 67, 48, 50, 49,186,  3,  0,  0,  0,  0,  0,  0,191,  3,  0,  0,   /* 0x e60 */
 76, 88, 85, 78, 70, 48, 51, 52,  0,  0,  0,  0, 76, 88, 74, 67,   /* 0x e70 */
 67, 48, 50, 51,191,  3,  0,  0, 76, 88, 85, 78, 70, 48, 51, 55,   /* 0x e80 */
198,  3,  0,  0, 76, 88, 85, 78, 70, 51, 56, 54,200,  3,  0,  0,   /* 0x e90 */
 76, 88, 85, 78, 70, 51, 56, 55,201,  3,  0,  0, 76, 88, 85, 78,   /* 0x ea0 */
 70, 51, 56, 56,210,  3,  0,  0,  0,  0,  0,  0,213,  3,  0,  0,   /* 0x eb0 */
 76, 88, 85, 78, 70, 48, 52, 48,  0,  0,  0,  0, 76, 88, 85, 78,   /* 0x ec0 */
 70, 52, 56, 54,213,  3,  0,  0, 76, 88, 85, 78, 70, 52, 56, 55,   /* 0x ed0 */
217,  3,  0,  0,  0,  0,  0,  0,219,  3,  0,  0, 76, 88, 85, 78,   /* 0x ee0 */
 70, 48, 52, 48,  0,  0,  0,  0, 76, 88, 77, 82, 85, 48, 54, 53,   /* 0x ef0 */
219,  3,  0,  0,  0,  0,  0,  0,223,  3,  0,  0, 76, 88, 77, 82,   /* 0x f00 */
 85, 48, 55, 48,  5,  0,  0,  0, 77, 82, 85, 66, 89, 84, 69, 51,   /* 0x f10 */
223,  3,  0,  0, 77, 82, 85, 65, 82, 66, 51, 48,225,  3,  0,  0,   /* 0x f20 */
 77, 82, 85, 66, 73, 84, 83, 51,226,  3,  0,  0, 77, 82, 85, 65,   /* 0x f30 */
 82, 66, 52, 48,228,  3,  0,  0, 76, 88, 77, 82, 85, 48, 55, 48,   /* 0x f40 */
232,  3,  0,  0,  0,  0,  0,  0,237,  3,  0,  0, 76, 88, 85, 78,   /* 0x f50 */
 70, 48, 52, 48,  0,  0,  0,  0, 77, 82, 85, 66, 89, 84, 69, 52,   /* 0x f60 */
240,  3,  0,  0, 77, 82, 85, 66, 73, 84, 83, 52,243,  3,  0,  0,   /* 0x f70 */
 77, 82, 85, 65, 82, 66, 53, 48,245,  3,  0,  0, 76, 88, 77, 82,   /* 0x f80 */
 85, 48, 56, 48,251,  3,  0,  0, 77, 82, 85, 66, 89, 84, 69, 53,   /* 0x f90 */
254,  3,  0,  0, 77, 82, 85, 65, 82, 66, 54, 48,  0,  4,  0,  0,   /* 0x fa0 */
 77, 82, 85, 66, 73, 84, 83, 53,  1,  4,  0,  0, 77, 82, 85, 65,   /* 0x fb0 */
 82, 66, 55, 48,  3,  4,  0,  0, 76, 88, 77, 82, 85, 48, 57, 48,   /* 0x fc0 */
  7,  4,  0,  0,  0,  0,  0,  0, 14,  4,  0,  0, 76, 88, 77, 82,   /* 0x fd0 */
 85, 49, 48, 48, 10,  0,  0,  0, 77, 82, 85, 66, 89, 84, 69, 54,   /* 0x fe0 */
 18,  4,  0,  0, 77, 82, 85, 65, 82, 66, 56, 48, 20,  4,  0,  0,   /* 0x ff0 */
 77, 82, 85, 66, 73, 84, 83, 54, 21,  4,  0,  0, 77, 82, 85, 65,   /* 0x1000 */
 82, 66, 57, 48, 23,  4,  0,  0, 76, 88, 77, 82, 85, 49, 48, 48,   /* 0x1010 */
 27,  4,  0,  0, 76, 88, 85, 78, 70, 48, 52, 48, 43,  4,  0,  0,   /* 0x1020 */
 76, 88, 77, 82, 85, 49, 49, 48, 48,  4,  0,  0, 76, 88, 77, 82,   /* 0x1030 */
 85, 49, 49, 49, 51,  4,  0,  0, 76, 88, 85, 78, 70, 48, 52, 49,   /* 0x1040 */
 53,  4,  0,  0,  0,  0,  0,  0, 60,  4,  0,  0, 76, 88, 85, 78,   /* 0x1050 */
 70, 48, 51, 52,  0,  0,  0,  0, 76, 88, 85, 78, 70, 48, 52, 50,   /* 0x1060 */
 60,  4,  0,  0, 76, 69, 88, 69, 67, 48, 49, 54, 60,  4,  0,  0,   /* 0x1070 */
  0,  0,  0,  0, 62,  4,  0,  0, 76, 88, 85, 78, 70, 48, 52, 50,   /* 0x1080 */
  0,  0,  0,  0, 76, 88, 77, 82, 85, 48, 49, 48, 62,  4,  0,  0,   /* 0x1090 */
 76, 88, 74, 77, 80, 65, 48, 48, 63,  4,  0,  0, 76, 88, 67, 65,   /* 0x10a0 */
 76, 76, 66, 48, 65,  4,  0,  0, 76, 88, 85, 78, 70, 48, 50, 49,   /* 0x10b0 */
 67,  4,  0,  0, 76, 88, 77, 82, 85, 48, 50, 50, 73,  4,  0,  0,   /* 0x10c0 */
 76, 88, 74, 77, 80, 65, 48, 49, 76,  4,  0,  0, 76, 88, 67, 65,   /* 0x10d0 */
 76, 76, 66, 49, 78,  4,  0,  0, 77, 82, 85, 66, 73, 84, 83, 49,   /* 0x10e0 */
 80,  4,  0,  0, 76, 88, 77, 82, 85, 48, 51, 48, 81,  4,  0,  0,   /* 0x10f0 */
 77, 82, 85, 66, 89, 84, 69, 49, 83,  4,  0,  0, 77, 82, 85, 65,   /* 0x1100 */
 82, 66, 49, 48, 85,  4,  0,  0, 76, 88, 77, 82, 85, 48, 52, 48,   /* 0x1110 */
 86,  4,  0,  0,  0,  0,  0,  0, 88,  4,  0,  0, 76, 88, 77, 82,   /* 0x1120 */
 85, 48, 51, 48,  0,  0,  0,  0, 76, 88, 85, 78, 70, 48, 51, 48,   /* 0x1130 */
 88,  4,  0,  0, 76, 88, 74, 67, 67, 48, 48, 48, 94,  4,  0,  0,   /* 0x1140 */
  0,  0,  0,  0,102,  4,  0,  0, 76, 88, 74, 67, 67, 48, 49, 48,   /* 0x1150 */
  0,  0,  0,  0, 76, 88, 67, 74, 48, 77, 82, 85,102,  4,  0,  0,   /* 0x1160 */
 76, 88, 67, 74, 49, 77, 82, 85,104,  4,  0,  0, 76, 88, 67, 65,   /* 0x1170 */
 76, 74, 77, 80,107,  4,  0,  0, 76, 88, 67, 65, 76, 76, 48, 48,   /* 0x1180 */
110,  4,  0,  0,  0,  0,  0,  0,112,  4,  0,  0, 76, 88, 85, 78,   /* 0x1190 */
 70, 48, 51, 55,  0,  0,  0,  0, 76, 88, 67, 65, 76, 76, 48, 49,   /* 0x11a0 */
112,  4,  0,  0, 76, 88, 67, 74, 50, 77, 82, 85,115,  4,  0,  0,   /* 0x11b0 */
  0,  0,  0,  0,117,  4,  0,  0, 76, 88, 85, 78, 70, 48, 51, 55,   /* 0x11c0 */
  0,  0,  0,  0, 76, 88, 67, 74, 52, 77, 82, 85,117,  4,  0,  0,   /* 0x11d0 */
  0,  0,  0,  0,119,  4,  0,  0, 76, 88, 85, 78, 70, 48, 51, 52,   /* 0x11e0 */
  0,  0,  0,  0, 76, 88, 67, 74, 54, 77, 82, 85,119,  4,  0,  0,   /* 0x11f0 */
  0,  0,  0,  0,121,  4,  0,  0, 76, 88, 67, 74, 56, 77, 82, 85,   /* 0x1200 */
  1,  0,  0,  0, 76, 88, 67, 74, 55, 77, 82, 85,121,  4,  0,  0,   /* 0x1210 */
  0,  0,  0,  0,123,  4,  0,  0, 76, 88, 67, 74, 56, 77, 82, 85,   /* 0x1220 */
  1,  0,  0,  0, 76, 88, 67, 74, 56, 77, 82, 85,123,  4,  0,  0,   /* 0x1230 */
  0,  0,  0,  0,126,  4,  0,  0, 76, 88, 85, 78, 70, 48, 51, 55,   /* 0x1240 */
  0,  0,  0,  0, 76, 88, 85, 78, 70, 48, 51, 52,126,  4,  0,  0,   /* 0x1250 */
  0,  0,  0,  0,131,  4,  0,  0, 76, 88, 85, 78, 70, 48, 51, 48,   /* 0x1260 */
  0,  0,  0,  0, 76, 88, 77, 82, 85, 48, 53, 53,131,  4,  0,  0,   /* 0x1270 */
 77, 82, 85, 66, 89, 84, 69, 50,133,  4,  0,  0, 77, 82, 85, 66,   /* 0x1280 */
 73, 84, 83, 50,138,  4,  0,  0, 77, 82, 85, 65, 82, 66, 50, 48,   /* 0x1290 */
143,  4,  0,  0, 76, 88, 77, 82, 85, 48, 53, 55,148,  4,  0,  0,   /* 0x12a0 */
 76, 88, 77, 82, 85, 48, 53, 56,154,  4,  0,  0, 76, 88, 85, 78,   /* 0x12b0 */
 70, 48, 51, 53,155,  4,  0,  0, 67, 75, 76, 76, 84, 82, 48, 48,   /* 0x12c0 */
161,  4,  0,  0,  0,  0,  0,  0,165,  4,  0,  0, 67, 75, 76, 76,   /* 0x12d0 */
 84, 82, 50, 48, 30,  0,  0,  0, 67, 75, 76, 76, 84, 82, 49, 48,   /* 0x12e0 */
170,  4,  0,  0,  0,  0,  0,  0,184,  4,  0,  0, 67, 75, 76, 76,   /* 0x12f0 */
 84, 82, 50, 48,  6,  0,  0,  0, 67, 75, 76, 76, 84, 82, 50, 48,   /* 0x1300 */
184,  4,  0,  0,  0,  0,  0,  0,190,  4,  0,  0, 67, 75, 76, 76,   /* 0x1310 */
 84, 82, 52, 48,  0,  0,  0,  0,  0,  0,  0,  0,194,  4,  0,  0,   /* 0x1320 */
 67, 75, 76, 76, 84, 82, 52, 48,  0,  0,  0,  0, 67, 75, 76, 76,   /* 0x1330 */
 84, 82, 51, 48,217,  4,  0,  0,  0,  0,  0,  0,224,  4,  0,  0,   /* 0x1340 */
 67, 75, 76, 76, 84, 82, 49, 48, 14,  0,  0,  0, 67, 75, 76, 76,   /* 0x1350 */
 84, 82, 52, 48,224,  4,  0,  0,  0,  0,  0,  0,229,  4,  0,  0,   /* 0x1360 */
 67, 75, 76, 76, 84, 82, 48, 48,  4,  0,  0,  0, 76, 69, 88, 69,   /* 0x1370 */
 67, 48, 49, 55,229,  4,  0,  0, 76, 69, 88, 69, 67, 48, 50, 48,   /* 0x1380 */
231,  4,  0,  0, 88, 84, 72, 69, 69, 78, 68, 88, 26,  5,  0,  0,   /* 0x1390 */
255,255,255,255, 26,  5                                            /* 0x13a0 */
};
