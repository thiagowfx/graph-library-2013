/*
 * File:   dijkstratest.cpp
 * Author: abc116
 *
 * Created on 30/10/2013, 16:42:23
 */

#include "dijkstratest.h"

#include "../Dijkstra.h"

Graph *gm;
Graph *gl;

CPPUNIT_TEST_SUITE_REGISTRATION(dijkstratest);

dijkstratest::dijkstratest() {
}

dijkstratest::~dijkstratest() {
}

void dijkstratest::setUp() {
    gm = new GraphMatrix(5, true);
    gm->addEdge( 1, 2, 1.0);
    gm->addEdge( 2, 5, 2.0);
    gm->addEdge( 1, 3, 2.0);
    gm->addEdge( 3, 5, 1.0);
    gm->addEdge( 1, 4, 8.0);
    gm->addEdge( 4, 5, 3.0);
}

void dijkstratest::tearDown() {
    delete gm;
}

void dijkstratest::testMethod() {
    CPPUNIT_ASSERT_EQUAL(5ULL, gm->getN());
    CPPUNIT_ASSERT( gm->isWeighted() );
    CPPUNIT_ASSERT( !gm->isNegativeWeighted() );
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(1,2));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(1,3));
    CPPUNIT_ASSERT_EQUAL(8.0, gm->getWeight(1,4));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(2,5));
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(3,5));
    CPPUNIT_ASSERT_EQUAL(3.0, gm->getWeight(4,5));
    
    unsigned long long source;
    source = 1;
    Dijkstra di(gm, source);
    CPPUNIT_ASSERT_EQUAL(0.0, di.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(1.0, di.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(2.0, di.getDistance(3));
    CPPUNIT_ASSERT_EQUAL(6.0, di.getDistance(4));
    CPPUNIT_ASSERT_EQUAL(3.0, di.getDistance(5));
}

