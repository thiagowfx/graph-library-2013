/*
 * File:   msttest.h
 * Author: gdcs
 *
 * Created on Nov 1, 2013, 12:41:01 AM
 */

#ifndef MSTTEST_H
#define	MSTTEST_H

#include <cppunit/extensions/HelperMacros.h>

class msttest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(msttest);

    CPPUNIT_TEST_SUITE_END();

public:
    msttest();
    virtual ~msttest();
    void setUp();
    void tearDown();

private:
    
};

#endif	/* MSTTEST_H */

