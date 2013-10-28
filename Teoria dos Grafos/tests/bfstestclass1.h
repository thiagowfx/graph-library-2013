/*
 * File:   bfstestclass1.h
 * Author: thiago
 *
 * Created on Oct 28, 2013, 1:42:33 PM
 */

#ifndef BFSTESTCLASS1_H
#define	BFSTESTCLASS1_H

#include <cppunit/extensions/HelperMacros.h>

class bfstestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(bfstestclass1);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    bfstestclass1();
    virtual ~bfstestclass1();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* BFSTESTCLASS1_H */

