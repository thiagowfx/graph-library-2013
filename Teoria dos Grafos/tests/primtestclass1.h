/*
 * File:   primtestclass1.h
 * Author: thiago
 *
 * Created on Nov 2, 2013, 6:14:14 PM
 */

#ifndef PRIMTESTCLASS1_H
#define	PRIMTESTCLASS1_H

#include "../Include.h"
#include "../Mst.h"
#include "../Utilities.h"

#include <cppunit/extensions/HelperMacros.h>

class primtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(primtestclass1);

    CPPUNIT_TEST(testMst);
    CPPUNIT_TEST(testMst2);
    CPPUNIT_TEST(testSaveInfo);

    CPPUNIT_TEST_SUITE_END();

public:
    primtestclass1();
    virtual ~primtestclass1();
    void setUp();
    void tearDown();

private:
    void testMst();
    void testMst2();
    void testSaveInfo();
};

#endif	/* PRIMTESTCLASS1_H */

