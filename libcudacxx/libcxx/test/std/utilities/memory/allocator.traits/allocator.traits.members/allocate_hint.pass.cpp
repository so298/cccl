//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// template <class Alloc>
// struct allocator_traits
// {
//     static pointer allocate(allocator_type& a, size_type n, const_void_pointer hint);
//     ...
// };

#include <memory>
#include <cstdint>
#include <cassert>

#include "test_macros.h"
#include "incomplete_type_helper.h"

template <class T>
struct A
{
    typedef T value_type;

    value_type* allocate(std::size_t n)
    {
        assert(n == 10);
        return reinterpret_cast<value_type*>(static_cast<std::uintptr_t>(0xDEADBEEF));
    }
};

template <class T>
struct B
{
    typedef T value_type;

    value_type* allocate(std::size_t n)
    {
        assert(n == 12);
        return reinterpret_cast<value_type*>(static_cast<std::uintptr_t>(0xEEADBEEF));
    }
    value_type* allocate(std::size_t n, const void* p)
    {
        assert(n == 11);
        assert(p == 0);
        return reinterpret_cast<value_type*>(static_cast<std::uintptr_t>(0xFEADBEEF));
    }
};


int main(int, char**)
{
#if TEST_STD_VER >= 2011
  {
    A<int> a;
    assert(std::allocator_traits<A<int> >::allocate(a, 10, nullptr) == reinterpret_cast<int*>(static_cast<std::uintptr_t>(0xDEADBEEF)));
  }
  {
    typedef IncompleteHolder* VT;
    typedef A<VT> Alloc;
    Alloc a;
    assert(std::allocator_traits<Alloc >::allocate(a, 10, nullptr) == reinterpret_cast<VT*>(static_cast<std::uintptr_t>(0xDEADBEEF)));
  }
#endif
  {
    B<int> b;
    assert(std::allocator_traits<B<int> >::allocate(b, 11, nullptr) == reinterpret_cast<int*>(static_cast<std::uintptr_t>(0xFEADBEEF)));
  }
  {
    typedef IncompleteHolder* VT;
    typedef B<VT> Alloc;
    Alloc b;
    assert(std::allocator_traits<Alloc >::allocate(b, 11, nullptr) == reinterpret_cast<VT*>(static_cast<std::uintptr_t>(0xFEADBEEF)));
  }

  return 0;
}
