/*
 * File:   outputinfo_testclass.cpp
 * Author: thiago
 *
 * Created on Oct 22, 2013, 9:37:42 AM
 */

#include "outputinfo_testclass.h"
#include "../Graph.h"
#include "../GraphMatrix.h"
#include "../GraphList.h"

Graph* gEx;

CPPUNIT_TEST_SUITE_REGISTRATION(outputinfo_testclass);

outputinfo_testclass::outputinfo_testclass() {
}

outputinfo_testclass::~outputinfo_testclass() {
}

void outputinfo_testclass::setUp() {
    gEx = new GraphMatrix(5);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);
}

void outputinfo_testclass::tearDown() {
    delete gEx;
}

void outputinfo_testclass::testSaveInfo() {
    const char file[] = "tmp/testSaveInfo.txt";
    gEx->saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);
    CPPUNIT_ASSERT("# n = 5" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("# m = 5" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("# d_medio = 2.0" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("1 0.40" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("2 0.40" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("3 0.00" == s);

    std::getline(is, s);
    CPPUNIT_ASSERT("4 0.20" == s);

    is.close();
}
