/*
 * File:   newtestclass.cpp
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:11
 */

#include "newtestclass.h"
#include "Graph.h"
#include "GraphMatrix.h"

GraphMatrix emptyGm(10);
GraphMatrix gm(10);

template <class T>
bool compareVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    if ( v1.size() != v2.size() )
        return false;
    
    for (int i = 0; i < (int) v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
    gm = GraphMatrix(10);
    gm.addEdge(1,2);
    gm.addEdge(1,3);
    gm.addEdge(9,10);
}

void newtestclass::tearDown() {
}

void newtestclass::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass::testEmptyGraph() {
    Graph g;
    CPPUNIT_ASSERT_EQUAL( 0ULL, g.getN());
    CPPUNIT_ASSERT_EQUAL( 0ULL, g.getM());
    CPPUNIT_ASSERT_EQUAL( 0.0, g.getAverDeg());
}

void newtestclass::testAddEdgesGraphMatrix() {    
    CPPUNIT_ASSERT( gm.isEdge(1,2) );
    CPPUNIT_ASSERT( gm.isEdge(1,3) );
    CPPUNIT_ASSERT( gm.isEdge(9,10) );
    CPPUNIT_ASSERT( !gm.isEdge(2,3) );
    CPPUNIT_ASSERT( !gm.isEdge(1,1) );
    
    CPPUNIT_ASSERT( !emptyGm.isEdge(2,3) );
    CPPUNIT_ASSERT( !emptyGm.isEdge(1,1) );
}

void newtestclass::testGetDegreeGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL( 2ULL, gm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(2));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(3));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(9));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(10));
    CPPUNIT_ASSERT_EQUAL( 0ULL, gm.getDegree(4));
    CPPUNIT_ASSERT_EQUAL( 0ULL, gm.getDegree(5));
    
    CPPUNIT_ASSERT_EQUAL( 0ULL, emptyGm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL( 0ULL, emptyGm.getDegree(10));
}
