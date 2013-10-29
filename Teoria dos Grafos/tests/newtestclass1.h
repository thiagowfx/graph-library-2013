/*
 * File:   newtestclass1.h
 * Author: thiago
 *
 * Created on Oct 28, 2013, 11:00:06 PM
 */

#ifndef NEWTESTCLASS1_H
#define	NEWTESTCLASS1_H

#include "../Graph.h"
#include "../GraphMatrix.h"
#include "../GraphList.h"

#include <cppunit/extensions/HelperMacros.h>

class newtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass1);

    CPPUNIT_TEST(testBasic);
    CPPUNIT_TEST(testBasic2);
    CPPUNIT_TEST(testBasic3);
    CPPUNIT_TEST(testBasic4);
    CPPUNIT_TEST(testBasic5);
    CPPUNIT_TEST(testBasic6);
    CPPUNIT_TEST(testBasic7);
    CPPUNIT_TEST(testBasic8);
    
    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass1();
    virtual ~newtestclass1();
    void setUp();
    void tearDown();

private:
    // addEdge and getWeight
    void testBasic();
    void testBasic2();
    void testBasic3();
    void testBasic4();
    void testBasic5();
    void testBasic6();
    void testBasic7();
    void testBasic8();
};

#endif	/* NEWTESTCLASS1_H */

