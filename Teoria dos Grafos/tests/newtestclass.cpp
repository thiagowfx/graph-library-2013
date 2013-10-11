/*
 * File:   newtestclass.cpp
 * Author: thiago
 *
 * Created on 06/10/2013, 20:16:11
 */

#include <string>
#include "newtestclass.h"
#include "Graph.h"
#include "GraphMatrix.h"

GraphMatrix emptyGm(10);
GraphMatrix gm(10);

template <class T>
bool compareVectors(const std::vector<T>& v1, const std::vector<T>& v2) {
    if ( v1.size() != v2.size() )
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
    gm.addEdge(1,2);
    gm.addEdge(1,3);
    gm.addEdge(9,10);
}

void newtestclass::tearDown() {
}

void newtestclass::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass::testEmptyGraph() {
    Graph *g = new GraphMatrix(0);
    CPPUNIT_ASSERT_EQUAL( 0ULL, g->getN());
    CPPUNIT_ASSERT_EQUAL( 0ULL, g->getM());
    CPPUNIT_ASSERT_EQUAL( 0.0, g->getAverDeg());
}

void newtestclass::testAddEdgesGraphMatrix() {    
    CPPUNIT_ASSERT_EQUAL( 3ULL, gm.getM());
    CPPUNIT_ASSERT_EQUAL( 10ULL, gm.getN());
    
    CPPUNIT_ASSERT( gm.isEdge(1,2) );
    CPPUNIT_ASSERT( gm.isEdge(2,1) );
    CPPUNIT_ASSERT( gm.isEdge(1,3) );
    CPPUNIT_ASSERT( gm.isEdge(3,1) );
    CPPUNIT_ASSERT( gm.isEdge(9,10) );
    CPPUNIT_ASSERT( gm.isEdge(10,9) );
    CPPUNIT_ASSERT( !gm.isEdge(2,3) );
    CPPUNIT_ASSERT( !gm.isEdge(1,1) );
    
    CPPUNIT_ASSERT( !emptyGm.isEdge(2,3) );
    CPPUNIT_ASSERT( !emptyGm.isEdge(1,1) );
}

void newtestclass::testGetDegreeGraphMatrix() {
    CPPUNIT_ASSERT_EQUAL( 2ULL, gm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(2));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(3));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(9));
    CPPUNIT_ASSERT_EQUAL( 1ULL, gm.getDegree(10));
    CPPUNIT_ASSERT_EQUAL( 0ULL, gm.getDegree(4));
    CPPUNIT_ASSERT_EQUAL( 0ULL, gm.getDegree(5));
    
    CPPUNIT_ASSERT_EQUAL( 0ULL, emptyGm.getDegree(1));
    CPPUNIT_ASSERT_EQUAL( 0ULL, emptyGm.getDegree(10));
}

void newtestclass::testGetNeighbours() {
    unsigned long long _v[] = {2,3};
    vector<unsigned long long> v(_v, _v + sizeof(_v)/sizeof(unsigned long long));
    CPPUNIT_ASSERT_MESSAGE( 
            returnPrintVector<unsigned long long>(v)
            + returnPrintVector<unsigned long long>(gm.getNeighbours(1))            
            , compareVectors<unsigned long long>( gm.getNeighbours(1), v));
    
    v = vector<unsigned long long>();
    v.push_back(1);
    CPPUNIT_ASSERT_MESSAGE(
            returnPrintVector<unsigned long long>(v)
            + returnPrintVector<unsigned long long>(gm.getNeighbours(2))            
            , compareVectors<unsigned long long>( gm.getNeighbours(2), v));
    
    v = vector<unsigned long long>();
    v.push_back(10);
    CPPUNIT_ASSERT( compareVectors<unsigned long long>( gm.getNeighbours(9), v));
    
    v = vector<unsigned long long>();
    CPPUNIT_ASSERT( compareVectors<unsigned long long>( gm.getNeighbours(5), v));
}