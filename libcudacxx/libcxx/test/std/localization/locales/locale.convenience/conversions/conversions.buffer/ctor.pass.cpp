//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <locale>

// wbuffer_convert<Codecvt, Elem, Tr>

// wbuffer_convert(streambuf *bytebuf = 0, Codecvt *pcvt = new Codecvt,
//                 state_type state = state_type());

#include <locale>
#include <codecvt>
#include <sstream>
#include <cassert>

#include "test_macros.h"
#include "count_new.h"

int main(int, char**)
{
    typedef std::wbuffer_convert<std::codecvt_utf8<wchar_t> > B;
#if TEST_STD_VER > 2011
    static_assert(!std::is_convertible<std::streambuf*, B>::value, "");
    static_assert( std::is_constructible<B, std::streambuf*>::value, "");
#endif
    {
        B b;
        assert(b.rdbuf() == nullptr);
        assert(globalMemCounter.checkOutstandingNewNotEq(0));
    }
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
        std::stringstream s;
        B b(s.rdbuf());
        assert(b.rdbuf() == s.rdbuf());
        assert(globalMemCounter.checkOutstandingNewNotEq(0));
    }
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
        std::stringstream s;
        B b(s.rdbuf(), new std::codecvt_utf8<wchar_t>);
        assert(b.rdbuf() == s.rdbuf());
        assert(globalMemCounter.checkOutstandingNewNotEq(0));
    }
    assert(globalMemCounter.checkOutstandingNewEq(0));
    {
        std::stringstream s;
        B b(s.rdbuf(), new std::codecvt_utf8<wchar_t>, std::mbstate_t());
        assert(b.rdbuf() == s.rdbuf());
        assert(globalMemCounter.checkOutstandingNewNotEq(0));
    }
    assert(globalMemCounter.checkOutstandingNewEq(0));

  return 0;
}
