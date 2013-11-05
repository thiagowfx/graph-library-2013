/*
 * File:   floydwarshalltest.h
 * Author: gdcs
 *
 * Created on Nov 3, 2013, 1:52:59 AM
 */

#ifndef FLOYDWARSHALLTEST_H
#define	FLOYDWARSHALLTEST_H

#include "../Include.h"
#include "../FloydWarshall.h"

#include <cppunit/extensions/HelperMacros.h>

class floydwarshalltestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(floydwarshalltestclass1);

    CPPUNIT_TEST(testFloydWarshall);
    CPPUNIT_TEST(testFWNeg);
    CPPUNIT_TEST(testAverDist);
    CPPUNIT_TEST(testFloydWarshallException);

    CPPUNIT_TEST_SUITE_END();

public:
    floydwarshalltestclass1();
    virtual ~floydwarshalltestclass1();
    void setUp();
    void tearDown();

private:
    void testFloydWarshall();
    void testFWNeg();
    void testAverDist();
    void testFloydWarshallException();
};

#endif	/* FLOYDWARSHALLTEST_H */

