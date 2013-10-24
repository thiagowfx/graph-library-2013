/*
 * File:   dfs_testclass.cpp
 * Author: thiago
 *
 * Created on Oct 22, 2013, 12:10:34 AM
 */

#include "dfs_testclass.h"
#include "../Graph.h"
#include "../GraphMatrix.h"
#include "../GraphList.h"
#include "../GraphAlgorithms.h"

Graph* gEx;

CPPUNIT_TEST_SUITE_REGISTRATION(dfs_testclass);

dfs_testclass::dfs_testclass() {
}

dfs_testclass::~dfs_testclass() {
}

void dfs_testclass::setUp() {
    gEx = new GraphMatrix(5);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);
}

void dfs_testclass::tearDown() {
    delete gEx;
}

void dfs_testclass::testDfs() {
    GraphAlgorithms GA(gEx);

    GA.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, GA.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, GA.getDfsParent(5));

    GA.dfs(1);
    CPPUNIT_ASSERT_EQUAL(1ULL, GA.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, GA.getDfsParent(5));

    GA.dfs(5);
    CPPUNIT_ASSERT_EQUAL(2ULL, GA.getDfsParent(1));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(2));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(4));
    CPPUNIT_ASSERT_EQUAL(5ULL, GA.getDfsParent(5));
}