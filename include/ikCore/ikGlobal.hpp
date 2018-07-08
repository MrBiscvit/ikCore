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

#endif // !__ikCore_ikGlobal_Header__
