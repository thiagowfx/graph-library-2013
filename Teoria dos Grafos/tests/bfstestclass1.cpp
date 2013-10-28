/*
 * File:   bfstestclass1.cpp
 * Author: thiago
 *
 * Created on Oct 28, 2013, 1:42:33 PM
 */

#include "bfstestclass1.h"


CPPUNIT_TEST_SUITE_REGISTRATION(bfstestclass1);

bfstestclass1::bfstestclass1() {
}

bfstestclass1::~bfstestclass1() {
}

void bfstestclass1::setUp() {
}

void bfstestclass1::tearDown() {
}

void bfstestclass1::testMethod() {
    CPPUNIT_ASSERT(true);
}

void bfstestclass1::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

