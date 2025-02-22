//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// UNSUPPORTED: libcpp-has-no-threads

// <thread>

// template <class T>
// struct hash
// {
//     size_t operator()(T val) const;
// };

// Not very portable

#include <thread>
#include <cassert>

#include "test_macros.h"

int main(int, char**)
{
    std::thread::id id1;
    std::thread::id id2 = std::this_thread::get_id();
    typedef std::hash<std::thread::id> H;
#if TEST_STD_VER <= 2014
    static_assert((std::is_same<typename H::argument_type, std::thread::id>::value), "" );
    static_assert((std::is_same<typename H::result_type, std::size_t>::value), "" );
#endif
    ASSERT_NOEXCEPT(H()(id2));
    H h;
    assert(h(id1) != h(id2));

  return 0;
}
