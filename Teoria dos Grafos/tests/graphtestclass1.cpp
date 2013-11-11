/*
 * File:   newtestclass.cpp
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:11
 */

#include "graphtestclass1.h"

GraphMatrix emptyGm(10, false);
GraphMatrix gm(10, false);
GraphList emptyGl(10, false);
GraphList gl(10, false);
Graph* gEx;

CPPUNIT_TEST_SUITE_REGISTRATION(graphtestclass1);

graphtestclass1::graphtestclass1() {
}

graphtestclass1::~graphtestclass1() {
}

void graphtestclass1::setUp() {
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

void graphtestclass1::tearDown() {
    delete gEx;
}

void graphtestclass1::testEmptyGraphMatrix() {
    Graph *g = new GraphMatrix(0, false);
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
    delete g;
}

void graphtestclass1::testAddEdgesGraphMatrix() {
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

void graphtestclass1::testGetDegreeGraphMatrix() {
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

void graphtestclass1::testGetNeighboursGraphMatrix() {
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

void graphtestclass1::testEmptyGraphList() {
    Graph *g = new GraphList(0, false);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de nós", 0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de arestas", 0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
}

void graphtestclass1::testAddEdgesGraphList() {
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

void graphtestclass1::testGetDegreeGraphList() {
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

void graphtestclass1::testGetNeighboursGraphList() {
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

void graphtestclass1::testEmpDist() {
    std::vector<double> v = gEx->getEmpDist();
    std::vector<double> w = {0.0, 0.4, 0.4, 0.0, 0.2};
    CPPUNIT_ASSERT(compareVectors(v, w));
}

void graphtestclass1::testGetDist() {
    Graph *gsempeso = new GraphList(3, false);
    gsempeso->addEdge(1, 2);
    gsempeso->addEdge(2, 3);
    CPPUNIT_ASSERT( 1.0 == gsempeso->getDistance(1, 2));
    CPPUNIT_ASSERT( 2.0 == gsempeso->getDistance(1, 3));    
    delete gsempeso;
    
    Graph *gpesopos = new GraphMatrix(3, true);
    gpesopos->addEdge(1, 2, 1.0);
    gpesopos->addEdge(1, 3, 3.0);
    gpesopos->addEdge(2, 3, 1.0);
    CPPUNIT_ASSERT( 1.0 == gpesopos->getDistance(1, 2) );
    CPPUNIT_ASSERT( 2.0 == gpesopos->getDistance(1, 3) );   
    delete gpesopos;
    
    Graph *gpesoneg = new GraphMatrix(3, true);
    gpesoneg->addEdge(1, 2, 1.0);
    gpesoneg->addEdge(2, 3, -1.0);
    gpesoneg->addEdge(1, 3, 2.0);
    CPPUNIT_ASSERT(gpesoneg->isWeighted());
    CPPUNIT_ASSERT(gpesoneg->isNegativeWeighted());
    CPPUNIT_ASSERT_EQUAL(1.0, gpesoneg->getWeight(1,2));
    CPPUNIT_ASSERT_EQUAL(-1.0, gpesoneg->getWeight(2,3));
    CPPUNIT_ASSERT_EQUAL(2.0, gpesoneg->getWeight(1,3));
    CPPUNIT_ASSERT_EQUAL( 0.0,  gpesoneg->getDistance(1, 3));
    delete gpesoneg;
}

void graphtestclass1::testSaveInfo() {
    const char file[] = "tmp/testSaveInfo.txt";
    gEx->saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("# n = 5" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("# m = 5" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("# d_medio = 2.0" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("1 0.40" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("2 0.40" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("3 0.00" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("4 0.20" == s);

    is.close();
}