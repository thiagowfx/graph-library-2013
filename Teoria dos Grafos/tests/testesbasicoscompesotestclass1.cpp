/*
 * File:   newtestclass1.cpp
 * Author: thiago
 *
 * Created on Oct 28, 2013, 11:00:07 PM
 */

#include "testesbasicoscompesotestclass1.h"

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void newtestclass1::testBasic() {
    Graph *g = new GraphMatrix(5, true);
    g->addEdge(1, 2, 1);
    g->addEdge(1, 3);
    g->addEdge(1, 4, 10);
    g->addEdge(1, 5, 50);

    CPPUNIT_ASSERT_EQUAL(4ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(5));

    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(10.0, g->getWeight(1, 4));
    CPPUNIT_ASSERT_EQUAL(50.0, g->getWeight(1, 5));
    CPPUNIT_ASSERT_EQUAL(true, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testBasic2() {
    Graph *g = new GraphMatrix(5, true);
    g->addEdge(1, 2, -10);
    CPPUNIT_ASSERT_EQUAL(-10.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(true, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(true, g->isNegativeWeighted());
}

void newtestclass1::testBasic3() {
    Graph *g = new GraphMatrix(5, false);
    g->addEdge(1, 2);
    g->addEdge(1, 3, 10);
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(false, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testBasic4() {
    // FIXME Graph *g = new GraphMatrix(5);
    Graph *g = new GraphMatrix(5, false);
    g->addEdge(1, 2);
    g->addEdge(1, 3, 10);
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(false, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testBasic5() {
    Graph *g = new GraphList(5, true);
    g->addEdge(1, 2, 3.0);
    g->addEdge(1, 3);
    g->addEdge(1, 4, 10);
    g->addEdge(1, 5, 50);

    CPPUNIT_ASSERT_EQUAL(4ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(4));
    CPPUNIT_ASSERT_EQUAL(1ULL, g->getDegree(5));

    CPPUNIT_ASSERT_EQUAL(3.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(10.0, g->getWeight(1, 4));
    CPPUNIT_ASSERT_EQUAL(50.0, g->getWeight(1, 5));
    CPPUNIT_ASSERT_EQUAL(true, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testBasic6() {
    Graph *g = new GraphList(5, true);
    g->addEdge(1, 2, -10);
    CPPUNIT_ASSERT_EQUAL(-10.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(true, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(true, g->isNegativeWeighted());
}

void newtestclass1::testBasic7() {
    Graph *g = new GraphList(5, false);
    g->addEdge(1, 2);
    g->addEdge(1, 3, 10);
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(false, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testBasic8() {
    // FIXME Graph *g = new GraphList(5);
    Graph *g = new GraphList(5, false);
    g->addEdge(1, 2);
    g->addEdge(1, 3, 10);
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(false, g->isWeighted());
    CPPUNIT_ASSERT_EQUAL(false, g->isNegativeWeighted());
}

void newtestclass1::testException() {
    Graph *g = new GraphList(5, true);
    CPPUNIT_ASSERT_THROW(g->getWeight(1, 10), std::exception);

    //Graph *h = new GraphMatrix(5, true);
    //CPPUNIT_ASSERT_THROW( g->isEdge(1, 10), std::exception);
}