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

#ifndef __ikCore_ikGlobal_Header__
#define __ikCore_ikGlobal_Header__

#include <ikCore/ikVersion.hpp>
#include <ikCore/ikCompiler.hpp>

#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <cstdarg>
#include <cstdalign>

//
// Some typedefs
//

#if defined(ikCOMP_MSVC)
typedef signed __int8 ikInt8;
typedef signed __int16 ikInt16;
typedef signed __int32 ikInt32;
typedef signed __int64 ikInt64;
typedef unsigned __int8 ikUInt8;
typedef unsigned __int16 ikUInt16;
typedef unsigned __int32 ikUInt32;
typedef unsigned __int64 ikUInt64;
#else
typedef signed char ikInt8;
typedef signed short ikInt16;
typedef signed int ikInt32;
typedef signed long long ikInt64;
typedef unsigned char ikUInt8;
typedef unsigned short ikUInt16;
typedef unsigned int ikUInt32;
typedef unsigned long long ikUInt64;
#endif

typedef bool ikBoolean;
typedef bool ikBit;

typedef ikInt8 ikByte;
typedef ikUInt8 ikUByte;

template<int Size> struct ikIntegerForSize {};
template<> struct ikIntegerForSize<1> { typedef ikInt8 Signed; typedef ikUInt8 Unsigned; };
template<> struct ikIntegerForSize<2> { typedef ikInt16 Signed; typedef ikUInt16 Unsigned; };
template<> struct ikIntegerForSize<4> { typedef ikInt32 Signed; typedef ikUInt32 Unsigned; };
template<> struct ikIntegerForSize<8> { typedef ikInt64 Signed; typedef ikUInt64 Unsigned; };
template<typename T> struct ikIntegerForSizeof : public ikIntegerForSize<sizeof(T)> {};

typedef ikIntegerForSizeof<void*>::Signed ikIntPtr;
typedef ikIntegerForSizeof<void*>::Unsigned ikUIntPtr;

//
// Debug configuration detection
//

#if !defined(ikDEBUG) && !defined(ikNDEBUG)
#  if defined(_DEBUG) || !defined(NDEBUG)
#    define ikDEBUG
#    undef ikNDEBUG
#  else
#    define ikNDEBUG
#    undef ikDEBUG
#  endif
#endif

//
// Assert
//

void ikcore_assert_function(const char* test, const char* file, int line);
void ikcore_assert_function(const char* where, const char* what, const char* file, int line);

#if defined(ikDEBUG) || defined(ikFORCE_ASSERTS)
#  define ikASSERT(test) ((test) ? static_cast<void>(false) : ikcore_assert_function(#test,__FILE__,__LINE__))
#  define ikASSERT_X(test,where,what) ((test) ? static_cast<void>(false) : ikcore_assert_function(where,what,__FILE__,__LINE__))
#else
#  define ikASSERT(test) static_cast<void>(false && (test))
#  define ikASSERT_X(test,where,what) static_cast<void>(false && (test))
#endif

#endif // !__ikCore_ikGlobal_Header__
