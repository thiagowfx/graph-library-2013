/*
 * File:   heaptestclass1.cpp
 * Author: thiago
 *
 * Created on Nov 3, 2013, 9:05:05 PM
 */

#include "heaptestclass1.h"

CPPUNIT_TEST_SUITE_REGISTRATION(heaptestclass1);

heaptestclass1::heaptestclass1() {
}

heaptestclass1::~heaptestclass1() {
}

void heaptestclass1::setUp() {
}

void heaptestclass1::tearDown() {
}

void heaptestclass1::testHeap() {
    Heap<int> h;
    CPPUNIT_ASSERT(h.empty());

    h.push(50);
    CPPUNIT_ASSERT_EQUAL(50, h.top());

    h.push(40);
    CPPUNIT_ASSERT_EQUAL(40, h.top());
    CPPUNIT_ASSERT(!h.empty());

    h.push(30);
    CPPUNIT_ASSERT_EQUAL(30, h.top());

    h.push(35);
    CPPUNIT_ASSERT_EQUAL(30, h.top());

    h.pop();
    CPPUNIT_ASSERT_EQUAL(35, h.top());

    h.push(40);
    CPPUNIT_ASSERT_EQUAL(35, h.top());

    h.pop();
    CPPUNIT_ASSERT_EQUAL(40, h.top());
    CPPUNIT_ASSERT(!h.empty());

    h.pop();
    CPPUNIT_ASSERT_EQUAL(40, h.top());

    h.pop();
    CPPUNIT_ASSERT_EQUAL(50, h.top());
    CPPUNIT_ASSERT(!h.empty());

    CPPUNIT_ASSERT_EQUAL(1ULL, h.size());

    h.pop();
    CPPUNIT_ASSERT(h.empty());

    CPPUNIT_ASSERT_THROW(h.pop(), std::exception);
    CPPUNIT_ASSERT_THROW(h.top(), std::exception);
}

void heaptestclass1::testHeap2() {
    Heap<double> Q;

    CPPUNIT_ASSERT(Q.empty());

    Q.push(3);
    CPPUNIT_ASSERT_EQUAL(3.0, Q.top());
    Q.push(-1);
    CPPUNIT_ASSERT_EQUAL(-1.0, Q.top());
    Q.pop();
    CPPUNIT_ASSERT_EQUAL(3.0, Q.top());
    Q.push(20);
    Q.push(4);
    Q.push(-2);
    CPPUNIT_ASSERT_EQUAL(-2.0, Q.top());
    CPPUNIT_ASSERT_EQUAL(4ULL, Q.size());
    Q.push(3.14);
    Q.pop();
    CPPUNIT_ASSERT_EQUAL(3.0, Q.top());
    Q.pop();
    CPPUNIT_ASSERT_EQUAL(3.14, Q.top());
}

void heaptestclass1::testHeapWithPair() {
    Heap< std::pair<double, unsigned long long> > h;

    h.push(std::make_pair(4.0, 3ULL));
    CPPUNIT_ASSERT(std::make_pair(4.0, 3ULL) == h.top());

    h.push(std::make_pair(3.0, 3ULL));
    CPPUNIT_ASSERT(std::make_pair(3.0, 3ULL) == h.top());

    h.push(std::make_pair(4.0, 3ULL));
    CPPUNIT_ASSERT(std::make_pair(3.0, 3ULL) == h.top());

    h.push(std::make_pair(3.0, 2ULL));
    CPPUNIT_ASSERT(std::make_pair(3.0, 2ULL) == h.top());

    h.pop();
    CPPUNIT_ASSERT(std::make_pair(3.0, 3ULL) == h.top());
}

void heaptestclass1::testTopReturnAfterPop() {
    Heap<int> h;
    h.push(1);
    CPPUNIT_ASSERT_EQUAL(1, h.top());
    h.push(2);
    CPPUNIT_ASSERT_EQUAL(1, h.top());
    int a = h.top(); // a <- 1
    h.pop();
    CPPUNIT_ASSERT_EQUAL(1, a);
    CPPUNIT_ASSERT_EQUAL(2, h.top());
}