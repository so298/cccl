//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11
// UNSUPPORTED: msvc-19.16

// Throwing bad_variant_access is supported starting in macosx10.13
// XFAIL: use_system_cxx_lib && target={{.+}}-apple-macosx10.{{9|10|11|12}} && !no-exceptions

// <cuda/std/variant>
// template <class R, class Visitor, class... Variants>
// constexpr R visit(Visitor&& vis, Variants&&... vars);

#include <cuda/std/cassert>
// #include <cuda/std/memory>
// #include <cuda/std/string>
#include <cuda/std/type_traits>
#include <cuda/std/utility>
#include <cuda/std/variant>

#include "test_macros.h"
#include "variant_test_helpers.h"

// See https://bugs.llvm.org/show_bug.cgi?id=31916
struct A {};
template<class ReturnType>
struct Visitor {
  __host__ __device__
  auto operator()(A&) {
      return ReturnType{};
  }
};
template<>
struct Visitor<void> {
  __host__ __device__
  void operator()(A&) {}
};

template <typename ReturnType>
__host__ __device__
void test_caller_accepts_nonconst() {
  cuda::std::variant<A> v;
  cuda::std::visit<ReturnType>(Visitor<ReturnType>{}, v);
}

int main(int, char**) {
  test_caller_accepts_nonconst<void>();
  test_caller_accepts_nonconst<int>();

  return 0;
}
