//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// Call erase(const_iterator position) with end()

#if _LIBCUDACXX_DEBUG >= 1

#define _LIBCUDACXX_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <string>
#include <cassert>
#include <cstdlib>
#include <exception>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    std::string l1("123");
    std::string::const_iterator i = l1.end();
    l1.erase(i);
    assert(false);
    }
#if TEST_STD_VER >= 2011
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    S l1("123");
    S::const_iterator i = l1.end();
    l1.erase(i);
    assert(false);
    }
#endif
}

#else

int main(int, char**)
{

  return 0;
}

#endif
