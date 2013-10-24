/*
 * File:   outputinfo_testclass.h
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:37:42 AM
 */

#ifndef OUTPUTINFO_TESTCLASS_H
#define	OUTPUTINFO_TESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class outputinfo_testclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(outputinfo_testclass);

    CPPUNIT_TEST(testSaveInfo);
    
    CPPUNIT_TEST_SUITE_END();

public:
    outputinfo_testclass();
    virtual ~outputinfo_testclass();
    void setUp();
    void tearDown();

private:
    void testSaveInfo();
};

#endif	/* OUTPUTINFO_TESTCLASS_H */

