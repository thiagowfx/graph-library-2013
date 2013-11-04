/*
 * File:   heaptestclass1.h
 * Author: thiago
 *
 * Created on Nov 3, 2013, 9:05:05 PM
 */

#ifndef HEAPTESTCLASS1_H
#define	HEAPTESTCLASS1_H

#include "../Heap.h"

#include <cppunit/extensions/HelperMacros.h>

class heaptestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(heaptestclass1);

    CPPUNIT_TEST(testHeap);
    CPPUNIT_TEST(testHeap2);
    CPPUNIT_TEST(testHeapWithPair);

    CPPUNIT_TEST_SUITE_END();

public:
    heaptestclass1();
    virtual ~heaptestclass1();
    void setUp();
    void tearDown();

private:
    void testHeap();
    void testHeap2();
    void testHeapWithPair();
};

#endif	/* HEAPTESTCLASS1_H */

