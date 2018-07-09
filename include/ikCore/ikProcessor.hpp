// 
// MIT License
// 
// Copyright (c) 2018 The ikTools team
// 
// All rights reserved.
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 

#ifndef __ikCore_ikProcessor_Header_
#define __ikCore_ikProcessor_Header_

//
// Based on Boost.Predef library.
// https://github.com/boostorg/predef
//

#include <ikCore/ikVersion.hpp>

//
// ikPROCESSOR_XXX macro is defined when XXX processor is detected.
// Processors supported:
//   - ikPROCESSOR_ALPHA    -> DEC Alpha processor
//   - ikPROCESSOR_ARM      -> ARM processor
//   - ikPROCESSOR_BLACKFIN -> Blackfin Processors from Analog Devices
//   - ikPROCESSOR_CONVEX   -> Convex Computer processor
//   - ikPROCESSOR_IA64     -> Intel Itanium 64 processor
//   - ikPROCESSOR_M68K     -> Motorola 68k processor
//   - ikPROCESSOR_MIPS     -> MIPS processor
//   - ikPROCESSOR_PARISC   -> HP/PA RISC processor
//   - ikPROCESSOR_PPC      -> PowerPC processor
//   - ikPROCESSOR_PTX      -> PTX processor
//   - ikPROCESSOR_PYRAMID  -> Pyramid 9810 processor
//   - ikPROCESSOR_RS6000   -> RS/6000 processor
//   - ikPROCESSOR_SPARC    -> SPARC processor
//   - ikPROCESSOR_SH       -> SuperH processor
//   - ikPROCESSOR_SYS370   -> System/370 processor
//   - ikPROCESSOR_SYS390   -> System/390 processor
//   - ikPROCESSOR_X86      -> Intel x86 processor
//     - ikPROCESSOR_X86_32 -> 32-bit version
//     - ikPROCESSOR_X86_64 -> 64-bit version
//   - ikPROCESSOR_Z        -> z/Architecture processor
//

#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA)
//
// DEC Alpha processor.
// http://en.wikipedia.org/wiki/DEC_Alpha
//
#  if defined(__alpha_ev4__)
#    define ikPROCESSOR_ALPHA ikMAKE_VERSION(4,0,0)
#  elif defined(__alpha_ev5__)
#    define ikPROCESSOR_ALPHA ikMAKE_VERSION(5,0,0)
#  elif defined(__alpha_ev6__)
#    define ikPROCESSOR_ALPHA ikMAKE_VERSION(6,0,0)
#  else
#    define ikPROCESSOR_ALPHA ikMAKE_VERSION_DEFAULT
#  endif
#endif // __alpha__ || __alpha || _M_ALPHA

#if defined(__arm__) || defined(__arm64) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) || \
    defined(__TARGET_ARCH_THUMB) || defined(__ARM_ARCH) || defined(_M_ARM) || defined(_M_ARM64)
//
// ARM processor.
// http://en.wikipedia.org/wiki/ARM_architecture
//
#  if defined(__arm64)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(8,0,0)
#  elif defined(__TARGET_ARCH_ARM)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(__TARGET_ARCH_ARM,0,0)
#  elif defined(__TARGET_ARCH_THUMB)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(__TARGET_ARCH_THUMB,0,0)
#  elif defined(__ARM_ARCH)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(__ARM_ARCH,0,0)
#  elif defined(_M_ARM64)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(8,0,0)
#  elif defined(_M_ARM)
#    define ikPROCESSOR_ARM ikMAKE_VERSION(_M_ARM,0,0)
#  else
#    define ikPROCESSOR_ARM ikMAKE_VERSION_DEFAULT
#  endif
#endif // __arm__ || __arm64 || __thumb__ || __TARGET_ARCH_ARM || ...

#if defined(__bfin__) || defined(__BFIN__) || defined(bfin) || defined(BFIN)
//
// Blackfin Processors from Analog Devices.
//
#  define ikPROCESSOR_BLACKFIN ikMAKE_VERSION_DEFAULT
#endif // __bfin__ || __BFIN__ || bfin || BFIN

#if defined(__convex__)
//
// Convex Computer processor.
// http://en.wikipedia.org/wiki/Convex_Computer
//
#  if defined(__convex_c1__)
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION(1,0,0)
#  elif defined(__convex_c2__)
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION(2,0,0)
#  elif defined(__convex_c32__)
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION(3,2,0)
#  elif defined(__convex_c34__)
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION(3,4,0)
#  elif defined(__convex_c38__)
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION(3,8,0)
#  else
#    define ikPROCESSOR_CONVEX ikMAKE_VERSION_DEFAULT
#  endif
#endif // __convex__

#if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) || defined(_M_IA64) || defined(__itanium__)
//
// Intel Itanium 64 processor.
// http://en.wikipedia.org/wiki/Ia64
//
#  define ikPROCESSOR_IA64 ikMAKE_VERSION_DEFAULT
#endif // __ia64__ || _IA64 || __IA64__ || __ia64 || _M_IA64 || __itanium__

#if defined(__m68k__) || defined(M68000)
//
// Motorola 68k processor.
// http://en.wikipedia.org/wiki/M68k
//
#  if defined(__mc68060__) || defined(mc68060) || defined(__mc68060)
#    define ikPROCESSOR_M68K ikMAKE_VERSION(6,0,0)
#  elif defined(__mc68040__) || defined(mc68040) || defined(__mc68040)
#    define ikPROCESSOR_M68K ikMAKE_VERSION(4,0,0)
#  elif defined(__mc68030__) || defined(mc68030) || defined(__mc68030)
#    define ikPROCESSOR_M68K ikMAKE_VERSION(3,0,0)
#  elif defined(__mc68020__) || defined(mc68020) || defined(__mc68020)
#    define ikPROCESSOR_M68K ikMAKE_VERSION(2,0,0)
#  elif defined(__mc68010__) || defined(mc68010) || defined(__mc68010)
#    define ikPROCESSOR_M68K ikMAKE_VERSION(1,0,0)
#  elif defined(__mc68000__) || defined(mc68000) || defined(__mc68000)
#    define ikPROCESSOR_M68K ikMAKE_VERSION_DEFAULT
#  else
#    define ikPROCESSOR_M68K ikMAKE_VERSION_DEFAULT
#  endif
#endif // __m68k__ || M68000

#if defined(__mips__) || defined(__mips) || defined(__MIPS__)
//
// MIPS processor.
// http://en.wikipedia.org/wiki/MIPS_architecture
//
#  if defined(__mips)
#    define ikPROCESSOR_MIPS ikMAKE_VERSION(__mips,0,0)
#  elif defined(_MIPS_ISA_MIPS1) || defined(_R3000)
#    define ikPROCESSOR_MIPS ikMAKE_VERSION(1,0,0)
#  elif defined(_MIPS_ISA_MIPS2) || defined(__MIPS_ISA2__) || defined(_R4000)
#    define ikPROCESSOR_MIPS ikMAKE_VERSION(2,0,0)
#  elif defined(_MIPS_ISA_MIPS3) || defined(__MIPS_ISA3__)
#    define ikPROCESSOR_MIPS ikMAKE_VERSION(3,0,0)
#  elif defined(_MIPS_ISA_MIPS4) || defined(__MIPS_ISA4__)
#    define ikPROCESSOR_MIPS ikMAKE_VERSION(4,0,0)
#  else
#    define ikPROCESSOR_MIPS ikMAKE_VERSION_DEFAULT
#  endif
#endif // __mips__ || __mips || __MIPS__

#if defined(__hppa__) || defined(__hppa) || defined(__HPPA__)
//
// HP/PA RISC processor.
// http://en.wikipedia.org/wiki/PA-RISC_family
//
#  if defined(_PA_RISC1_0)
#    define ikPROCESSOR_PARISC ikMAKE_VERSION(1,0,0)
#  elif defined(_PA_RISC1_1) || defined(__HPPA11__) || defined(__PA7100__)
#    define ikPROCESSOR_PARISC ikMAKE_VERSION(1,1,0)
#  elif defined(_PA_RISC2_0) || defined(__RISC2_0__) || defined(__HPPA20__) || defined(__PA8000__)
#    define ikPROCESSOR_PARISC ikMAKE_VERSION(2,0,0)
#  else
#    define ikPROCESSOR_PARISC ikMAKE_VERSION_DEFAULT
#  endif
#endif // __hppa__ || __hppa || __HPPA__

#if defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) || defined(_M_PPC) || \
    defined(_ARCH_PPC) || defined(__PPCGECKO__) || defined(__PPCBROADWAY__) || defined(_XENON)
//
// PowerPC processor.
// http://en.wikipedia.org/wiki/PowerPC
//
#  if defined(__ppc601__) || defined(_ARCH_601)
#    define ikPROCESSOR_PPC ikMAKE_VERSION(6,1,0)
#  elif defined(__ppc603__) || defined(_ARCH_603)
#    define ikPROCESSOR_PPC ikMAKE_VERSION(6,3,0)
#  elif defined(__ppc604__) || defined(__ppc604__)
#    define ikPROCESSOR_PPC ikMAKE_VERSION(6,4,0)
#  else
#    define ikPROCESSOR_PPC ikMAKE_VERSION_DEFAULT
#  endif
#endif // __powerpc || __powerpc__ || __POWERPC__ || __ppc__ || _M_PPC || ...

#if defined(__CUDA_ARCH__)
//
// PTX processor.
// https://en.wikipedia.org/wiki/Parallel_Thread_Execution
//
#  define ikPROCESSOR_PTX ikMAKE_VERSION_10_VR0(__CUDA_ARCH__)
#endif // __CUDA_ARCH__

#if defined(pyr)
//
// Pyramid 9810 processor.
//
#  define ikPROCESSOR_PYRAMID ikMAKE_VERSION_DEFAULT
#endif // pyr

#if defined(__THW_RS6000) || defined(_IBMR2) || defined(_POWER) || defined(_ARCH_PWR) || defined(_ARCH_PWR2)
//
// RS/6000 processor.
// http://en.wikipedia.org/wiki/RS/6000
//
#  define ikPROCESSOR_RS6000 ikMAKE_VERSION_DEFAULT
#endif // __THW_RS6000 || _IBMR2 || _POWER || _ARCH_PWR || _ARCH_PWR2

#if defined(__sparc__) || defined(__sparc)
//
// SPARC processor.
// http://en.wikipedia.org/wiki/SPARC
//
#  if defined(__sparcv9)
#    define ikPROCESSOR_SPARC ikMAKE_VERSION(9,0,0)
#  elif defined(__sparcv8)
#    define ikPROCESSOR_SPARC ikMAKE_VERSION(8,0,0)
#  else
#    define ikPROCESSOR_SPARC ikMAKE_VERSION_DEFAULT
#  endif
#endif // __sparc__ || __sparc

#if defined(__sh__)
//
// SuperH processor.
// If available versions [1-5] are specifically detected. 
// http://en.wikipedia.org/wiki/SuperH
//
#  if defined(__SH5__)
#    define ikPROCESSOR_SH ikMAKE_VERSION(5,0,0)
#  elif defined(__SH4__)
#    define ikPROCESSOR_SH ikMAKE_VERSION(4,0,0)
#  elif defined(__sh3__) || defined(__SH3__)
#    define ikPROCESSOR_SH ikMAKE_VERSION(3,0,0)
#  elif defined(__sh2__)
#    define ikPROCESSOR_SH ikMAKE_VERSION(2,0,0)
#  elif defined(__sh1__)
#    define ikPROCESSOR_SH ikMAKE_VERSION(1,0,0)
#  else
#    define ikPROCESSOR_SH ikMAKE_VERSION_DEFAULT
#  endif
#endif // __sh__

#if defined(__370__) || defined(__THW_370__)
//
// System/370 processor.
// http://en.wikipedia.org/wiki/System/370
//
#  define ikPROCESSOR_SYS370 ikMAKE_VERSION_DEFAULT
#endif // __370__ || __THW_370__

#if defined(__s390__) || defined(__s390x__)
//
// System/390 processor.
// http://en.wikipedia.org/wiki/System/390
//
#  define ikPROCESSOR_SYS390 ikMAKE_VERSION_DEFAULT
#endif // __s390__ || __s390x__

#if defined(i386) || defined(__i386__) || defined(__i486__) || defined(__i586__) || defined(__i686__) || defined(__i386) || \
    defined(_M_IX86) || defined(_X86_) || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__)
//
// Intel x86 processor.
// http://en.wikipedia.org/wiki/X86
//
#  define ikPROCESSOR_X86 ikMAKE_VERSION_DEFAULT
#  if defined(__I86__)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION(__I86__,0,0)
#  elif defined(_M_IX86)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION_10_VV00(_M_IX86)
#  elif defined(__i686__)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION(6,0,0)
#  elif defined(__i586__)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION(5,0,0)
#  elif defined(__i486__)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION(4,0,0)
#  elif defined(__i386__)
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION(3,0,0)
#  else
#    define ikPROCESSOR_X86_32 ikMAKE_VERSION_DEFAULT
#  endif
#endif // i386 || __i386__ || __i486__ || __i586__ || __i686__ || __i386 || ...

#if defined(__x86_64) || defined(__x86_64__) || defined(__amd64__) || defined(__amd64) || defined(_M_X64)
//
// Intel x86 processor.
// http://en.wikipedia.org/wiki/X86
//
#  define ikPROCESSOR_X86 ikMAKE_VERSION_DEFAULT
#  define ikPROCESSOR_X86_64 ikMAKE_VERSION_DEFAULT
#endif // __x86_64 || __x86_64__ || __amd64__ || __amd64 || _M_X64

#if defined(__SYSC_ZARCH__)
//
// z/Architecture processor.
// http://en.wikipedia.org/wiki/Z/Architecture
//
#  define ikPROCESSOR_Z ikMAKE_VERSION_DEFAULT
#endif // __SYSC_ZARCH__

#endif // !__ikCore_ikProcessor_Header_
