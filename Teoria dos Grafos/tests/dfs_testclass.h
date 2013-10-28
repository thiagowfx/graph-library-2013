/*
 * File:   dfs_testclass.h
 * Author: thiago
 *
 * Created on Oct 22, 2013, 12:10:34 AM
 */

#ifndef DFS_TESTCLASS_H
#define	DFS_TESTCLASS_H

#include <cppunit/extensions/HelperMacros.h>

class dfs_testclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(dfs_testclass);

    CPPUNIT_TEST(testDfs);
    CPPUNIT_TEST(testDfsGrafoDesconexo);
    CPPUNIT_TEST(testDfsStartOverPrimeiro);

    CPPUNIT_TEST_SUITE_END();

public:
    dfs_testclass();
    virtual ~dfs_testclass();
    void setUp();
    void tearDown();

private:
    void testDfs();
    void testDfsGrafoDesconexo();
    void testDfsStartOverPrimeiro();
};

#endif	/* DFS_TESTCLASS_H */

