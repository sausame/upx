/* ACC -- Automatic Compiler Configuration

   Copyright (C) 1996-2003 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   This software is a copyrighted work licensed under the terms of
   the GNU General Public License. Please consult the file "ACC_LICENSE"
   for details.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/
 */


/*
 * C/C++ Compiler - exactly one of:
 *
 *   ACC_CC_UNKNOWN         [default]
 *   ACC_CC_GNUC
 *   ...
 */

#if defined(__GNUC__) && defined(__VERSION__)
#  define ACC_CC_GNUC           1
#  define ACC_INFO_CC           "gcc"
#  define ACC_INFO_CCVER        __VERSION__
#elif defined(__BORLANDC__)
#  define ACC_CC_BORLANDC       1
#  define ACC_INFO_CC           "Borland C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__BORLANDC__)
#elif defined(__DMC__)
#  define ACC_CC_DMC            1
#  define ACC_INFO_CC           "Digital Mars C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__DMC__)
#elif defined(__INTEL_COMPILER)
#  define ACC_CC_INTELC         1
#  define ACC_INFO_CC           "Intel C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__INTEL_COMPILER)
#elif defined(__LCC__)
#  define ACC_CC_LCC            1
#  define ACC_INFO_CC           "lcc"
#  define ACC_INFO_CCVER        "unknown"
#elif defined(_MSC_VER)
#  define ACC_CC_MSC            1
#  define ACC_INFO_CC           "Microsoft C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(_MSC_VER)
#elif defined(__MWERKS__)
#  define ACC_CC_MWERKS         1
#  define ACC_INFO_CC           "Metrowerks C"
#  define ACC_INFO_CCVER        "unknown"
#elif defined(__PACIFIC__)
#  define ACC_CC_PACIFIC        1
#  define ACC_INFO_CC           "Pacific C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__PACIFIC__)
#elif defined(__PUREC__)
#  define ACC_CC_PUREC          1
#  define ACC_INFO_CC           "Pure C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__PUREC__)
#elif defined(__SC__)
#  define ACC_CC_SYMANTEC       1
#  define ACC_INFO_CC           "Symantec C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__SC__)
#elif defined(__SUNPRO_C)
#  define ACC_CC_SUNPROC        1
#  define ACC_INFO_CC           "Sun C"
#  define ACC_INFO_CCVER        "unknown"
#elif defined(__TINYC__)
#  define ACC_CC_TINYC          1
#  define ACC_INFO_CC           "Tiny C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__TINYC__)
#elif defined(__WATCOMC__)
#  define ACC_CC_WATCOMC        1
#  define ACC_INFO_CC           "Watcom C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__WATCOMC__)
#elif defined(__TURBOC__)
#  define ACC_CC_TURBOC         1
#  define ACC_INFO_CC           "Turbo C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__TURBOC__)
#elif defined(__ZTC__)
#  define ACC_CC_ZORTECHC       1
#  define ACC_INFO_CC           "Zortech C"
#  define ACC_INFO_CCVER        ACC_MACRO_EXPAND(__ZTC__)
#else
#  define ACC_CC_UNKNOWN        1
#  define ACC_INFO_CC           "unknown"
#  define ACC_INFO_CCVER        "unknown"
#endif


/*
vi:ts=4:et
*/
