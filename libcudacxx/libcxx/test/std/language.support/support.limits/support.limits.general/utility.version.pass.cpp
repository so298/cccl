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

// <utility>

// Test the feature test macros defined by <utility>

/*  Constant                       Value
    __cpp_lib_as_const             201510L [C++17]
    __cpp_lib_constexpr_misc       201811L [C++2a]
    __cpp_lib_exchange_function    201304L [C++14]
    __cpp_lib_integer_sequence     201304L [C++14]
    __cpp_lib_to_chars             201611L [C++17]
    __cpp_lib_tuples_by_type       201304L [C++14]
*/

#include <utility>
#include "test_macros.h"

#if TEST_STD_VER < 2014

# ifdef __cpp_lib_as_const
#   error "__cpp_lib_as_const should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifdef __cpp_lib_exchange_function
#   error "__cpp_lib_exchange_function should not be defined before c++14"
# endif

# ifdef __cpp_lib_integer_sequence
#   error "__cpp_lib_integer_sequence should not be defined before c++14"
# endif

# ifdef __cpp_lib_to_chars
#   error "__cpp_lib_to_chars should not be defined before c++17"
# endif

# ifdef __cpp_lib_tuples_by_type
#   error "__cpp_lib_tuples_by_type should not be defined before c++14"
# endif

#elif TEST_STD_VER == 2014

# ifdef __cpp_lib_as_const
#   error "__cpp_lib_as_const should not be defined before c++17"
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifndef __cpp_lib_exchange_function
#   error "__cpp_lib_exchange_function should be defined in c++14"
# endif
# if __cpp_lib_exchange_function != 201304L
#   error "__cpp_lib_exchange_function should have the value 201304L in c++14"
# endif

# ifndef __cpp_lib_integer_sequence
#   error "__cpp_lib_integer_sequence should be defined in c++14"
# endif
# if __cpp_lib_integer_sequence != 201304L
#   error "__cpp_lib_integer_sequence should have the value 201304L in c++14"
# endif

# ifdef __cpp_lib_to_chars
#   error "__cpp_lib_to_chars should not be defined before c++17"
# endif

# ifndef __cpp_lib_tuples_by_type
#   error "__cpp_lib_tuples_by_type should be defined in c++14"
# endif
# if __cpp_lib_tuples_by_type != 201304L
#   error "__cpp_lib_tuples_by_type should have the value 201304L in c++14"
# endif

#elif TEST_STD_VER == 2017

# ifndef __cpp_lib_as_const
#   error "__cpp_lib_as_const should be defined in c++17"
# endif
# if __cpp_lib_as_const != 201510L
#   error "__cpp_lib_as_const should have the value 201510L in c++17"
# endif

# ifdef __cpp_lib_constexpr_misc
#   error "__cpp_lib_constexpr_misc should not be defined before c++2a"
# endif

# ifndef __cpp_lib_exchange_function
#   error "__cpp_lib_exchange_function should be defined in c++17"
# endif
# if __cpp_lib_exchange_function != 201304L
#   error "__cpp_lib_exchange_function should have the value 201304L in c++17"
# endif

# ifndef __cpp_lib_integer_sequence
#   error "__cpp_lib_integer_sequence should be defined in c++17"
# endif
# if __cpp_lib_integer_sequence != 201304L
#   error "__cpp_lib_integer_sequence should have the value 201304L in c++17"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_to_chars
#     error "__cpp_lib_to_chars should be defined in c++17"
#   endif
#   if __cpp_lib_to_chars != 201611L
#     error "__cpp_lib_to_chars should have the value 201611L in c++17"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_to_chars
#     error "__cpp_lib_to_chars should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_tuples_by_type
#   error "__cpp_lib_tuples_by_type should be defined in c++17"
# endif
# if __cpp_lib_tuples_by_type != 201304L
#   error "__cpp_lib_tuples_by_type should have the value 201304L in c++17"
# endif

#elif TEST_STD_VER > 2017

# ifndef __cpp_lib_as_const
#   error "__cpp_lib_as_const should be defined in c++2a"
# endif
# if __cpp_lib_as_const != 201510L
#   error "__cpp_lib_as_const should have the value 201510L in c++2a"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_constexpr_misc
#     error "__cpp_lib_constexpr_misc should be defined in c++2a"
#   endif
#   if __cpp_lib_constexpr_misc != 201811L
#     error "__cpp_lib_constexpr_misc should have the value 201811L in c++2a"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_constexpr_misc
#     error "__cpp_lib_constexpr_misc should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_exchange_function
#   error "__cpp_lib_exchange_function should be defined in c++2a"
# endif
# if __cpp_lib_exchange_function != 201304L
#   error "__cpp_lib_exchange_function should have the value 201304L in c++2a"
# endif

# ifndef __cpp_lib_integer_sequence
#   error "__cpp_lib_integer_sequence should be defined in c++2a"
# endif
# if __cpp_lib_integer_sequence != 201304L
#   error "__cpp_lib_integer_sequence should have the value 201304L in c++2a"
# endif

# if !defined(_LIBCUDACXX_VERSION)
#   ifndef __cpp_lib_to_chars
#     error "__cpp_lib_to_chars should be defined in c++2a"
#   endif
#   if __cpp_lib_to_chars != 201611L
#     error "__cpp_lib_to_chars should have the value 201611L in c++2a"
#   endif
# else // _LIBCUDACXX_VERSION
#   ifdef __cpp_lib_to_chars
#     error "__cpp_lib_to_chars should not be defined because it is unimplemented in libc++!"
#   endif
# endif

# ifndef __cpp_lib_tuples_by_type
#   error "__cpp_lib_tuples_by_type should be defined in c++2a"
# endif
# if __cpp_lib_tuples_by_type != 201304L
#   error "__cpp_lib_tuples_by_type should have the value 201304L in c++2a"
# endif

#endif // TEST_STD_VER > 2017

int main(int, char**) { return 0; }
