//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// Add to iterator out of bounds.

#if _LIBCUDACXX_DEBUG >= 1

#define _LIBCUDACXX_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <string>
#include <cassert>
#include <iterator>
#include <exception>
#include <cstdlib>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    typedef std::string C;
    C c(1, '\0');
    C::iterator i = c.begin();
    i += 1;
    assert(i == c.end());
    i = c.begin();
    i += 2;
    assert(false);
    }
#if TEST_STD_VER >= 2011
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> C;
    C c(1, '\0');
    C::iterator i = c.begin();
    i += 1;
    assert(i == c.end());
    i = c.begin();
    i += 2;
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
