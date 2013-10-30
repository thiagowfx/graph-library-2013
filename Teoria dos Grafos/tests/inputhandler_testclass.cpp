/*
 * File:   inputhandler_testclass.cpp
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:51:08 AM
 */

#include "inputhandler_testclass.h"
#include "../Graph.h"
#include "../GraphMatrix.h"
#include "../GraphList.h"
#include "../InputHandler.h"

CPPUNIT_TEST_SUITE_REGISTRATION(inputhandler_testclass);

inputhandler_testclass::inputhandler_testclass() {
}

inputhandler_testclass::~inputhandler_testclass() {
}

void inputhandler_testclass::setUp() {
}

void inputhandler_testclass::tearDown() {
}

void a(Graph **g) {
    *g = new GraphMatrix(3, false);
    (*g)->addEdge(1, 2);
    (*g)->addEdge(2, 3);
    (*g)->addEdge(1, 3);
}

void inputhandler_testclass::testReadGraphMatrix() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3.txt";
    //a(&g);
    ih.readGraphMatrix(&g, c);

    CPPUNIT_ASSERT(g->isEdge(1, 2));
    CPPUNIT_ASSERT(g->isEdge(1, 3));
    CPPUNIT_ASSERT(g->isEdge(2, 3));
    CPPUNIT_ASSERT(!g->isEdge(1, 1));

    CPPUNIT_ASSERT_EQUAL(3ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(3ULL, g->getM());

    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(3));


    //CPPUNIT_ASSERT_THROW(g->isEdge(1, 4), std::exception);
    //CPPUNIT_ASSERT_THROW(g->isEdge(3, 4), std::exception);
    CPPUNIT_ASSERT_THROW(g->getDegree(4), std::exception);

    delete g;
}

void inputhandler_testclass::testReadGraphList() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3.txt";
    //a(&g);
    ih.readGraphList(&g, c);

    CPPUNIT_ASSERT(g->isEdge(1, 2));
    CPPUNIT_ASSERT(g->isEdge(1, 3));
    CPPUNIT_ASSERT(g->isEdge(2, 3));
    CPPUNIT_ASSERT(!g->isEdge(1, 1));

    CPPUNIT_ASSERT_EQUAL(3ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(3ULL, g->getM());

    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(3));

    CPPUNIT_ASSERT_THROW(g->getDegree(4), std::exception);

    delete g;
}
