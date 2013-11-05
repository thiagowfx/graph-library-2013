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
    gEx = new GraphMatrix(5, false);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);

    gDe = new GraphList(5, false);
    gDe->addEdge(1, 2);
    gDe->addEdge(2, 3);
    gDe->addEdge(1, 3);
    gDe->addEdge(4, 5);

    gK2 = new GraphMatrix(2, false);
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
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(5));

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));
}

void dfstestclass1::testDfsGrafoDesconexo() {
    Dfs di(gDe);

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_THROW(di.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_THROW(di.getLevel(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(5), std::exception);

    di.dfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_THROW(di.getParent(1), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(2), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_THROW(di.getLevel(1), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(2), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));

    di.dfs(3);
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));

    di.dfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_THROW(di.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_THROW(di.getLevel(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(5), std::exception);

    di.dfs(4);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(5));
}

void dfstestclass1::testDfsStartOverPrimeiro() {
    Dfs di(gDe);

    di.dfsStartOver(5);
    CPPUNIT_ASSERT_THROW(di.getParent(1), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(2), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_THROW(di.getLevel(1), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(2), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));

    di.dfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_THROW(di.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getParent(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_THROW(di.getLevel(4), std::exception);
    CPPUNIT_ASSERT_THROW(di.getLevel(5), std::exception);

    di.dfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(5));
}

void dfstestclass1::testDfsConflict() {
    Dfs di(gK2);

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(2));

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(2));

    di.dfs(2);
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(2));

    di.dfsStartOver(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(2));
    
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(2));

    di.dfs(1);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(2));
    
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(2));

    di.dfs(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(2));
    
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(2));
}

void dfstestclass1::testDfsSaveInfo() {
    Dfs di(gEx);
    di.dfs(1);
    const char file[] = "tmp/testDfsSaveInfo.txt";
    di.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("parent[1] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[2] = 5" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[3] = 5" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[4] = 5" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[5] = 1" == s);

    is.close();
}


void dfstestclass1::testDfsSaveInfo2() {
    Dfs di(gDe);
    di.dfs(1);
    const char file[] = "tmp/testBfsSaveInfo2.txt";
    di.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("parent[1] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[2] = 3" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[3] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[4] = undef" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[5] = undef" == s);

    is.close();
}

void dfstestclass1::testDfsAll() {
    Dfs di(gDe);
    di.dfsAll();
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, di.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, di.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getLevel(5));
}