/*
 * File:   floydwarshalltest.cpp
 * Author: gdcs
 *
 * Created on Nov 3, 2013, 1:52:59 AM
 */

#include "floydwarshalltestclass1.h"

Graph *gDesc;

CPPUNIT_TEST_SUITE_REGISTRATION(floydwarshalltestclass1);

floydwarshalltestclass1::floydwarshalltestclass1() {
}

floydwarshalltestclass1::~floydwarshalltestclass1() {
}

void floydwarshalltestclass1::setUp() {
    gDesc = new GraphList(5, true);
    gDesc->addEdge(1, 2, 10);
    gDesc->addEdge(2, 3, 1);
    gDesc->addEdge(1, 3, 1);
    gDesc->addEdge(4, 5, 2);
}

void floydwarshalltestclass1::tearDown() {
    delete gDesc;
}

void floydwarshalltestclass1::testFloydWarshall() {
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
    CPPUNIT_ASSERT_THROW(fw.getParent(1ULL,4ULL), std::exception);
    CPPUNIT_ASSERT_THROW(fw.getParent(2ULL,5ULL), std::exception);
    CPPUNIT_ASSERT_THROW(fw.getParent(3ULL,4ULL), std::exception);
    CPPUNIT_ASSERT_THROW(fw.getParent(3ULL,5ULL), std::exception);
    CPPUNIT_ASSERT_EQUAL(4ULL , fw.getParent(4ULL,5ULL));
}

void floydwarshalltestclass1::testFWNeg() {
    Graph *gpesoneg = new GraphMatrix(3, true);
    gpesoneg->addEdge(1, 2, 1.0);
    gpesoneg->addEdge(2, 3, -1.0);
    gpesoneg->addEdge(1, 3, 2.0);
    CPPUNIT_ASSERT_EQUAL(3ULL, gpesoneg->getN());
    CPPUNIT_ASSERT(gpesoneg->isWeighted());
    CPPUNIT_ASSERT(gpesoneg->isNegativeWeighted());
    CPPUNIT_ASSERT_EQUAL(1.0, gpesoneg->getWeight(1,2));
    CPPUNIT_ASSERT_EQUAL(-1.0, gpesoneg->getWeight(2,3));
    CPPUNIT_ASSERT_EQUAL(2.0, gpesoneg->getWeight(1,3));
    
    FloydWarshall fw(gpesoneg);
    CPPUNIT_ASSERT_EQUAL(0.0, fw.getDistance(1, 1));
    CPPUNIT_ASSERT_EQUAL(0.0, fw.getDistance(2, 2));
    CPPUNIT_ASSERT_EQUAL(0.0, fw.getDistance(3, 3));
    
    CPPUNIT_ASSERT_EQUAL(-1.0, fw.getDistance(2, 3));
    CPPUNIT_ASSERT_EQUAL(0.0, fw.getDistance(1, 3));
    
    CPPUNIT_ASSERT_EQUAL(-1.0, gpesoneg->getDistance(2, 3));
    CPPUNIT_ASSERT_EQUAL(0.0, gpesoneg->getDistance(1, 3));
    delete gpesoneg;
}

void floydwarshalltestclass1::testAverDist() {
  Graph *gm = new GraphMatrix(5, true);
  gm->addEdge(1, 2, 2.0);
  gm->addEdge(2, 3, 2.0);
  gm->addEdge(1, 3, 2.0);
  gm->addEdge(4, 5, 1.0);

  FloydWarshall f(gm);
  CPPUNIT_ASSERT_EQUAL(0.7, f.getAverageDist());

  Graph *gl = new GraphList(3, true);
  gl->addEdge(1, 2, 2.0);
  gl->addEdge(2, 3, 2.0);
  gl->addEdge(1, 3, 2.0);

  FloydWarshall _f(gl);
  CPPUNIT_ASSERT_EQUAL(2.0, _f.getAverageDist());

  delete gl;
  delete gm;
}

void floydwarshalltestclass1::testFloydWarshallException() {
    Graph *gm = new GraphMatrix(2, true);
    FloydWarshall f(gm);
    CPPUNIT_ASSERT_THROW( f.getDistance(1, 2), std::exception );
    CPPUNIT_ASSERT_THROW( f.getParent(1, 2), std::exception );
    
    delete gm;
}