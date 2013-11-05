/*
 * File:   primtestclass1.cpp
 * Author: thiago
 *
 * Created on Nov 2, 2013, 6:14:14 PM
 */

#include "primtestclass1.h"

Graph *gm;
Graph *gl;
Graph *gDesc;

CPPUNIT_TEST_SUITE_REGISTRATION(primtestclass1);

primtestclass1::primtestclass1() {
}

primtestclass1::~primtestclass1() {
}

void primtestclass1::setUp() {
    gm = new GraphMatrix(5, true);
    gm->addEdge(1, 2, 1);
    gm->addEdge(1, 3, 2);
    gm->addEdge(1, 4, 8.0);
    gm->addEdge(2, 5, 2);
    gm->addEdge(3, 5, 1);
    gm->addEdge(4, 5, 3);

    gl = new GraphList(4, true);
    gl->addEdge(1, 2, 1);
    gl->addEdge(1, 4, 1);
    gl->addEdge(2, 3, 1);
    gl->addEdge(3, 4, 10);

    gDesc = new GraphList(5, true);
    gDesc->addEdge(1, 2, 10);
    gDesc->addEdge(2, 3, 1);
    gDesc->addEdge(1, 3, 1);
    gDesc->addEdge(4, 5, 1);
}

void primtestclass1::tearDown() {
    delete gm;
    delete gl;
    delete gDesc;
}

void primtestclass1::testMst() {

    CPPUNIT_ASSERT_EQUAL(5ULL, gm->getN());
    CPPUNIT_ASSERT(gm->isWeighted());
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(8.0, gm->getWeight(1, 4));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(2, 5));
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(3, 5));
    CPPUNIT_ASSERT_EQUAL(3.0, gm->getWeight(4, 5));

    unsigned long long source = 1;
    Prim mi(gm, source);
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getSource());
    CPPUNIT_ASSERT_EQUAL(5ULL, mi.getNumberOfMstNodes());

    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, mi.getParent(4));
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getParent(5));

    CPPUNIT_ASSERT_EQUAL(0.0, mi.getKey(1));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(2));
    CPPUNIT_ASSERT_EQUAL(2.0, mi.getKey(3));
    CPPUNIT_ASSERT_EQUAL(3.0, mi.getKey(4));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(5));

    CPPUNIT_ASSERT_EQUAL(7.0, mi.getMstCost());

    CPPUNIT_ASSERT_EQUAL(0.0, mi.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(2.0, mi.getDistance(3));
    CPPUNIT_ASSERT_EQUAL(6.0, mi.getDistance(4));
    CPPUNIT_ASSERT_EQUAL(3.0, mi.getDistance(5));

    std::vector<unsigned long long> v = {1, 3, 5, 4};
    CPPUNIT_ASSERT(v == mi.getPath(4));

    v = {1, 2};
    CPPUNIT_ASSERT(v == mi.getPath(2));
}

void primtestclass1::testMst2() {
    CPPUNIT_ASSERT_EQUAL(4ULL, gl->getN());
    CPPUNIT_ASSERT(gl->isWeighted());
    CPPUNIT_ASSERT_EQUAL(1.0, gl->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, gl->getWeight(1, 4));
    CPPUNIT_ASSERT_EQUAL(1.0, gl->getWeight(2, 3));
    CPPUNIT_ASSERT_EQUAL(10.0, gl->getWeight(3, 4));

    unsigned long long source = 3;
    Prim mi(gl, source);
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getSource());
    CPPUNIT_ASSERT_EQUAL(4ULL, mi.getNumberOfMstNodes());

    CPPUNIT_ASSERT_EQUAL(2ULL, mi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getParent(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(4));

    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(1));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(2));
    CPPUNIT_ASSERT_EQUAL(0.0, mi.getKey(3));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(4));

    CPPUNIT_ASSERT_EQUAL(3.0, mi.getMstCost());

    CPPUNIT_ASSERT_EQUAL(2.0, mi.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(0.0, mi.getDistance(3));
    CPPUNIT_ASSERT_EQUAL(3.0, mi.getDistance(4));

    std::vector<unsigned long long> v = {3, 2, 1, 4};
    CPPUNIT_ASSERT(v == mi.getPath(4));

    v = {3, 2};
    CPPUNIT_ASSERT(v == mi.getPath(2));
}

void primtestclass1::testSaveGraph() {
    const char output[] = "tmp/mstSaveInfo.txt";
    const char expected[] = "tests/graphs/mstSaveInfo.exp";
    Prim mi(gl, 3ULL);
    mi.saveGraph(output);
    CPPUNIT_ASSERT(areFilesEqual(output, expected));

    const char output2[] = "tmp/mstSaveInfo2.txt";
    const char expected2[] = "tests/graphs/mstSaveInfo2.exp";
    Prim mj(gm, 1ULL);
    mj.saveGraph(output2);
    CPPUNIT_ASSERT(areFilesEqual(output2, expected2));

    const char output3[] = "tmp/mstSaveInfo3.txt";
    const char expected3[] = "tests/graphs/mstSaveInfo3.exp";
    Prim mk(gDesc, 1ULL);
    mk.saveGraph(output3);
    CPPUNIT_ASSERT(areFilesEqual(output3, expected3));
}

void primtestclass1::testMstGrafoDesconexo() {
    Prim mj(gDesc, 4ULL);
    CPPUNIT_ASSERT_EQUAL(5ULL, gDesc->getN());
    CPPUNIT_ASSERT_EQUAL(4ULL, mj.getSource());

    CPPUNIT_ASSERT_EQUAL(2ULL, mj.getNumberOfMstNodes());
    CPPUNIT_ASSERT_EQUAL(1.0, mj.getMstCost());

    Prim mi(gDesc, 1ULL);
    CPPUNIT_ASSERT_EQUAL(5ULL, gDesc->getN());
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getSource());
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getNumberOfMstNodes());
    CPPUNIT_ASSERT_EQUAL(2.0, mi.getMstCost());

    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(1));
    CPPUNIT_ASSERT_EQUAL(3ULL, mi.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, mi.getParent(3));
    CPPUNIT_ASSERT_THROW(mi.getParent(4), std::exception);
    CPPUNIT_ASSERT_THROW(mi.getParent(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0.0, mi.getKey(1));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(2));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getKey(3));
    CPPUNIT_ASSERT_THROW(mi.getKey(4), std::exception);
    CPPUNIT_ASSERT_THROW(mi.getKey(5), std::exception);

    CPPUNIT_ASSERT_EQUAL(0.0, mi.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(2.0, mi.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(1.0, mi.getDistance(3));
    CPPUNIT_ASSERT_THROW(mi.getKey(4), std::exception);
    CPPUNIT_ASSERT_THROW(mi.getKey(5), std::exception);
}

void primtestclass1::testSaveInfo() {
    Prim mi(gDesc, 1ULL);
    const char file[] = "tmp/testPrimSaveInfo.txt";
    mi.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("custo = 2, source = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("key[1] = 0, parent[1] = 1, path[1] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("key[2] = 1, parent[2] = 3, path[2] = 1 3 2" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("key[3] = 1, parent[3] = 1, path[3] = 1 3" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("key[4] = undef, parent[4] = undef, path[4] = undef" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("key[5] = undef, parent[5] = undef, path[5] = undef" == s);

    is.close();
}