// stb_dxt.h - Real-Time DXT1/DXT5 compressor 
// Based on original by fabian "ryg" giesen v1.04
// Custom version, modified by Yann Collet
//
/*
BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the following disclaimer
in the documentation and/or other materials provided with the
distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

You can contact the author at :
- RygsDXTc source repository : http://code.google.com/p/rygsdxtc/

*/
// use '#define STB_DXT_IMPLEMENTATION' before including to create the implementation
//
// USAGE:
//   call stb_compress_dxt_block() for every block (you must pad)
//     source should be a 4x4 block of RGBA data in row-major order;
//     A is ignored if you specify alpha=0; you can turn on dithering
//     and "high quality" using mode.
//
// version history:
//   v1.06  - (cyan) implement Fabian Giesen's comments
//   v1.05  - (cyan) speed optimizations
//   v1.04  - (ryg) default to no rounding bias for lerped colors (as per S3TC/DX10 spec);
//            single color match fix (allow for inexact color interpolation);
//            optimal DXT5 index finder; "high quality" mode that runs multiple refinement steps.
//   v1.03  - (stb) endianness support
//   v1.02  - (stb) fix alpha encoding bug
//   v1.01  - (stb) fix bug converting to RGB that messed up quality, thanks ryg & cbloom
//   v1.00  - (stb) first release

#pragma once
#include "HammUErPrivatePCH.h"

#ifndef STB_INCLUDE_STB_DXT_H
#define STB_INCLUDE_STB_DXT_H

// XCODE IS A PIECE OF GARBAGE THAT SUDDENLY CAN'T SEE THE OTHER ONE ANY MORE EVEN THOUGH IT USED TO
#define STB_DXT_IMPLEMENTATION

//*******************************************************************
// Enable custom Optimisations
// Comment this define if you want to revert to ryg's original code
#define NEW_OPTIMISATIONS
//*******************************************************************

// compression mode (bitflags)
#define STB_DXT_NORMAL    0
#define STB_DXT_DITHER    1   // use dithering. dubious win. never use for normal maps and the like!
#define STB_DXT_HIGHQUAL  2   // high quality mode, does two refinement steps instead of 1. ~30-40% slower.

void rygCompress(unsigned char *dst, unsigned char *src, int w, int h, int isDxt5);

// TODO remove these, not working properly..
//void rygCompressYCoCg(unsigned char *dst, unsigned char *src, int w, int h);
//void linearize(unsigned char * dst, const unsigned char * src, int n);

void stb_compress_dxt_block(unsigned char *dest, const unsigned char *src, int alpha, int mode);
#define STB_COMPRESS_DXT_BLOCK
static unsigned char stb__Expand5[32];
static unsigned char stb__Expand6[64];
static unsigned char stb__OMatch5[256][2];
static unsigned char stb__OMatch6[256][2];
static unsigned char stb__QuantRBTab[256 + 16];
static unsigned char stb__QuantGTab[256 + 16];

#endif // STB_INCLUDE_STB_DXT_H
