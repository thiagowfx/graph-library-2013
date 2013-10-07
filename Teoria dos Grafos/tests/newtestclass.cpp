/*
 * File:   newtestclass.cpp
 * Author: abc116
 *
 * Created on 07/10/2013, 19:03:27
 */

#include "newtestclass.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass::testTest() {
    // CPPUNIT_ASSERT(1 == 2);
    CPPUNIT_ASSERT_EQUAL(1, 1);
}

