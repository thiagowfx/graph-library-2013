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

class floydwarshalltest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(floydwarshalltest);

    CPPUNIT_TEST(testFloydWarshall);
    CPPUNIT_TEST(testAverDist);

    CPPUNIT_TEST_SUITE_END();

public:
    floydwarshalltest();
    virtual ~floydwarshalltest();
    void setUp();
    void tearDown();

private:
    void testFloydWarshall();
    void testAverDist();
};

#endif	/* FLOYDWARSHALLTEST_H */

