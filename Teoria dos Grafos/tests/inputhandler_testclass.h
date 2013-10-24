/*
 * File:   inputhandler_testclass.h
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:51:08 AM
 */

#ifndef INPUTHANDLER_TESTCLASS_H
#define	INPUTHANDLER_TESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class inputhandler_testclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(inputhandler_testclass);

    CPPUNIT_TEST(testReadGraph);
    
    CPPUNIT_TEST_SUITE_END();

public:
    inputhandler_testclass();
    virtual ~inputhandler_testclass();
    void setUp();
    void tearDown();

private:
    void testReadGraph();
};

#endif	/* INPUTHANDLER_TESTCLASS_H */
