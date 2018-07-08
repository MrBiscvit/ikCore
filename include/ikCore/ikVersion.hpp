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

#ifndef __ikCore_ikVersion_Header__
#define __ikCore_ikVersion_Header__

//
// Based on Boost.Predef library.
// https://github.com/boostorg/predef
//

#define ikMAKE_VERSION(major,minor,patch) ((((major)%100)*10000000)+(((minor)%100)*100000)+((patch)%100000))
#define ikMAKE_VERSION_MAX ikMAKE_VERSION(99,99,99999)
#define ikMAKE_VERSION_MIN ikMAKE_VERSION(0,0,0)
#define ikMAKE_VERSION_DEFAULT ikMAKE_VERSION(0,0,1)
#define ikMAKE_VERSION_MAJOR(version) (((version)/10000000)%100)
#define ikMAKE_VERSION_MINOR(version) (((version)/100000)%100)
#define ikMAkE_VERSION_PATCH(version) ((version)%100000)

//
// ikCore use the semantic versioning.
// More info at https://semver.org/
//

#define ikVERSION_MAJOR 0
#define ikVERSION_MINOR 1
#define ikVERSION_PATCH 0
#define iKVERSION ikMAKE_VERSION(ikVERSION_MAJOR, ikVERSION_MINOR, ikVERSION_PATCH)
#define ikVERSION_STR "0.1.0-alpha"

//
// Macros to make version from version number formats used by vendors
//

#define ikMAKE_VERSION_0X_VRP(version) ikMAKE_VERSION((version&0xF00)>>8,(version&0xF0)>>4,(version&0xF))
#define ikMAKE_VERSION_0X_VVRP(version) ikMAKE_VERSION((version&0xFF00)>>8,(version&0xF0)>>4,(version&0xF))
#define ikMAKE_VERSION_0X_VRPP(version) ikMAKE_VERSION((version&0xF000)>>12,(version&0xF00)>>8,(version&0xFF))
#define ikMAKE_VERSION_0X_VVRR(version) ikMAKE_VERSION((version&0xFF00)>>8,(version&0xFF),0)
#define ikMAKE_VERSION_0X_VRRPPPP(version) ikMAKE_VERSION((version&0xF000000)>>24,(version&0xFF0000)>>16,(version&0xFFFF))
#define ikMAKE_VERSION_0X_VVRRP(version) ikMAKE_VERSION((version&0xFF000)>>12,(version&0xFF0)>>4,(version&0xF))
#define ikMAKE_VERSION_0X_VRRPP000(version) ikMAKE_VERSION((version&0xF0000000)>>28,(version&0xFF00000)>>20,(version&0xFF000)>>12)
#define ikMAKE_VERSION_0X_VVRRPP(version) ikMAKE_VERSION((version&0xFF0000)>>16,(version&0xFF00)>>8,(version&0xFF))
#define ikMAKE_VERSION_10_VPPP(version) ikMAKE_VERSION(((version)/1000)%10,0,(version)%1000)
#define ikMAKE_VERSION_10_VR0(version) ikMAKE_VERSION(((version)/100)%10,((version)/10)%10,0)
#define ikMAKE_VERSION_10_VRP(version) ikMAKE_VERSION(((version)/100)%10,((version)/10)%10,(version)%10)
#define ikMAKE_VERSION_10_VRP000(version) ikMAKE_VERSION(((version)/100000)%10,((version)/10000)%10,((version)/1000)%10)
#define ikMAKE_VERSION_10_VRPPPP(version) ikMAKE_VERSION(((version)/100000)%10,((version)/10000)%10,(version)%10000)
#define ikMAKE_VERSION_10_VRPP(version) ikMAKE_VERSION(((version)/1000)%10,((version)/100)%10,(version)%100)
#define ikMAKE_VERSION_10_VRR(version) ikMAKE_VERSION(((version)/100)%10,(version)%100,0)
#define ikMAKE_VERSION_10_VRRPP(version) ikMAKE_VERSION(((version)/10000)%10,((version)/100)%100,(version)%100)
#define ikMAKE_VERSION_10_VRR000(version) ikMAKE_VERSION(((version)/100000)%10,((version)/1000)%100,0)
#define ikMAKE_VERSION_10_VV00(version) ikMAKE_VERSION(((version)/100)%100,0,0)
#define ikMAKE_VERSION_10_VVRR(version) ikMAKE_VERSION(((version)/100)%100,(version)%100,0)
#define ikMAKE_VERSION_10_VVRRP(version) ikMAKE_VERSION(((version)/1000)%100,((version)/10)%100,(version)%10)
#define ikMAKE_VERSION_10_VVRRPP(version) ikMAKE_VERSION(((version)/10000)%100,((version)/100)%100,(version)%100)
#define ikMAKE_VERSION_10_VVRRPPP(version) ikMAKE_VERSION(((version)/100000)%100,((version)/1000)%100,(version)%1000)
#define ikMAKE_VERSION_10_VVRR0PP00(version) ikMAKE_VERSION(((version)/10000000)%100,((version)/100000)%100,((version)/100)%100)
#define ikMAKE_VERSION_10_VVRR0PPPP(version) ikMAKE_VERSION(((version)/10000000)%100,((version)/100000)%100,(version)%10000)
#define ikMAKE_VERSION_10_VVRR00PP00(version) ikMAKE_VERSION(((version)/100000000)%100,((version)/1000000)%100,((version)/100)%100)

#define ikMAKE_VERSION_DATE(year,month,day) ikMAKE_VERSION((year)%10000-1970,(month)%100,(day)%100)
#define ikMAKE_VERSION_YYYYMMDD(version) BOOST_PREDEF_MAKE_DATE(((version)/10000)%10000,((version)/100)%100,(version)%100)
#define ikMAKE_VERSION_YYYY(version) BOOST_PREDEF_MAKE_DATE(version,1,1)
#define ikMAKE_VERSION_YYYYMM(version) BOOST_PREDEF_MAKE_DATE((version)/100,(version)%100,1)

#endif // !__ikCore_ikVersion_Header__
