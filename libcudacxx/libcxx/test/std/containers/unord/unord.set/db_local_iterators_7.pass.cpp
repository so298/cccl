//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <unordered_set>

// Increment local_iterator past end.

#if _LIBCUDACXX_DEBUG >= 1

#define _LIBCUDACXX_ASSERT(x, m) ((x) ? (void)0 : std::exit(0))

#include <unordered_set>
#include <cassert>
#include <iterator>
#include <exception>
#include <cstdlib>

#include "test_macros.h"
#include "min_allocator.h"

int main(int, char**)
{
    {
    typedef int T;
    typedef std::unordered_set<T> C;
    C c(1);
    C::local_iterator i = c.begin(0);
    ++i;
    ++i;
    assert(false);
    }
#if TEST_STD_VER >= 2011
    {
    typedef int T;
    typedef std::unordered_set<T, std::hash<T>, std::equal_to<T>, min_allocator<T>> C;
    C c(1);
    C::local_iterator i = c.begin(0);
    ++i;
    ++i;
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
