/*
 * File:   dfstestclass1.h
 * Author: thiago
 *
 * Created on Oct 28, 2013, 12:56:00 PM
 */

#ifndef DFSTESTCLASS1_H
#define	DFSTESTCLASS1_H

#include "../Include.h"
#include "../Dfs.h"

#include <cppunit/extensions/HelperMacros.h>

class dfstestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(dfstestclass1);

    CPPUNIT_TEST(testDfs);
    CPPUNIT_TEST(testDfsGrafoDesconexo);
    CPPUNIT_TEST(testDfsStartOverPrimeiro);
    CPPUNIT_TEST(testDfsConflict);
    CPPUNIT_TEST(testDfsSaveInfo);
    CPPUNIT_TEST(testDfsSaveInfo2);
    CPPUNIT_TEST(testDfsAll);

    CPPUNIT_TEST_SUITE_END();

public:
    dfstestclass1();
    virtual ~dfstestclass1();
    void setUp();
    void tearDown();

private:
    void testDfs();
    void testDfsGrafoDesconexo();
    void testDfsStartOverPrimeiro();
    void testDfsConflict();
    void testDfsSaveInfo();
    void testDfsSaveInfo2();
    void testDfsAll();
};

#endif	/* DFSTESTCLASS1_H */

