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
    Mst mi(gm, source);
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
    Mst mi(gl, source);
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

void primtestclass1::testSaveInfo() {
    const char output[] = "tmp/mstSaveInfo.txt";
    const char expected[] = "tests/graphs/mstSaveInfo.exp";
    Mst mi(gl, 3ULL);
    mi.saveInfo(output);
    CPPUNIT_ASSERT(areFilesEquali(output, expected));

    const char output2[] = "tmp/mstSaveInfo2.txt";
    const char expected2[] = "tests/graphs/mstSaveInfo2.exp";
    Mst mj(gm, 1ULL);
    mj.saveInfo(output2);
    CPPUNIT_ASSERT(areFilesEquali(output2, expected2));
}

void primtestclass1::testMstGrafoDesconexo() {
    Mst mj(gDesc, 4ULL);    
    CPPUNIT_ASSERT_EQUAL(5ULL, gDesc->getN());
    CPPUNIT_ASSERT_EQUAL(4ULL, mj.getSource());
    
    CPPUNIT_ASSERT_EQUAL(2ULL, mj.getNumberOfMstNodes());
    CPPUNIT_ASSERT_EQUAL(1.0, mj.getMstCost());
    
    Mst mi(gDesc, 1ULL);
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