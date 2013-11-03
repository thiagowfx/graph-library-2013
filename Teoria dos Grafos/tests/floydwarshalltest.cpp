/*
 * File:   floydwarshalltest.cpp
 * Author: gdcs
 *
 * Created on Nov 3, 2013, 1:52:59 AM
 */

#include "floydwarshalltest.h"
#include "FloydWarshall.h"

Graph *gDesc;

CPPUNIT_TEST_SUITE_REGISTRATION(floydwarshalltest);

floydwarshalltest::floydwarshalltest() {
}

floydwarshalltest::~floydwarshalltest() {
}

void floydwarshalltest::setUp() {
    gDesc = new GraphList(5, true);
    gDesc->addEdge(1, 2, 10);
    gDesc->addEdge(2, 3, 1);
    gDesc->addEdge(1, 3, 1);
    gDesc->addEdge(4, 5, 2);
}

void floydwarshalltest::tearDown() {
    delete gDesc;
}

void floydwarshalltest::testFloydWarshall() {
    FloydWarshall fw(gDesc);
    
    CPPUNIT_ASSERT_EQUAL(0.0 , fw.getDistance(1ULL,1ULL));
    CPPUNIT_ASSERT_EQUAL(2.0 , fw.getDistance(2ULL,1ULL));
    CPPUNIT_ASSERT_EQUAL(2.0 , fw.getDistance(1ULL,2ULL));
    CPPUNIT_ASSERT_EQUAL(1.0 , fw.getDistance(1ULL,3ULL));
    CPPUNIT_ASSERT_EQUAL(1.0 , fw.getDistance(2ULL,3ULL));
    CPPUNIT_ASSERT_EQUAL(2.0 , fw.getDistance(4ULL,5ULL));
    
    CPPUNIT_ASSERT_EQUAL(0ULL , fw.getParent(1ULL,1ULL));
    CPPUNIT_ASSERT_EQUAL(0ULL , fw.getParent(5ULL,5ULL));
    CPPUNIT_ASSERT_EQUAL(1ULL , fw.getParent(1ULL,3ULL));
    CPPUNIT_ASSERT_EQUAL(3ULL , fw.getParent(1ULL,2ULL));
    CPPUNIT_ASSERT_EQUAL(0ULL , fw.getParent(1ULL,4ULL));
    CPPUNIT_ASSERT_EQUAL(4ULL , fw.getParent(4ULL,5ULL));
}

void floydwarshalltest::testAverDist() {
  Graph *gm = new GraphMatrix(5, true);
  gm->addEdge(1, 2, 2.0);
  gm->addEdge(2, 3, 2.0);
  gm->addEdge(1, 3, 2.0);
  gm->addEdge(4, 5, 1.0);

  FloydWarshall f(gm);
  CPPUNIT_ASSERT_EQUAL(1.4, f.getAverageDist());

  Graph *gl = new GraphList(3, true);
  gl->addEdge(1, 2, 2.0);
  gl->addEdge(2, 3, 2.0);
  gl->addEdge(1, 3, 2.0);

  FloydWarshall _f(gl);
  CPPUNIT_ASSERT_EQUAL(4.0, _f.getAverageDist());

  delete gl;
  delete gm;
}