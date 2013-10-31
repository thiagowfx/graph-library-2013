/*
 * File:   inputhandler_testclass.h
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:51:08 AM
 */

#ifndef INPUTHANDLER_TESTCLASS_H
#define	INPUTHANDLER_TESTCLASS_H

#include "../Include.h"
#include "../InputHandler.h"

#include <cppunit/extensions/HelperMacros.h>

class inputhandler_testclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(inputhandler_testclass);

    CPPUNIT_TEST(testReadGraphMatrix);
    CPPUNIT_TEST(testReadGraphList);

    CPPUNIT_TEST_SUITE_END();

public:
    inputhandler_testclass();
    virtual ~inputhandler_testclass();
    void setUp();
    void tearDown();

private:
    void testReadGraphMatrix();
    void testReadGraphList();
};

#endif	/* INPUTHANDLER_TESTCLASS_H */

