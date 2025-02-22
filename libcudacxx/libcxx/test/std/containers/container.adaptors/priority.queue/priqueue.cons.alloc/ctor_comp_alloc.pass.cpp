//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <queue>

// template <class Alloc>
//     priority_queue(const Compare& comp, const Alloc& a);

#include <queue>
#include <cassert>

#include "test_macros.h"
#include "test_allocator.h"

template <class T>
struct test
    : public std::priority_queue<T, std::vector<T, test_allocator<T> > >
{
    typedef std::priority_queue<T, std::vector<T, test_allocator<T> > > base;
    typedef typename base::container_type container_type;
    typedef typename base::value_compare value_compare;

    explicit test(const test_allocator<int>& a) : base(a) {}
    test(const value_compare& comp, const test_allocator<int>& a)
        : base(comp, a) {}
    test(const value_compare& comp, const container_type& c,
        const test_allocator<int>& a) : base(comp, c, a) {}
#if TEST_STD_VER >= 2011
    test(const value_compare& comp, container_type&& c,
         const test_allocator<int>& a) : base(comp, std::move(c), a) {}
    test(test&& q, const test_allocator<int>& a) : base(std::move(q), a) {}
#endif
    test_allocator<int> get_allocator() {return c.get_allocator();}

    using base::c;
};

int main(int, char**)
{
    test<int> q(std::less<int>(), test_allocator<int>(3));
    assert(q.c.get_allocator() == test_allocator<int>(3));
    assert(q.c.size() == 0);

  return 0;
}
