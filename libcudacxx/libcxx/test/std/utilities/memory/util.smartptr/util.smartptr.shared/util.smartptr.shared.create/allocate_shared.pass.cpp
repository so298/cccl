//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <memory>

// shared_ptr

// template<class T, class A, class... Args>
//    shared_ptr<T> allocate_shared(const A& a, Args&&... args);

#include <memory>
#include <new>
#include <cstdlib>
#include <cassert>
#include "test_macros.h"
#include "test_allocator.h"
#include "min_allocator.h"

#if TEST_STD_VER >= 2011
#define DELETE_FUNCTION = delete
#else
#define DELETE_FUNCTION
#endif

int new_count = 0;

struct A
{
    static int count;

    A(int i, char c) : int_(i), char_(c) {++count;}
    A(const A& a)
        : int_(a.int_), char_(a.char_)
        {++count;}
    ~A() {--count;}

    int get_int() const {return int_;}
    char get_char() const {return char_;}

    A* operator& () DELETE_FUNCTION;
private:
    int int_;
    char char_;
};

int A::count = 0;

struct Zero
{
    static int count;
    Zero() {++count;}
    Zero(Zero const &) {++count;}
    ~Zero() {--count;}
};

int Zero::count = 0;

struct One
{
    static int count;
    int value;
    explicit One(int v) : value(v) {++count;}
    One(One const & o) : value(o.value) {++count;}
    ~One() {--count;}
};

int One::count = 0;


struct Two
{
    static int count;
    int value;
    Two(int v, int) : value(v) {++count;}
    Two(Two const & o) : value(o.value) {++count;}
    ~Two() {--count;}
};

int Two::count = 0;

struct Three
{
    static int count;
    int value;
    Three(int v, int, int) : value(v) {++count;}
    Three(Three const & o) : value(o.value) {++count;}
    ~Three() {--count;}
};

int Three::count = 0;

template <class Alloc>
void test()
{
    int const bad = -1;
    {
    std::shared_ptr<Zero> p = std::allocate_shared<Zero>(Alloc());
    assert(Zero::count == 1);
    }
    assert(Zero::count == 0);
    {
    int const i = 42;
    std::shared_ptr<One> p = std::allocate_shared<One>(Alloc(), i);
    assert(One::count == 1);
    assert(p->value == i);
    }
    assert(One::count == 0);
    {
    int const i = 42;
    std::shared_ptr<Two> p = std::allocate_shared<Two>(Alloc(), i, bad);
    assert(Two::count == 1);
    assert(p->value == i);
    }
    assert(Two::count == 0);
    {
    int const i = 42;
    std::shared_ptr<Three> p = std::allocate_shared<Three>(Alloc(), i, bad, bad);
    assert(Three::count == 1);
    assert(p->value == i);
    }
    assert(Three::count == 0);
}

int main(int, char**)
{
    test<bare_allocator<void> >();
    test<test_allocator<void> >();

    {
    int i = 67;
    char c = 'e';
    std::shared_ptr<A> p = std::allocate_shared<A>(test_allocator<A>(54), i, c);
    assert(test_allocator<A>::alloc_count == 1);
    assert(A::count == 1);
    assert(p->get_int() == 67);
    assert(p->get_char() == 'e');
    }
    assert(A::count == 0);
    assert(test_allocator<A>::alloc_count == 0);
    {
    int i = 67;
    char c = 'e';
    std::shared_ptr<A> p = std::allocate_shared<A>(min_allocator<void>(), i, c);
    assert(A::count == 1);
    assert(p->get_int() == 67);
    assert(p->get_char() == 'e');
    }
    assert(A::count == 0);
    {
    int i = 68;
    char c = 'f';
    std::shared_ptr<A> p = std::allocate_shared<A>(bare_allocator<void>(), i, c);
    assert(A::count == 1);
    assert(p->get_int() == 68);
    assert(p->get_char() == 'f');
    }
    assert(A::count == 0);

  return 0;
}
