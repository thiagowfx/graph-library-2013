/*
 * File:   dfstestclass1.cpp
 * Author: thiago
 *
 * Created on Oct 28, 2013, 12:56:00 PM
 */

#include "dfstestclass1.h"

Graph* gEx;
// K3 e K2
Graph* gDe;
// K2 = 1 aresta
Graph* gK2;

CPPUNIT_TEST_SUITE_REGISTRATION(dfstestclass1);

dfstestclass1::dfstestclass1() {
}

dfstestclass1::~dfstestclass1() {
}

void dfstestclass1::setUp() {
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

void dfstestclass1::tearDown() {
    delete gEx;
    delete gDe;
    delete gK2;
}

void dfstestclass1::testDfs() {
    // di = dfs instance
    Dfs di(gEx);

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(5));

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));
}

void dfstestclass1::testDfsGrafoDesconexo() {
    Dfs di(gDe);

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(5));

    di.dfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));

    di.dfs(3);
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));

    di.dfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(5));

    di.dfs(4);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getDfsParent(5));
}

void dfstestclass1::testDfsStartOverPrimeiro() {
    Dfs di(gDe);

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));

    di.dfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getDfsParent(5));

    di.dfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getDfsParent(5));
}

void dfstestclass1::testDfsConflict() {
    Dfs di(gK2);

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(2));

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(2));

    di.dfs(2);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getDfsParent(2));
    
    di.dfsStartOver(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(2));
    
    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(2));
    
    di.dfs(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getDfsParent(2));
}