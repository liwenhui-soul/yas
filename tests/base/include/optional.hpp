
// Copyright (c) 2010-2015 niXman (i dot nixman dog gmail dot com). All
// rights reserved.
//
// This file is part of YAS(https://github.com/niXman/yas) project.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef _yas_test__optional_hpp__included_
#define _yas_test__optional_hpp__included_

/***************************************************************************/

#ifdef __has_include
#	if __has_include(<optional>)
#		include <optional>
#		define _YAS_HAVE_STD_OPTIONAL 1
#	elif __has_include(<experimental/optional>)
#		include <experimental/optional>
#		define _YAS_HAVE_STD_OPTIONAL 1
#		define _YAS_HAVE_STD_EXPERIMENTAL_OPTIONAL
#	else
#		define _YAS_HAVE_STD_OPTIONAL 0
#	endif
#endif

#ifdef _YAS_HAVE_STD_EXPERIMENTAL_OPTIONAL
#	define _YAS_STD_OPTIONAL_NS std::experimental
#else
#	define _YAS_STD_OPTIONAL_NS std
#endif // _YAS_HAVE_STD_EXPERIMENTAL_OPTIONAL

template<typename archive_traits>
bool optional_test(const char* archive_type, const char* io_type) {
	{
		int i0 = 33;
		boost::optional<int> o0(i0), o1;
		typename archive_traits::oarchive oa;
		archive_traits::ocreate(oa, archive_type, io_type);
		oa & o0;

		typename archive_traits::iarchive ia;
		archive_traits::icreate(ia, oa, archive_type, io_type);
		ia & o1;

		if ( o0 != o1 ) {
			std::cout << "OPTIONAL serialization error! [1]" << std::endl;
			return false;
		}
	}
	{
		const std::string s0 = "some string";
		boost::optional<std::string> o0(s0), o1;
		typename archive_traits::oarchive oa;
		archive_traits::ocreate(oa, archive_type, io_type);
		oa & o0;

		typename archive_traits::iarchive ia;
		archive_traits::icreate(ia, oa, archive_type, io_type);
		ia & o1;

		if ( o0 != o1 ) {
			std::cout << "OPTIONAL serialization error! [2]" << std::endl;
			return false;
		}
	}
#if _YAS_HAVE_STD_OPTIONAL
	{
		int i0 = 33;
		_YAS_STD_OPTIONAL_NS::optional<int> o0(i0), o1;
		typename archive_traits::oarchive oa;
		archive_traits::ocreate(oa, archive_type, io_type);
		oa & o0;

		typename archive_traits::iarchive ia;
		archive_traits::icreate(ia, oa, archive_type, io_type);
		ia & o1;

		if ( o0 != o1 ) {
			std::cout << "OPTIONAL serialization error! [3]" << std::endl;
			return false;
		}
	}
	{
		const std::string s0 = "some string";
		_YAS_STD_OPTIONAL_NS::optional<std::string> o0(s0), o1;
		typename archive_traits::oarchive oa;
		archive_traits::ocreate(oa, archive_type, io_type);
		oa & o0;

		typename archive_traits::iarchive ia;
		archive_traits::icreate(ia, oa, archive_type, io_type);
		ia & o1;

		if ( o0 != o1 ) {
			std::cout << "OPTIONAL serialization error! [4]" << std::endl;
			return false;
		}
	}
#endif // _YAS_HAVE_STD_OPTIONAL

	return true;
}

/***************************************************************************/

#undef _YAS_HAVE_STD_OPTIONAL
#undef _YAS_HAVE_STD_EXPERIMENTAL_OPTIONAL
#undef _YAS_STD_OPTIONAL_NS

#endif // _yas_test__optional_hpp__included_
