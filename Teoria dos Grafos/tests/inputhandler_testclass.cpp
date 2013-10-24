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
#include "../GraphAlgorithms.h"
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

void inputhandler_testclass::testReadGraph() {
    CPPUNIT_ASSERT(false);
    // fazer readGraph
    
    Graph *g;
    InputHandler.readGraphMatrix(g, "graphs/k3.txt");
    CPPUNIT_ASSERT(g->isEdge(1, 2));
    CPPUNIT_ASSERT(g->isEdge(2, 3));
    CPPUNIT_ASSERT(g->isEdge(1, 3));
    CPPUNIT_ASSERT(!g->isEdge(1, 1));
    
    CPPUNIT_ASSERT_THROW(g->isEdge(1,4), std::exception);
    CPPUNIT_ASSERT_THROW(g->isEdge(3,4), std::exception);
    
}