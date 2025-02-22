//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// WARNING: This test was generated by generate_feature_test_macro_components.py
// and should not be edited manually.

// <exception>

// Test the feature test macros defined by <exception>

/*  Constant                         Value
    __cpp_lib_uncaught_exceptions    201411L [C++17]
*/

#include <exception>
#include "test_macros.h"

#if TEST_STD_VER < 2014

# ifdef __cpp_lib_uncaught_exceptions
#   error "__cpp_lib_uncaught_exceptions should not be defined before c++17"
# endif

#elif TEST_STD_VER == 2014

# ifdef __cpp_lib_uncaught_exceptions
#   error "__cpp_lib_uncaught_exceptions should not be defined before c++17"
# endif

#elif TEST_STD_VER == 2017

# ifndef __cpp_lib_uncaught_exceptions
#   error "__cpp_lib_uncaught_exceptions should be defined in c++17"
# endif
# if __cpp_lib_uncaught_exceptions != 201411L
#   error "__cpp_lib_uncaught_exceptions should have the value 201411L in c++17"
# endif

#elif TEST_STD_VER > 2017

# ifndef __cpp_lib_uncaught_exceptions
#   error "__cpp_lib_uncaught_exceptions should be defined in c++2a"
# endif
# if __cpp_lib_uncaught_exceptions != 201411L
#   error "__cpp_lib_uncaught_exceptions should have the value 201411L in c++2a"
# endif

#endif // TEST_STD_VER > 2017

int main(int, char**) { return 0; }
