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

#ifndef __ikCore_ikSystem_Header__
#define __ikCore_ikSystem_Header__ 

//
// Based on Boost.Predef library.
// https://github.com/boostorg/predef
//

#include <ikCore/ikVersion.hpp>

//
// ikOS_XXX macro is defined when XXX operating system is detected.
// Operating systems supported:
//   - ikOS_AIX           -> IBM AIX operating system
//   - ikOS_AMIGAOS       -> AmigaOS operating system
//   - ikOS_ANDROID       -> Android operating system
//   - ikOS_BEOS          -> BeOS operating system
//   - ikOS_BSD_BSDI      -> BSDi BSD/OS operating system
//   - ikOS_BSD_DRAGONFLY -> DragonFly BSD operating system
//   - ikOS_BSD_FREE      -> FreeBSD operating system
//   - ikOS_BSD_NET       -> NetBSD operating system
//   - ikOS_BSD_OPEN      -> OpenBSD operating system
//   - ikOS_BSD           -> BSD operating system
//   - ikOS_CYGWIN        -> Cygwin evironment
//   - ikOS_HAIKU         -> Haiku operating system
//   - ikOS_HPUX          -> HP-UX operating system
//   - ikOS_IOS           -> iOS operating system
//   - ikOS_IRIX          -> IRIX operating system
//   - ikOS_LINUX         -> Linux operating system
//   - ikOS_MACOS         -> Mac OS operating system
//   - ikOS_OS400         -> IBM OS/400 operating system
//   - ikOS_QNX           -> QNX operating system
//   - ikOS_SOLARIS       -> Solaris operating system
//   - ikOS_SVR4          -> SVR4 Environment operating system
//   - ikOS_UNIX          -> Unix Environment operating system
//   - ikOS_VMS           -> VMS operating system
//   - ikOS_WINDOWS       -> Microsoft Windows operating system
//   - ikOS_APPLE         -> Apple operating system
//

#if defined(_AIX) || defined(__TOS_AIX__)
//
// IBM AIX operating system.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/AIX_operating_system
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  if defined(_AIX43)
#    define ikOS_AIX ikMAKE_VERSION(4,3,0)
#  elif defined(_AIX41)
#    define ikOS_AIX ikMAKE_VERSION(4,1,0)
#  elif defined(_AIX32)
#    define ikOS_AIX ikMAKE_VERSION(3,2,0)
#  elif defined(_AIX3)
#    define ikOS_AIX ikMAKE_VERSION(3,0,0)
#  else
#    define ikOS_AIX ikMAKE_VERSION_DEFAULT
#  endif
#endif // _AIX || __TOS_AIX__

#if defined(AMIGA) || defined(__amigaos__)
//
// AmigaOS operating system.
// http://en.wikipedia.org/wiki/AmigaOS
//
#  define ikOS_AMIGAOS ikMAKE_VERSION_DEFAULT
#endif // AMIGA || __amigaos__

#if defined(__ANDROID__)
//
// Android operating system.
// http://en.wikipedia.org/wiki/Android_%28operating_system%29
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_LINUX ikMAKE_VERSION_DEFAULT
#  define ikOS_ANDROID ikMAKE_VERSION_DEFAULT
#endif // __ANDROID__

#if defined(__BEOS__)
//
// BeOS operating system.
// http://en.wikipedia.org/wiki/BeOS
//
#  define ikOS_BEOS ikMAKE_VERSION_DEFAULT
#endif // __BEOS__

#if defined(__bsdi__)
//
// BSDi BSD/OS operating system.
// http://en.wikipedia.org/wiki/BSD/OS
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD_BSDI ikMAKE_VERSION_DEFAULT
#endif // __bsdi__

#if defined(__DragonFly__)
//
// DragonFly BSD operating system.
// http://en.wikipedia.org/wiki/DragonFly_BSD
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD_DRAGONFLY ikMAKE_VERSION_DEFAULT
#endif // __DragonFly__

#if defined(__FreeBSD__)
//
// FreeBSD operating system.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Freebsd
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD ikMAKE_VERSION_DEFAULT
#  include <sys/param.h>
#  if defined(__FreeBSD_version)
#    if __FreeBSD_version == 491000
#      define ikOS_BSD_FREE ikMAKE_VERSION(4, 10, 0)
#    elif __FreeBSD_version == 492000
#       define ikOS_BSD_FREE ikMAKE_VERSION(4, 11, 0)
#    elif __FreeBSD_version < 500000
#       define ikOS_BSD_FREE ikMAKE_VERSION_10_VRPPPP(__FreeBSD_version)
#    else
#       define ikOS_BSD_FREE ikMAKE_VERSION_10_VVRRPPP(__FreeBSD_version)
#    endif
#  else
#    define ikOS_BSD_FREE ikMAKE_VERSION_DEFAULT
#  endif
#endif // __FreeBSD__

#if defined(__NETBSD__) || defined(__NetBSD__)
//
// NetBSD operating system.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Netbsd
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD ikMAKE_VERSION_DEFAULT
#  if defined(__NETBSD__)
#    if defined(__NETBSD_version)
#      if __NETBSD_version < 500000
#        define ikOS_BSD_NET ikMAKE_VERSION_10_VRP000(__NETBSD_version)
#      else
#        define ikOS_BSD_NET ikMAKE_VERSION_10_VRR000(__NETBSD_version)
#      endif
#    endif
#  else
#    if defined(NetBSD0_8)
#      define ikOS_BSD_NET ikMAKE_VERSION(0,8,0)
#    elif defined(NetBSD0_9)
#      define ikOS_BSD_NET ikMAKE_VERSION(0,9,0)
#    elif defined(NetBSD1_0)
#      define ikOS_BSD_NET ikMAKE_VERSION(1,0,0)
#    elif defined(__NetBSD_Version)
#      define ikOS_BSD_NET ikMAKE_VERSION_10_VVRR00PP00(__NetBSD_Version)
#    else
#      define ikOS_BSD_NET ikMAKE_VERSION_DEFAULT
#    endif
#  endif
#endif // __NETBSD__ || __NetBSD__

#if defined(__OpenBSD__)
//
// OpenBSD operating system.
// Version number available as major, minor, and patch.
// http://en.wikipedia.org/wiki/Openbsd
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_BSD ikMAKE_VERSION_DEFAULT
#  if defined(OpenBSD2_0)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,0,0)
#  elif defined(OpenBSD2_1)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,1,0)
#  elif defined(OpenBSD2_2)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,2,0)
#  elif defined(OpenBSD2_3)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,3,0)
#  elif defined(OpenBSD2_4)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,4,0)
#  elif defined(OpenBSD2_5)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,5,0)
#  elif defined(OpenBSD2_6)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,6,0)
#  elif defined(OpenBSD2_7)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,7,0)
#  elif defined(OpenBSD2_8)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,8,0)
#  elif defined(OpenBSD2_9)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(2,9,0)
#  elif defined(OpenBSD3_0)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,0,0)
#  elif defined(OpenBSD3_1)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,1,0)
#  elif defined(OpenBSD3_2)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,2,0)
#  elif defined(OpenBSD3_3)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,3,0)
#  elif defined(OpenBSD3_4)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,4,0)
#  elif defined(OpenBSD3_5)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,5,0)
#  elif defined(OpenBSD3_6)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,6,0)
#  elif defined(OpenBSD3_7)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,7,0)
#  elif defined(OpenBSD3_8)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,8,0)
#  elif defined(OpenBSD3_9)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(3,9,0)
#  elif defined(OpenBSD4_0)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,0,0)
#  elif defined(OpenBSD4_1)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,1,0)
#  elif defined(OpenBSD4_2)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,2,0)
#  elif defined(OpenBSD4_3)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,3,0)
#  elif defined(OpenBSD4_4)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,4,0)
#  elif defined(OpenBSD4_5)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,5,0)
#  elif defined(OpenBSD4_6)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,6,0)
#  elif defined(OpenBSD4_7)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,7,0)
#  elif defined(OpenBSD4_8)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,8,0)
#  elif defined(OpenBSD4_9)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(4,9,0)
#  elif defined(OpenBSD5_0)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,0,0)
#  elif defined(OpenBSD5_1)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,1,0)
#  elif defined(OpenBSD5_2)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,2,0)
#  elif defined(OpenBSD5_3)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,3,0)
#  elif defined(OpenBSD5_4)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,4,0)
#  elif defined(OpenBSD5_5)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,5,0)
#  elif defined(OpenBSD5_6)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,6,0)
#  elif defined(OpenBSD5_7)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,7,0)
#  elif defined(OpenBSD5_8)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,8,0)
#  elif defined(OpenBSD5_9)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(5,9,0)
#  elif defined(OpenBSD6_0)
#    define ikOS_BS__OpenBSD__D_OPEN ikMAKE_VERSION(6,0,0)
#  elif defined(Ope__OpenBSD__nBSD6_1)
#    define ikOS_BS__OpenBSD__D_OPEN ikMAKE_VERSION(6,1,0)
#  elif defined(Ope__OpenBSD__nBSD6_2)
#    define ikOS_BS__OpenBSD__D_OPEN ikMAKE_VERSION(6,2,0)
#  elif defined(Ope__OpenBSD__nBSD6_3)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,3,0)
#  elif defined(OpenBSD6_4)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,4,0)
#  elif defined(OpenBSD6_5)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,5,0)
#  elif defined(OpenBSD6_6)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,6,0)
#  elif defined(OpenBSD6_7)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,7,0)
#  elif defined(OpenBSD6_8)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,8,0)
#  elif defined(OpenBSD6_9)
#    define ikOS_BSD_OPEN ikMAKE_VERSION(6,9,0)
#  endif
#endif // __OpenBSD__

#if !defined(ikOS_BSD)
#  if defined(BSD) || defined(_SYSTYPE_BSD)
//
// BSD operating system.
// http://en.wikipedia.org/wiki/Berkeley_Software_Distribution
//
#    define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#    include <sys/param.h>
#    if defined(BSD4_4)
#      define ikOS_BSD ikMAKE_VERSION(4,4,0)
#    elif defined(BSD4_3)
#      define ikOS_BSD ikMAKE_VERSION(4,3,0)
#    elif defined(BSD4_2)
#      define ikOS_BSD ikMAKE_VERSION(4,2,0)
#    elif defined(BSD)
#      define ikOS_BSD ikMAKE_VERSION_10_VVRR(BSD)
#    else
#      define ikOS_BSD
#    endif
#  endif // BSD || _SYSTYPE_BSD
#endif // !ikOS_BSD

#if defined(__CYGWIN__)
//
// Cygwin evironment.
// http://en.wikipedia.org/wiki/Cygwin
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_CYGWIN ikMAKE_VERSION_DEFAULT
#endif // __CYGWIN__

#if defined(__HAIKU__)
//
// Haiku operating system.
// http://en.wikipedia.org/wiki/Haiku_(operating_system)
//
#  define ikOS_HAIKU ikMAKE_VERSION_DEFAULT
#endif // __HAIKU__

#if defined(hpux) || defined(_hpux) || defined(__hpux)
//
// HP-UX operating system.
// http://en.wikipedia.org/wiki/HP-UX
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_HPUX ikMAKE_VERSION_DEFAULT
#endif // hpux || _hpux || __hpux

#if defined(__APPLE__) && defined(__MACH__) && defined(__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__)
//
// iOS operating system.
// http://en.wikipedia.org/wiki/iOS
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_APPLE ikMAKE_VERSION_DEFAULT
#  define ikOS_IOS (__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__*1000)
#endif // __APPLE__ && __MACH__ && __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__

#if defined(sgi) || defined(__sgi)
//
// IRIX operating system.
// http://en.wikipedia.org/wiki/Irix
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_IRIX ikMAKE_VERSION_DEFAULT
#endif // sgi || _sgi

#if !defined(ikOS_LINUX)
#  if defined(linux) || defined(__linux)
//
// Linux operating system.
// http://en.wikipedia.org/wiki/Linux
//
#    define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#    define ikOS_LINUX ikMAKE_VERSION_DEFAULT
#  endif
#endif // linux || __linux

#if defined(macintosh) || defined(Macintosh) || (defined(__APPLE__) && defined(__MACH__))
//
// Mac OS operating system.
// http://en.wikipedia.org/wiki/Mac_OS
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_APPLE ikMAKE_VERSION_DEFAULT
#  if defined(__APPLE__) && defined(__MACH__)
#    define ikOS_MACOS ikMAKE_VERSION(10,0,0)
#  else
#    define ikOS_MACOS ikMAKE_VERSION(9,0,0)
#  endif
#endif // macintosh || Macintosh || (__APPLE__ && __MACH__)

#if defined(__OS400__)
//
// IBM OS/400 operating system.
// http://en.wikipedia.org/wiki/IBM_i
//
#  define ikOS_OS400 ikMAKE_VERSION_DEFAULT
#endif // __OS400__

#if defined(__QNX__) || defined(__QNXNTO__)
//
// QNX operating system.
// Version number available as major, and minor if possible. And version 4 is specifically detected.
// http://en.wikipedia.org/wiki/QNX
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  if defined(_NTO_VERSION)
#    define ikOS_QNX ikMAKE_VERSION_10_VVRR(_NTO_VERSION)
#  elif defined(__QNX__)
#    define ikOS_QNX ikMAKE_VERSION(4,0,0)
#  else
#    define ikOS_QNX ikMAKE_VERSION_DEFAULT
#  endif
#endif // __QNX__ || __QNXNTO__

#if defined(sun) || defined(__sun)
//
// Solaris operating system.
// http://en.wikipedia.org/wiki/Solaris_Operating_Environment
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_SOLARIS ikMAKE_VERSION_DEFAULT
#endif // sun || __sun

#if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4)
//
// SVR4 Environment operating system.
// http://en.wikipedia.org/wiki/UNIX_System_V
//
#  define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  define ikOS_SVR4 ikMAKE_VERSION_DEFAULT
#endif // __sysv__ || __SVR4 || __svr4__ || _SYSTYPE_SVR4

#if !defined(ikOS_UNIX)
#  if defined(unix) || defined(__unix) || defined(_XOPEN_SOURCE) || defined(_POSIX_SOURCE)
//
// Unix Environment operating system.
// http://en.wikipedia.org/wiki/Unix
//
#    define ikOS_UNIX ikMAKE_VERSION_DEFAULT
#  endif
#endif // unix || __unix || _XOPEN_SOURCE || _POSIX_SOURCE

#if defined(VMS) || defined(__VMS)
//
// VMS operating system.
// http://en.wikipedia.org/wiki/Vms
//
#  if defined(__VMS_VER)
#    define ikOS_VMS ikMAKE_VERSION_10_VVRR00PP00(__VMS_VER)
#  else
#    define ikOS_VMS ikMAKE_VERSION_DEFAULT
#  endif
#endif // VMS || __VMS

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
//
// Microsoft Windows operating system.
// http://en.wikipedia.org/wiki/Category:Microsoft_Windows
//
#  define ikOS_WINDOWS ikMAKE_VERSION_DEFAULT
#endif // _WIN32 || _WIN64 || __WIN32__ || __TOS_WIN__ || __WINDOWS__

#endif // !__ikCore_ikSystem_Header__
