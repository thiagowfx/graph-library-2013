#ifndef DIJKSTRATEST_H
#define	DIJKSTRATEST_H

#include "../Include.h"
#include "../Dijkstra.h"
#include "../Utilities.h"

#include <cppunit/extensions/HelperMacros.h>

class dijkstratest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(dijkstratest);

    CPPUNIT_TEST(testDijkstra);
    CPPUNIT_TEST(testOnlyPositiveWeights);
    CPPUNIT_TEST(testGetPath);
    CPPUNIT_TEST(testConstructorWithTarget);
    CPPUNIT_TEST(testSaveInfo);

    CPPUNIT_TEST_SUITE_END();

public:
    dijkstratest();
    virtual ~dijkstratest();
    void setUp();
    void tearDown();

private:
    void testDijkstra();
    void testOnlyPositiveWeights();
    void testGetPath();
    void testConstructorWithTarget();
    void testSaveInfo();
};

#endif	/* DIJKSTRATEST_H */

