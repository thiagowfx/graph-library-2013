/*
 * File:   inputhandler_testclass.cpp
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:51:08 AM
 */

#include "inputhandlertestclass1.h"

CPPUNIT_TEST_SUITE_REGISTRATION(inputhandlertestclass1);

inputhandlertestclass1::inputhandlertestclass1() {
}

inputhandlertestclass1::~inputhandlertestclass1() {
}

void inputhandlertestclass1::setUp() {
}

void inputhandlertestclass1::tearDown() {
}

void a(Graph **g) {
    *g = new GraphMatrix(3, false);
    (*g)->addEdge(1, 2);
    (*g)->addEdge(2, 3);
    (*g)->addEdge(1, 3);
}

void inputhandlertestclass1::testReadGraphMatrix() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3.txt";
    //a(&g);
    ih.readGraph(&g, c, 'm', false);

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

void inputhandlertestclass1::testReadGraphList() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3.txt";
    //a(&g);
    ih.readGraph(&g, c, 'l', false);

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

void inputhandlertestclass1::testReadGraphMatrixWeighted() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3weighted.txt";
    ih.readGraph(&g, c, 'm', true);

    CPPUNIT_ASSERT(g->isEdge(1, 2));
    CPPUNIT_ASSERT(g->isEdge(1, 3));
    CPPUNIT_ASSERT(g->isEdge(2, 3));
    CPPUNIT_ASSERT(!g->isEdge(1, 1));

    CPPUNIT_ASSERT(g->isWeighted());
    CPPUNIT_ASSERT(!g->isNegativeWeighted());

    CPPUNIT_ASSERT_EQUAL(3ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(3ULL, g->getM());

    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(3));

    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(2.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(3.0, g->getWeight(2, 3));

    CPPUNIT_ASSERT_THROW(g->getDegree(4), std::exception);

    delete g;
}

void inputhandlertestclass1::testReadGraphListWeighted() {
    Graph *g;
    InputHandler ih;
    const char c[] = "tests/graphs/k3weighted.txt";
    ih.readGraph(&g, c, 'l', true);

    CPPUNIT_ASSERT(g->isEdge(1, 2));
    CPPUNIT_ASSERT(g->isEdge(1, 3));
    CPPUNIT_ASSERT(g->isEdge(2, 3));
    CPPUNIT_ASSERT(!g->isEdge(1, 1));

    CPPUNIT_ASSERT(g->isWeighted());
    CPPUNIT_ASSERT(!g->isNegativeWeighted());

    CPPUNIT_ASSERT_EQUAL(3ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(3ULL, g->getM());

    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(1));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(2));
    CPPUNIT_ASSERT_EQUAL(2ULL, g->getDegree(3));

    CPPUNIT_ASSERT_EQUAL(1.0, g->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(2.0, g->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(3.0, g->getWeight(2, 3));

    CPPUNIT_ASSERT_THROW(g->getDegree(4), std::exception);

    delete g;
}

void inputhandlertestclass1::testRemoveDuplicates() {
    InputHandler ih;

    const char input[] = "tests/graphs/duplicates.txt";
    const char output[] = "tmp/duplicates.txt";
    const char expected[] = "tests/graphs/duplicates.exp";
    ih.removeDuplicates(input, output);
    CPPUNIT_ASSERT(areFilesEquali(output, expected));

    const char input2[] = "tests/graphs/duplicates2.txt";
    const char output2[] = "tmp/duplicates2.txt";
    const char expected2[] = "tests/graphs/duplicates2.exp";
    ih.removeDuplicates(input2, output2);
    CPPUNIT_ASSERT(areFilesEquali(output2, expected2));
}