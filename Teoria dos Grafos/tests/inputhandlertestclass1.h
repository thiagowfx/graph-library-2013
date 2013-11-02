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
#include "../Utilities.h"

#include <cppunit/extensions/HelperMacros.h>

class inputhandlertestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(inputhandlertestclass1);

    CPPUNIT_TEST(testReadGraphMatrix);
    CPPUNIT_TEST(testReadGraphList);
    CPPUNIT_TEST(testReadGraphMatrixWeighted);
    CPPUNIT_TEST(testReadGraphListWeighted);
    CPPUNIT_TEST(testRemoveDuplicates);
    

    CPPUNIT_TEST_SUITE_END();

public:
    inputhandlertestclass1();
    virtual ~inputhandlertestclass1();
    void setUp();
    void tearDown();

private:
    void testReadGraphMatrix();
    void testReadGraphList();
    void testReadGraphMatrixWeighted();
    void testReadGraphListWeighted();
    void testRemoveDuplicates();
};

#endif	/* INPUTHANDLER_TESTCLASS_H */

