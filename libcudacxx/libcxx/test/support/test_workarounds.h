// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef SUPPORT_TEST_WORKAROUNDS_H
#define SUPPORT_TEST_WORKAROUNDS_H

#include "test_macros.h"

#if defined(TEST_COMPILER_EDG)
# define TEST_WORKAROUND_EDG_EXPLICIT_CONSTEXPR // VSO#424280
#endif

#if defined(TEST_COMPILER_MSVC)
# define TEST_WORKAROUND_C1XX_BROKEN_IS_TRIVIALLY_COPYABLE // VSO#117743
# ifndef _MSC_EXTENSIONS
#  define TEST_WORKAROUND_C1XX_BROKEN_ZA_CTOR_CHECK // VSO#119998
# endif
#endif

#if defined(TEST_COMPILER_GCC)
# if __GNUC__ < 9
#  define TEST_WORKAROUND_CONSTEXPR_IMPLIES_NOEXCEPT // GCC PR 87603
# endif
#endif

#endif // SUPPORT_TEST_WORKAROUNDS_H
