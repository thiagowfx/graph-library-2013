/*
 * File:   newtestclass.cpp
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:11
 */

#include "testesbasicostestclass.h"
#include "Utilities.h"

GraphMatrix emptyGm(10, false);
GraphMatrix gm(10, false);
GraphList emptyGl(10, false);
GraphList gl(10, false);
Graph* gEx;

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
    gm = GraphMatrix(10, false);
    gm.addEdge(1, 2);
    gm.addEdge(1, 3);
    gm.addEdge(9, 10);

    gl = GraphList(10, false);
    gl.addEdge(1, 2);
    gl.addEdge(1, 3);
    gl.addEdge(9, 10);

    gEx = new GraphMatrix(5, false);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);
}

void newtestclass::tearDown() {
    delete gEx;
}

void newtestclass::testEmptyGraphMatrix() {
    Graph *g = new GraphMatrix(0, false);
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
    delete g;
}

void newtestclass::testAddEdgesGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL(3ULL, gm.getM());
    CPPUNIT_ASSERT_EQUAL(10ULL, gm.getN());
    CPPUNIT_ASSERT_EQUAL(0.6, gm.getAverDeg());

    CPPUNIT_ASSERT(gm.isEdge(1, 2));
    CPPUNIT_ASSERT(gm.isEdge(2, 1));
    CPPUNIT_ASSERT(gm.isEdge(1, 3));
    CPPUNIT_ASSERT(gm.isEdge(3, 1));
    CPPUNIT_ASSERT(gm.isEdge(9, 10));
    CPPUNIT_ASSERT(gm.isEdge(10, 9));
    CPPUNIT_ASSERT(!gm.isEdge(2, 3));
    CPPUNIT_ASSERT(!gm.isEdge(1, 1));

    CPPUNIT_ASSERT( gEx->isEdge(1, 2) );
    CPPUNIT_ASSERT( gEx->isEdge(2, 5) );
    CPPUNIT_ASSERT( gEx->isEdge(5, 3) );
    CPPUNIT_ASSERT( gEx->isEdge(4, 5) );
    CPPUNIT_ASSERT( gEx->isEdge(1, 5) );

    CPPUNIT_ASSERT(!emptyGm.isEdge(2, 3));
    CPPUNIT_ASSERT(!emptyGm.isEdge(1, 1));

    //CPPUNIT_ASSERT_THROW(gm.isEdge(10, 11), std::exception);
}

void newtestclass::testGetDegreeGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL(2ULL, gm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(9));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(10));
    CPPUNIT_ASSERT_EQUAL(0ULL, gm.getDegree(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, gm.getDegree(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGm.getDegree(10));

    CPPUNIT_ASSERT_THROW(gm.getDegree(11), std::exception);
}

void newtestclass::testGetNeighboursGraphMatrix() {
    std::vector<unsigned long long> v{2, 3};
    CPPUNIT_ASSERT_MESSAGE(
            printVector(v)
            + printVector(gm.getNeighbours(1))
            , compareVectors(gm.getNeighbours(1), v));

    v = {1};
    CPPUNIT_ASSERT_MESSAGE(
            printVector(v)
            + printVector(gm.getNeighbours(2))
            , compareVectors(gm.getNeighbours(2), v));

    v = {10};
    CPPUNIT_ASSERT(compareVectors(gm.getNeighbours(9), v));

    v = std::vector<unsigned long long>();
    CPPUNIT_ASSERT(compareVectors(gm.getNeighbours(5), v));

    //CPPUNIT_ASSERT_THROW(gm.getNeighbours(11), std::exception);
    v = std::vector<unsigned long long>();
    CPPUNIT_ASSERT(compareVectors(gm.getNeighbours(11), v));
}

void newtestclass::testEmptyGraphList() {
    Graph *g = new GraphList(0, false);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de nós", 0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de arestas", 0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
}

void newtestclass::testAddEdgesGraphList() {
    CPPUNIT_ASSERT_EQUAL(3ULL, gl.getM());
    CPPUNIT_ASSERT_EQUAL(10ULL, gl.getN());
    CPPUNIT_ASSERT_EQUAL(0.6, gl.getAverDeg());

    CPPUNIT_ASSERT(gl.isEdge(1, 2));
    CPPUNIT_ASSERT(gl.isEdge(2, 1));
    CPPUNIT_ASSERT(gl.isEdge(1, 3));
    CPPUNIT_ASSERT(gl.isEdge(3, 1));
    CPPUNIT_ASSERT(gl.isEdge(9, 10));
    CPPUNIT_ASSERT(gl.isEdge(10, 9));
    CPPUNIT_ASSERT(!gl.isEdge(2, 3));
    CPPUNIT_ASSERT(!gl.isEdge(1, 1));

    CPPUNIT_ASSERT(!emptyGl.isEdge(2, 3));
    CPPUNIT_ASSERT(!emptyGl.isEdge(1, 1));
}

void newtestclass::testGetDegreeGraphList() {
    CPPUNIT_ASSERT_EQUAL(2ULL, gl.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(9));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(10));
    CPPUNIT_ASSERT_EQUAL(0ULL, gl.getDegree(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, gl.getDegree(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGl.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGl.getDegree(10));

    CPPUNIT_ASSERT_THROW(gl.getDegree(11), std::exception);
}

void newtestclass::testGetNeighboursGraphList() {
    std::vector<unsigned long long> v{2, 3};
    CPPUNIT_ASSERT_MESSAGE(
            printVector(v)
            + printVector(gl.getNeighbours(1))
            , compareVectors(gl.getNeighbours(1), v));

    v = {1};
    CPPUNIT_ASSERT_MESSAGE(
            printVector(v)
            + printVector(gl.getNeighbours(2))
            , compareVectors(gl.getNeighbours(2), v));

    v = {10};
    CPPUNIT_ASSERT(compareVectors(gl.getNeighbours(9), v));

    v = std::vector<unsigned long long>();
    CPPUNIT_ASSERT(compareVectors(gl.getNeighbours(5), v));

    CPPUNIT_ASSERT_THROW(gl.getNeighbours(11), std::exception);
}

void newtestclass::testEmpDist() {
    std::vector<double> v = gEx->getEmpDist();
    std::vector<double> w = {0.0, 0.4, 0.4, 0.0, 0.2};
    CPPUNIT_ASSERT(compareVectors(v, w));
}
