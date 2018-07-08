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

#ifndef __ikCore_ikCompiler_Header__
#define __ikCore_ikCompiler_Header__

//
// Based on Boost.Predef library.
// https://github.com/boostorg/predef
//

#include <ikCore/ikVersion.hpp>

//
// ikCOMP_XXX macro is defined when XXX compiler is detected.
// Compilers supported:
//   - ikCOMP_BORLAND -> Borland C++ compiler
//   - ikCOMP_CLANG   -> Clang compiler
//   - ikCOMP_COMO    -> Comeau C++ compiler
//   - ikCOMP_DEC     -> Compaq C/C++ compiler
//   - ikCOMP_DIAB    -> Diab C/C++ compiler
//   - ikCOMP_DMC     -> Digital Mars compiler
//   - ikCOMP_SYSC    -> Dignus Systems/C++ compiler
//   - ikCOMP_EDG     -> EDG C++ Frontend compiler
//   - ikCOMP_PATH    -> EKOpath compiler
//   - ikCOMP_GCC     -> Gnu GCC C/C++ compiler
//   - ikCOMP_GHS     -> Green Hills C/C++ compiler
//   - ikCOMP_HPACC   -> HP aC++ compiler
//   - ikCOMP_IAR     -> IAR C/C++ compiler
//   - ikCOMP_IBM     -> IBM XL C/C++ compiler
//   - ikCOMP_INTEL   -> Intel C/C++ compiler
//   - ikCOMP_KAI     -> Kai C++ compiler
//   - ikCOMP_LLVM    -> LLVM compiler
//   - ikCOMP_HIGHC   -> MetaWare High C/C++ compiler
//   - ikCOMP_MWERKS  -> Metrowerks CodeWarrior compiler
//   - ikCOMP_MRI     -> Microtec C/C++ compiler
//   - ikCOMP_MPW     -> MPW C++ compiler
//   - ikCOMP_NVCC    -> NVCC compiler
//   - ikCOMP_PALM    -> Palm C/C++ compiler
//   - ikCOMP_PGI     -> Portland Group C/C++ compiler
//   - ikCOMP_SGI     -> SGI MIPSpro compiler
//   - ikCOMP_SUNPRO  -> Oracle Solaris Studio compiler
//   - ikCOMP_TENDRA  -> TenDRA C/C++ compiler
//   - ikCOMP_MSVC    -> Microsoft Visual C/C++ compiler
//   - ikCOMP_WATCOM  -> Watcom C++ compiler
//

#if defined(__BORLANDC__) || defined(__CODEGEARC__)
//
// Borland C++ compiler.
// Version number available as major, minor, and patch.
// https://en.wikipedia.org/wiki/Borland_C%2B%2B
//
#  if defined(__CODEGEARC__)
#    define ikCOMP_BORLAND ikMAKE_VERSION(__CODEGEARC__)
#  else
#    define ikCOMP_BORLAND ikMAKE_VERSION(__BORLANDC__)
#  endif
#endif // __BORLANDC__ || __CODEGEARC__

#if defined(__clang__)
//
// Clang compiler.
// Version number available as major, minor, and patch.
// https://en.wikipedia.org/wiki/Clang
//
#  define ikCOMP_CLANG ikMAKE_VERSION(__clang_major__,__clang_minor__,__clang_patchlevel__)
#endif // __clang__

#if defined(__COMO__)
//
// Comeau C++ compiler.
// Version number available as major, minor, and patch.
// https://en.wikipedia.org/wiki/Comeau_C/C%2B%2B
//
#  if defined(__COMO_VERSION__)
#    define ikCOMP_COMO ikMAKE_VERSION_0X_VRP(__COMO_VERSION__)
#  else
#    define ikCOMP_COMO ikMAKE_VERSION_DEFAULT
#  endif
#endif // __COMO__

#if defined(__DECC) || defined(__DECCXX)
//
// Compaq C/C++ compiler.
// Version number available as major, minor, and patch.
//
#  if defined(__DECCXX_VER)
#    define ikCOMP_DEC ikMAKE_VERSION_10_VVRR0PP00(__DECCXX_VER)
#  elif defined(__DECC_VER)
#    define ikCOMP_DEC ikMAKE_VERSION_10_VVRR0PP00(__DECC_VER)
#  else
#    define ikCOMP_DEC ikMAKE_VERSION_DEFAULT
#  endif
#endif // __DECC || __DECCXX

#if defined(__DCC__)
//
// Diab C/C++ compiler.
// Version number available as major, minor, and patch. 
//
#  define ikCOMP_DIAB ikMAKE_VERSION_10_VRPP(__VERSION_NUMBER__)
#endif // __DCC__

#if defined(__DMC__)
//
// Digital Mars compiler.
// Version number available as major, minor, and patch. 
// https://en.wikipedia.org/wiki/Digital_Mars
//
#  define ikCOMP_DMC ikMAKE_VERSION_0X_VRP(__DMC__)
#endif // __DMC__

#if defined(__SYSC__)
//
// Dignus Systems/C++ compiler.
// Version number available as major, minor, and patch. 
//
#  define ikCOMP_SYSC ikMAKE_VERSION_10_VRRPP(__SYSC_VER__)
#endif

#if defined(__EDG__)
//
// EDG C++ Frontend compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Edison_Design_Group
//
#  define ikCOMP_EDG ikMAKE_VERSION_10_VRR(__EDG_VERSION__)
#endif // __EDG__

#if defined(__PATHCC__)
//
// EKOpath compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/PathScale
//
#  define ikCOMP_PATH ikMAKE_VERSION(__PATHCC__,__PATHCC_MINOR__,__PATHCC_PATCHLEVEL__)
#endif // __PATHCC__

#if defined(__GNUC__)
//
// Gnu GCC C/C++ compiler.
// Version number available as major, minor, and patch (if available).
// http://en.wikipedia.org/wiki/GNU_Compiler_Collection
//
#  if defined(__GNUC_PATCHLEVEL__)
#    define ikCOMP_GCC ikMAKE_VERSION(__GNUC__,__GNUC_MINOR__,__GNUC_PATCHLEVEL__)
#  else
#    define ikCOMP_GCC ikMAKE_VERSION(__GNUC__,__GNUC_MINOR__,0)
#  endif
#endif // __GNUC__

#if defined(__ghs) || defined(__ghs__)
//
// Green Hills C/C++ compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Green_Hills_Software
//
#  if defined(__GHS_VERSION_NUMBER__)
#    define ikCOMP_GHS ikMAKE_VERSION_10_VRP(__GHS_VERSION_NUMBER__)
#  elif defined(__ghs)
#    define ikCOMP_GHS ikMAKE_VERSION_10_VRP(__ghs)
#  else
#    define ikCOMP_GHS ikMAKE_VERSION_DEFAULT
#  endif
#endif // __ghs || __ghs__

#if defined(__HP_aCC)
// 
// HP aC++ compiler.
// Version number available as major, minor, and patch.
// 
#  if __HP_aCC > 1
#    define ikCOMP_HPACC ikMAKE_VERSION_10_VVRRPP(__HP_aCC)
#  else
#    define ikCOMP_HPACC ikMAKE_VERSION_DEFAULT
#  endif
#endif // __HP_aCC

#if defined(__IAR_SYSTEMS_ICC__)
//
// IAR C/C++ compiler.
// Version number available as major, minor, and patch.
//
#  define ikCOMP_IAR ikMAKE_VERSION_10_VVRR(__VER__)
#endif // __IAR_SYSTEMS_ICC__

#if defined(__IBMCPP__) || defined(__xlC__) || defined(__xlc__)
//
// IBM XL C/C++ compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/VisualAge
// 
#  if defined(__COMPILER_VER__)
#    define ikCOMP_IBM ikMAKE_VERSION_0X_VRRPPPP(__COMPILER_VER__)
#  elif defined(__xlC__)
#    define ikCOMP_IBM ikMAKE_VERSION_0x_VVRR(__xlC__)
#  elif defined(__xlc__)
#    define ikCOMP_IBM ikMAKE_VERSION_0x_VVRR(__xlc__)
#  else
#    define ikCOMP_IBM ikMAKE_VERSION_10_VRP(__IBMCPP__)
#  endif
#endif // __IBMCPP__ || __xlC__ || __xlc__

#if defined(__INTEL_COMPILER) || defined(__ICL) || defined(__ICC) || defined(__ECC)
//
// Intel C/C++ compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Intel_C%2B%2B
//
#  if defined(__INTEL_COMPILER) && (__INTEL_COMPILER == 9999)
#    define ikCOMP_INTEL ikMAKE_VERSION(12,1,0)
#  elif defined(__INTEL_COMPILER) && defined(__INTEL_COMPILER_UPDATE)
#    define ikCOMP_INTEL ikMAKE_VERSION(ikMAKE_VERSION_MAJOR(ikMAKE_VERSION_10_VVRR(__INTEL_COMPILER))\
                                        ikMAKE_VERSION_MINOR(ikMAKE_VERSION_10_VVRR(__INTEL_COMPILER))\
                                        __INTEL_COMPILER_UPDATE)
#  elif defined(__INTEL_COMPILER)
#    define ikCOMP_INTEL ikMAKE_VERSION_10_VVRR(__INTEL_COMPILER)
#  else
#    define ikCOMP_INTEL ikMAKE_VERSION_DEFAULT
#  endif
#endif // __INTEL_COMPILER || __ICL || __ICC || __ECC

#if defined(__KCC)
//
// Kai C++ compiler.
// Version number available as major, minor, and patch. 
//
#  define ikCOMP_KAI ikMAKE_VERSION_0X_VRPP(__KCC_VERSION)
#endif // __KCC

#if defined(__llvm__)
//
// LLVM compiler.
// http://en.wikipedia.org/wiki/LLVM
//
#  define ikCOMP_LLVM ikMAKE_VERSION_DEFAULT
#endif // __llvm__

#if defined(__HIGHC__)
//
// MetaWare High C/C++ compiler.
//
#  define ikCOMP_HIGHC ikMAKE_VERSION_DEFAULT
#endif // __HIGHC__

#if defined(__MWERKS__) || defined(__CWCC__)
//
// Metrowerks CodeWarrior compiler.
// Version number available as major, minor, and patch. 
// http://en.wikipedia.org/wiki/CodeWarrior
//
#  if defined(__CWCC__)
#    define ikCOMP_MWERKS ikMAKE_VERSION_0X_VRPP(__CWCC__)
#  elif (__MWERKS__ >= 0x4200)
#    define ikCOMP_MWERKS ikMAKE_VERSION_0X_VRPP(__MWERKS__)
#  elif (__MWERKS__ >= 0x3204)
#    define ikCOMP_MWERKS ikMAKE_VERSION(9,(__MWERKS__)%100-1,0)
#  elif (__MWERKS__ >= 0x3200)
#    define ikCOMP_MWERKS ikMAKE_VERSION(9,(__MWERKS__)%100,0)
#  elif (__MWERKS__ >= 0x3000)
#    define ikCOMP_MWERKS ikMAKE_VERSION(8,(__MWERKS__)%100,0)
#  else
#    define ikCOMP_MWERKS ikMAKE_VERSION_DEFAULT
#  endif
#endif // __MWERKS__ || __CWCC__

#if defined(_MRI)
//
// Microtec C/C++ compiler.
//
#  define ikCOMP_MRI ikMAKE_VERSION_DEFAULT
#endif // _MRI

#if defined(__MRC__) || defined(MPW_C) || defined(MPW_CPLUS)
//
// MPW C++ compiler.
// Version number available as major, and minor.
// http://en.wikipedia.org/wiki/Macintosh_Programmer%27s_Workshop
//
#  if defined(__MRC__)
#    define ikCOMP_MPW ikMAKE_VERSION_0x_VVRR(__MRC__)
#  else
#    define ikCOMP_MPW ikMAKE_VERSION_DEFAULT
#  endif
#endif // __MRC__ || MPW_C || MPW_CPLUS

#if defined(__NVCC__)
//
// NVCC compiler.
// Version number available as major, minor, and patch beginning with version 7.5.
// https://en.wikipedia.org/wiki/NVIDIA_CUDA_Compiler
//
#  if !defined(__CUDACC_VER_MAJOR__) || !defined(__CUDACC_VER_MINOR__) || !defined(__CUDACC_VER_BUILD__)
#    define ikCOMP_NVCC ikMAKE_VERSION_DEFAULT
#  else
#    define ikCOMP_NVCC ikMAKE_VERSION(__CUDACC_VER_MAJOR__,__CUDACC_VER_MINOR__,__CUDACC_VER_BUILD__)
#  endif
#endif // __NVCC__

#if defined(_PACC_VER)
//
// Palm C/C++ compiler.
// Version number available as major, minor, and patch.
//
#  define ikCOMP_PALM ikMAKE_VERSION_0X_VRRPP000(_PACC_VER)
#endif // _PACC_VER

#if defined(__PGI)
//
// Portland Group C/C++ compiler.
// http://en.wikipedia.org/wiki/The_Portland_Group
//
#  if defined(__PGIC__) && defined(__PGIC_MINOR__) && defined(__PGIC_PATCHLEVEL__)
#    define ikCOMP_PGI ikMAKE_VERSION(__PGIC__,__PGIC_MINOR__,__PGIC_PATCHLEVEL__)
#  else
#    define ikCOMP_PGI ikMAKE_VERSION_DEFAULT
#  endif
#endif // __PGI

#if defined(__sgi) || defined(sgi)
//
// SGI MIPSpro compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/MIPSpro
//
#  if defined(_SGI_COMPILER_VERSION)
#    define ikCOMP_SGI ikMAKE_VERSION_10_VRP(_SGI_COMPILER_VERSION)
#  elif defined(__COMPILER_VERSION)
#    define ikCOMP_SGI ikMAKE_VERSION_0X_VRP(__COMPILER_VERSION)
#  else
#    define ikCOMP_SGI ikMAKE_VERSION_DEFAULT
#  endif
#endif // __sgi || sgi

#if defined(__SUNPRO_CC) || defined(__SUNPRO_C)
//
// Oracle Solaris Studio compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Oracle_Solaris_Studio
//
#  if defined(__SUNPRO_CC)
#    if (__SUNPRO_CC < 0x5100)
#      define ikCOMP_SUNPRO ikMAKE_VERSION_0X_VRP(__SUNPRO_CC)
#    else
#      define ikCOMP_SUNPRO ikMAKE_VERSION_0x_VVRRP(__SUNPRO_CC)
#    endif
#  elif defined(__SUNPRO_C)
#    if (__SUNPRO_CC < 0x5100)
#      define ikCOMP_SUNPRO ikMAKE_VERSION_0X_VRP(__SUNPRO_C)
#    else
#      define ikCOMP_SUNPRO ikMAKE_VERSION_0x_VVRRP(__SUNPRO_C)
#    endif
#  else
#    define ikCOMP_SUNPRO ikMAKE_VERSION_DEFAULT
#  endif
#endif // __SUNPRO_CC || __SUNPRO_C

#if defined(__TenDRA__)
//
// TenDRA C/C++ compiler.
// http://en.wikipedia.org/wiki/TenDRA_Compiler
//
#  define ikCOMP_TENDRA ikMAKE_VERSION_DEFAULT
#endif // __TenDRA__

#if defined(_MSC_VER)
//
// Microsoft Visual C/C++ compiler.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Visual_studio
//
#  if !defined(_MSC_FULL_VER)
#    define _MSC_VER_BUILD 0
#  else
#    if (_MSC_FULL_VER / 10000) == _MSC_VER
#      define _MSC_VER_BUILD (_MSC_FULL_VER % 10000)
#    elif (_MSC_FULL_VER / 100000) == _MSC_VER
#      define _MSC_VER_BUILD (_MSC_FULL_VER % 100000)
#    else
#      error "ikCompiler: Cannot determine build number from _MSC_FULL_VER"
#    endif
#  endif
#  if (_MSC_VER > 1900)
#    define ikCOMP_MSVC ikMAKE_VERSION(_MSC_VER/100,_MSC_VER%100,_MSC_VER_BUILD)
#  elif (_MSC_VER == 1900)
#    define ikCOMP_MSVC ikMAKE_VERSION(_MSC_VER/100-5,_MSC_VER%100,_MSC_VER_BUILD)
#  else
#    define ikCOMP_MSVC ikMAKE_VERSION(_MSC_VER/100-6,_MSC_VER%100,_MSC_VER_BUILD)
#  endif
#endif // _MSC_VER

#if defined(__WATCOMC__)
//
// Watcom C++ compiler.
// Version number available as major, and minor.
// http://en.wikipedia.org/wiki/Watcom
//
#  define ikCOMP_WATCOM ikMAKE_VERSION_10_VVRR(__WATCOMC__)
#endif // __WATCOMC__

#endif // !__ikCore_ikCompiler_Header__
