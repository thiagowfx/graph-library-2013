/*
 * File:   newtestclass.cpp
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:11
 */

#include <boost/assign/list_of.hpp> // std::vector<int> v = boost::assign::list_of(1)(2)(3)(4);
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
using namespace boost::assign; // bring 'operator+=()' into scope
// vector<int> values;  
// values += 1,2,3,4,5,6,7,8,9; // insert values at the end of the container
#include <boost/assert.hpp>
// BOOST_ASSERT( true )
// v = {10,11} --std=c++11 way (flag to gcc)

#include <iostream>
#include <fstream>
#include <string>
#include "newtestclass.h"
#include "Graph.h"
#include "GraphMatrix.h"
#include "GraphList.h"
#include "GraphAlgorithms.h"

GraphMatrix emptyGm(10);
GraphMatrix gm(10);
GraphList emptyGl(10);
GraphList gl(10);
Graph* gEx;

template <class T>
bool compareVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    if (v1.size() != v2.size())
        return false;

    for (int i = 0; i < (int) v1.size(); ++i)
        if (v1[i] != v2[i])
            return false;
    return true;
}

template<class T>
void printVector(const std::vector<T>& v) {
    for (int i = 0; i < (int) v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

template<class T>
std::string returnPrintVector(const std::vector<T>& v) {
    std::string s;
    s += ": ";
    char tmp[100];
    for (int i = 0; i < (int) v.size(); ++i) {
        sprintf(tmp, "%lld", v[i]);
        s += tmp;
        s += " ";
    }
    s += "\n";
    return s;
}

CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
    gm = GraphMatrix(10);
    gm.addEdge(1, 2);
    gm.addEdge(1, 3);
    gm.addEdge(9, 10);

    gl = GraphList(10);
    gl.addEdge(1, 2);
    gl.addEdge(1, 3);
    gl.addEdge(9, 10);

    gEx = new GraphMatrix(5);
    gEx->addEdge(1, 2);
    gEx->addEdge(2, 5);
    gEx->addEdge(5, 3);
    gEx->addEdge(4, 5);
    gEx->addEdge(1, 5);
}

void newtestclass::tearDown() {
    delete gEx;
}

void newtestclass::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass::testEmptyGraphMatrix() {
    Graph *g = new GraphMatrix(0);
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL(0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
    delete g;
}

void newtestclass::testAddEdgesGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL(3ULL, gm.getM());
    CPPUNIT_ASSERT_EQUAL(10ULL, gm.getN());
    CPPUNIT_ASSERT_EQUAL(0.6, gm.getAverDeg());

    CPPUNIT_ASSERT(gm.isEdge(1, 2));
    CPPUNIT_ASSERT(gm.isEdge(2, 1));
    CPPUNIT_ASSERT(gm.isEdge(1, 3));
    CPPUNIT_ASSERT(gm.isEdge(3, 1));
    CPPUNIT_ASSERT(gm.isEdge(9, 10));
    CPPUNIT_ASSERT(gm.isEdge(10, 9));
    CPPUNIT_ASSERT(!gm.isEdge(2, 3));
    CPPUNIT_ASSERT(!gm.isEdge(1, 1));

    CPPUNIT_ASSERT(!emptyGm.isEdge(2, 3));
    CPPUNIT_ASSERT(!emptyGm.isEdge(1, 1));

    CPPUNIT_ASSERT_THROW(gm.isEdge(10, 11), std::exception);
}

void newtestclass::testGetDegreeGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL(2ULL, gm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(9));
    CPPUNIT_ASSERT_EQUAL(1ULL, gm.getDegree(10));
    CPPUNIT_ASSERT_EQUAL(0ULL, gm.getDegree(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, gm.getDegree(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGm.getDegree(10));

    CPPUNIT_ASSERT_THROW(gm.getDegree(11), std::exception);
}

void newtestclass::testGetNeighboursGraphMatrix() {
    std::vector<unsigned long long> v{2, 3};
    CPPUNIT_ASSERT_MESSAGE(
            returnPrintVector(v)
            + returnPrintVector(gm.getNeighbours(1))
            , compareVectors(gm.getNeighbours(1), v));

    v = {1};
    CPPUNIT_ASSERT_MESSAGE(
            returnPrintVector(v)
            + returnPrintVector(gm.getNeighbours(2))
            , compareVectors(gm.getNeighbours(2), v));

    v = {10};
    CPPUNIT_ASSERT(compareVectors(gm.getNeighbours(9), v));

    v = std::vector<unsigned long long>();
    CPPUNIT_ASSERT(compareVectors(gm.getNeighbours(5), v));

    CPPUNIT_ASSERT_THROW(gm.getNeighbours(11), std::exception);
}

void newtestclass::testEmptyGraphList() {
    Graph *g = new GraphList(0);
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de nós", 0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL_MESSAGE("Número de arestas", 0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL(0.0, g->getAverDeg());
}

void newtestclass::testAddEdgesGraphList() {
    CPPUNIT_ASSERT_EQUAL(3ULL, gl.getM());
    CPPUNIT_ASSERT_EQUAL(10ULL, gl.getN());
    CPPUNIT_ASSERT_EQUAL(0.6, gl.getAverDeg());

    CPPUNIT_ASSERT(gl.isEdge(1, 2));
    CPPUNIT_ASSERT(gl.isEdge(2, 1));
    CPPUNIT_ASSERT(gl.isEdge(1, 3));
    CPPUNIT_ASSERT(gl.isEdge(3, 1));
    CPPUNIT_ASSERT(gl.isEdge(9, 10));
    CPPUNIT_ASSERT(gl.isEdge(10, 9));
    CPPUNIT_ASSERT(!gl.isEdge(2, 3));
    CPPUNIT_ASSERT(!gl.isEdge(1, 1));

    CPPUNIT_ASSERT(!emptyGl.isEdge(2, 3));
    CPPUNIT_ASSERT(!emptyGl.isEdge(1, 1));
}

void newtestclass::testGetDegreeGraphList() {
    CPPUNIT_ASSERT_EQUAL(2ULL, gl.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(3));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(9));
    CPPUNIT_ASSERT_EQUAL(1ULL, gl.getDegree(10));
    CPPUNIT_ASSERT_EQUAL(0ULL, gl.getDegree(4));
    CPPUNIT_ASSERT_EQUAL(0ULL, gl.getDegree(5));

    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGl.getDegree(1));
    CPPUNIT_ASSERT_EQUAL(0ULL, emptyGl.getDegree(10));

    CPPUNIT_ASSERT_THROW(gl.getDegree(11), std::exception);
}

void newtestclass::testGetNeighboursGraphList() {
    std::vector<unsigned long long> v{2, 3};
    CPPUNIT_ASSERT_MESSAGE(
            returnPrintVector(v)
            + returnPrintVector(gl.getNeighbours(1))
            , compareVectors(gl.getNeighbours(1), v));

    v = {1};
    CPPUNIT_ASSERT_MESSAGE(
            returnPrintVector(v)
            + returnPrintVector(gl.getNeighbours(2))
            , compareVectors(gl.getNeighbours(2), v));

    v = {10};
    CPPUNIT_ASSERT(compareVectors(gl.getNeighbours(9), v));

    v = std::vector<unsigned long long>();
    CPPUNIT_ASSERT(compareVectors(gl.getNeighbours(5), v));

    CPPUNIT_ASSERT_THROW(gl.getNeighbours(11), std::exception);
}

void newtestclass::testEmpDist() {
    std::vector<double> v = gEx->getEmpDist();
    std::vector<double> w = {0.0, 0.4, 0.4, 0.0, 0.2};
    CPPUNIT_ASSERT(compareVectors(v, w));
}

void newtestclass::testSaveInfo() {
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

//void newtestclass::testReadFileGraphMatrix() {
    //CPPUNIT_ASSERT(false);
    //   const char c[] = "samples/k3.txt";
    //   Graph* g = new GraphMatrix(c);
    //   
    //   CPPUNIT_ASSERT( g->isEdge(1, 2) );
    //   CPPUNIT_ASSERT( g->isEdge(1, 3) );
    //   CPPUNIT_ASSERT( g->isEdge(2, 3) );
    //   CPPUNIT_ASSERT( !g->isEdge(1, 1) );
    //   
    //   CPPUNIT_ASSERT_EQUAL( 3ULL, g->getN() );
    //   CPPUNIT_ASSERT_EQUAL( 3ULL, g->getM() );
    //   
    //   CPPUNIT_ASSERT_EQUAL( 2ULL, g->getDegree(1));
    //   CPPUNIT_ASSERT_EQUAL( 2ULL, g->getDegree(2));
    //   CPPUNIT_ASSERT_EQUAL( 2ULL, g->getDegree(3));
    //   
    //   CPPUNIT_ASSERT_THROW( g->isEdge(3, 4), std::exception);
    //   CPPUNIT_ASSERT_THROW( g->getDegree(4), std::exception);
//}

void newtestclass::testDfs() {
    GraphAlgorithms GA(gEx);
    
    GA.dfs(1);
    CPPUNIT_ASSERT_EQUAL( 1ULL, GA.getDfsParent(1) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(2) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(3) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(4) );
    CPPUNIT_ASSERT_EQUAL( 1ULL, GA.getDfsParent(5) );
    
    GA.dfs(1);
    CPPUNIT_ASSERT_EQUAL( 1ULL, GA.getDfsParent(1) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(2) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(3) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(4) );
    CPPUNIT_ASSERT_EQUAL( 1ULL, GA.getDfsParent(5) );
   
    GA.dfs(5);
    CPPUNIT_ASSERT_EQUAL( 2ULL, GA.getDfsParent(1) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(2) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(3) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(4) );
    CPPUNIT_ASSERT_EQUAL( 5ULL, GA.getDfsParent(5) );
    
}

// adicionar TESTE DFS GRAFO DESCONEXO