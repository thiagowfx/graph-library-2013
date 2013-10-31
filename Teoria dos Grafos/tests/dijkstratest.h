/*
 * File:   dijkstratest.h
 * Author: abc116
 *
 * Created on 30/10/2013, 16:42:22
 */

#ifndef DIJKSTRATEST_H
#define	DIJKSTRATEST_H

#include "../Include.h"

#include <cppunit/extensions/HelperMacros.h>

class dijkstratest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(dijkstratest);

    CPPUNIT_TEST(testMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    dijkstratest();
    virtual ~dijkstratest();
    void setUp();
    void tearDown();

private:
    void testMethod();
};

#endif	/* DIJKSTRATEST_H */

