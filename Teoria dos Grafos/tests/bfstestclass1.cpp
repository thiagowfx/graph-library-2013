/*
 * File:   bfstestclass1.cpp
 * Author: thiago
 *
 * Created on Oct 28, 2013, 1:42:33 PM
 */

#include "bfstestclass1.h"

Graph* gEx;
// K3 e K2
Graph* gDe;
// K2 = 1 aresta
Graph* gK2;

CPPUNIT_TEST_SUITE_REGISTRATION(bfstestclass1);

bfstestclass1::bfstestclass1() {
}

bfstestclass1::~bfstestclass1() {
}

void bfstestclass1::setUp() {
    gEx = new GraphMatrix(5);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);

    gDe = new GraphList(5);
    gDe->addEdge(1, 2);
    gDe->addEdge(2, 3);
    gDe->addEdge(1, 3);
    gDe->addEdge(4, 5);

    gK2 = new GraphMatrix(2);
    gK2->addEdge(1, 2);
}

void bfstestclass1::tearDown() {
    delete gEx;
    delete gDe;
    delete gK2;
}

void bfstestclass1::testBfs() {
    // di = bfs instance
    Bfs di(gEx);

    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(5));

    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(5));

    di.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));

    di.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));
}

void bfstestclass1::testBfsGrafoDesconexo() {
    Bfs di(gDe);

    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(5));

    di.bfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));

    di.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));

    di.bfs(3);
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));

    di.bfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(5));

    di.bfs(4);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getBfsParent(5));
}

void bfstestclass1::testBfsStartOverPrimeiro() {
    Bfs di(gDe);

    di.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));

    di.bfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getBfsParent(5));

    di.bfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getBfsParent(5));
}

void bfstestclass1::testBfsConflict() {
    Bfs di(gK2);

    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));

    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));

    di.bfs(2);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getBfsParent(2));
    
    di.bfsStartOver(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(2));
    
    di.bfs(1);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(2));
    
    di.bfs(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getBfsParent(2));
}