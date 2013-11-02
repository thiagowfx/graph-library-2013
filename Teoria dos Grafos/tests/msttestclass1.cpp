/*
 * File:   msttest.cpp
 * Author: gdcs
 *
 * Created on Nov 1, 2013, 12:41:02 AM
 */

#include "msttest.h"

Graph *G;

CPPUNIT_TEST_SUITE_REGISTRATION(msttest);

msttest::msttest() {
}

msttest::~msttest() {
}

void msttest::setUp() {
    gm = new GraphMatrix(5, true);
    gm->addEdge( 1, 2, 1.0);
    gm->addEdge( 2, 5, 2.0);
    gm->addEdge( 1, 3, 2.0);
    gm->addEdge( 3, 5, 1.0);
    gm->addEdge( 1, 4, 8.0);
    gm->addEdge( 4, 5, 3.0);
}

void msttest::tearDown() {
    delete gm;
}

void msttest::testMst() {
    CPPUNIT_ASSERT_EQUAL(5ULL, gm->getN());
    CPPUNIT_ASSERT( gm->isWeighted() );
    CPPUNIT_ASSERT( !gm->isNegativeWeighted() );
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(1,2));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(1,3));
    CPPUNIT_ASSERT_EQUAL(8.0, gm->getWeight(1,4));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(2,5));
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(3,5));
    CPPUNIT_ASSERT_EQUAL(3.0, gm->getWeight(4,5));
    
    unsigned long long source = 1;
    Mst mst(gm, source);
    CPPUNIT_ASSERT_EQUAL(0.0, di.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(1.0, di.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(2.0, di.getDistance(3));
    CPPUNIT_ASSERT_EQUAL(6.0, di.getDistance(4));
    CPPUNIT_ASSERT_EQUAL(3.0, di.getDistance(5));
    
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(5));        

}

void msttest::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}