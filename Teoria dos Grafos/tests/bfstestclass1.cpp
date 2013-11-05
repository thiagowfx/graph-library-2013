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

void bfstestclass1::tearDown() {
    delete gEx;
    delete gDe;
    delete gK2;
}

void bfstestclass1::testBfs() {
    // di = bfs instance
    Bfs bi(gEx);

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(5));

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(5));

    bi.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(5));

    bi.bfsStartOver(5);
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(5));
}

void bfstestclass1::testBfsGrafoDesconexo() {
    Bfs bi(gDe);

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_THROW(bi.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(5), std::exception);

    bi.bfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(5));


    bi.bfsStartOver(5);
    CPPUNIT_ASSERT_THROW(bi.getParent(1), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(2), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    bi.bfs(3);
    CPPUNIT_ASSERT_EQUAL(3ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(3ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    bi.bfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_THROW(bi.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(5), std::exception);

    bi.bfs(4);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, bi.getParent(5));
}

void bfstestclass1::testBfsStartOverPrimeiro() {
    Bfs bi(gDe);

    bi.bfsStartOver(5);
    CPPUNIT_ASSERT_THROW(bi.getParent(1), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(2), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getParent(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    CPPUNIT_ASSERT_THROW(bi.getLevel(1), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getLevel(2), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getLevel(3), std::exception);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(5));

    bi.bfsStartOver(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_THROW(bi.getLevel(5), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getLevel(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_THROW(bi.getLevel(4), std::exception);
    CPPUNIT_ASSERT_THROW(bi.getLevel(5), std::exception);

    bi.bfs(5);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(5));

}

void bfstestclass1::testBfsConflict() {
    Bfs bi(gK2);

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));

    bi.bfs(2);
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));

    bi.bfsStartOver(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(2));

    bi.bfs(1);
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(2));

    bi.bfs(2);
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, bi.getParent(2));

    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(2));
}

void bfstestclass1::testBfsSaveInfo() {
    Bfs bi(gEx);
    bi.bfs(1);
    const char file[] = "tmp/testBfsSaveInfo.txt";
    bi.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("parent[1] = 1, level[1] = 0" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[2] = 1, level[2] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[3] = 5, level[3] = 2" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[4] = 5, level[4] = 2" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[5] = 1, level[5] = 1" == s);

    is.close();
}

void bfstestclass1::testBfsSaveInfo2() {
    Bfs bi(gDe);
    bi.bfs(1);
    const char file[] = "tmp/testBfsSaveInfo2.txt";
    bi.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("parent[1] = 1, level[1] = 0" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[2] = 1, level[2] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[3] = 1, level[3] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[4] = undef, level[4] = undef" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("parent[5] = undef, level[5] = undef" == s);

    is.close();
}

void bfstestclass1::testBfsAll() {
    Bfs bi(gDe);
    bi.bfsAll();
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(4ULL, bi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(4ULL, bi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(3));
    CPPUNIT_ASSERT_EQUAL(0ULL, bi.getLevel(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, bi.getLevel(5));
}