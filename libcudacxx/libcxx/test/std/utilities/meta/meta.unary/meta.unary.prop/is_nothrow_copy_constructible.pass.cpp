//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// type_traits

// is_nothrow_copy_constructible

#include <type_traits>
#include "test_macros.h"

template <class T>
void test_is_nothrow_copy_constructible()
{
    static_assert( std::is_nothrow_copy_constructible<T>::value, "");
    static_assert( std::is_nothrow_copy_constructible<const T>::value, "");
#if TEST_STD_VER > 2014
    static_assert( std::is_nothrow_copy_constructible_v<T>, "");
    static_assert( std::is_nothrow_copy_constructible_v<const T>, "");
#endif
}

template <class T>
void test_has_not_nothrow_copy_constructor()
{
    static_assert(!std::is_nothrow_copy_constructible<T>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<const T>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<volatile T>::value, "");
    static_assert(!std::is_nothrow_copy_constructible<const volatile T>::value, "");
#if TEST_STD_VER > 2014
    static_assert(!std::is_nothrow_copy_constructible_v<T>, "");
    static_assert(!std::is_nothrow_copy_constructible_v<const T>, "");
    static_assert(!std::is_nothrow_copy_constructible_v<volatile T>, "");
    static_assert(!std::is_nothrow_copy_constructible_v<const volatile T>, "");
#endif
}

class Empty
{
};

union Union {};

struct bit_zero
{
    int :  0;
};

struct A
{
    A(const A&);
};

int main(int, char**)
{
    test_has_not_nothrow_copy_constructor<void>();
    test_has_not_nothrow_copy_constructor<A>();

    test_is_nothrow_copy_constructible<int&>();
    test_is_nothrow_copy_constructible<Union>();
    test_is_nothrow_copy_constructible<Empty>();
    test_is_nothrow_copy_constructible<int>();
    test_is_nothrow_copy_constructible<double>();
    test_is_nothrow_copy_constructible<int*>();
    test_is_nothrow_copy_constructible<const int*>();
    test_is_nothrow_copy_constructible<bit_zero>();

  return 0;
}
