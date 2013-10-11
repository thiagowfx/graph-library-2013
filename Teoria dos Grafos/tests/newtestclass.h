/*
 * File:   newtestclass.h
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:09
 */

#ifndef NEWTESTCLASS_H
#define	NEWTESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testEmptyGraph);
    CPPUNIT_TEST(testAddEdgesGraphMatrix);
    CPPUNIT_TEST(testGetDegreeGraphMatrix);
    CPPUNIT_TEST(testGetNeighbours);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testEmptyGraph();
    void testAddEdgesGraphMatrix();
    void testGetDegreeGraphMatrix();
    void testGetNeighbours();
};

#endif	/* NEWTESTCLASS_H */

