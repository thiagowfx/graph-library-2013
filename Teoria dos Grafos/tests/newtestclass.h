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
    CPPUNIT_TEST(testEmptyGraphMatrix);
    CPPUNIT_TEST(testAddEdgesGraphMatrix);
    CPPUNIT_TEST(testGetDegreeGraphMatrix);
    CPPUNIT_TEST(testGetNeighboursGraphMatrix);
    CPPUNIT_TEST(testEmptyGraphList);
    CPPUNIT_TEST(testAddEdgesGraphList);   
    CPPUNIT_TEST(testGetDegreeGraphList);
    CPPUNIT_TEST(testGetNeighboursGraphList);
    CPPUNIT_TEST(testEmpDist);
    CPPUNIT_TEST(testSaveInfo);
    
    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testEmptyGraphMatrix();
    void testAddEdgesGraphMatrix();
    void testGetDegreeGraphMatrix();
    void testGetNeighboursGraphMatrix();
    void testEmptyGraphList();
    void testAddEdgesGraphList();
    void testGetDegreeGraphList();
    void testGetNeighboursGraphList();
    void testEmpDist();
    void testSaveInfo();
};

#endif	/* NEWTESTCLASS_H */
