#include "dijkstratestclass1.h"

Graph *gm;

CPPUNIT_TEST_SUITE_REGISTRATION(dijkstratestclass1);

dijkstratestclass1::dijkstratestclass1() {
}

dijkstratestclass1::~dijkstratestclass1() {
}

void dijkstratestclass1::setUp() {
    gm = new GraphMatrix(5, true);
    gm->addEdge(1, 2, 1.0);
    gm->addEdge(2, 5, 2.0);
    gm->addEdge(1, 3, 2.0);
    gm->addEdge(3, 5, 1.0);
    gm->addEdge(1, 4, 8.0);
    gm->addEdge(4, 5, 3.0);
}

void dijkstratestclass1::tearDown() {
    delete gm;
}

void dijkstratestclass1::testDijkstra() {
    CPPUNIT_ASSERT_EQUAL(5ULL, gm->getN());
    CPPUNIT_ASSERT(gm->isWeighted());
    CPPUNIT_ASSERT(!gm->isNegativeWeighted());
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(1, 2));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(1, 3));
    CPPUNIT_ASSERT_EQUAL(8.0, gm->getWeight(1, 4));
    CPPUNIT_ASSERT_EQUAL(2.0, gm->getWeight(2, 5));
    CPPUNIT_ASSERT_EQUAL(1.0, gm->getWeight(3, 5));
    CPPUNIT_ASSERT_EQUAL(3.0, gm->getWeight(4, 5));

    unsigned long long source = 1;
    Dijkstra di(gm, source);
    CPPUNIT_ASSERT_EQUAL(0.0, di.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(1.0, di.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(2.0, di.getDistance(3));
    CPPUNIT_ASSERT_EQUAL(6.0, di.getDistance(4));
    CPPUNIT_ASSERT_EQUAL(3.0, di.getDistance(5));

    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(3));
    CPPUNIT_ASSERT_EQUAL(5ULL, di.getParent(4));
    CPPUNIT_ASSERT_EQUAL(2ULL, di.getParent(5));
}

void dijkstratestclass1::testOnlyPositiveWeights() {
    Graph *g = new GraphList(5, true);
    g->addEdge(1, 2, 1.0);
    g->addEdge(2, 3, -1.0);

    CPPUNIT_ASSERT_THROW_MESSAGE("o grafo contém algum peso negativo", Dijkstra di(g, 1), std::exception);
}

void dijkstratestclass1::testGetPath() {
    std::vector<unsigned long long> v = {1, 2, 5, 4};
    Dijkstra di(gm, 1ULL);
    CPPUNIT_ASSERT_MESSAGE(printVector(v) + printVector(di.getPath(4)), v == di.getPath(4));

    v = {2, 5, 4};
    Dijkstra dj(gm, 2ULL);
    CPPUNIT_ASSERT_MESSAGE(printVector(v) + printVector(dj.getPath(4)), v == dj.getPath(4));
}

void dijkstratestclass1::testConstructorWithTarget() {
    Graph *g = new GraphMatrix(5, true);
    g->addEdge(1, 2, 3.0);
    g->addEdge(2, 3, 3.0);
    Dijkstra di(g, 1ULL, 2ULL);
    CPPUNIT_ASSERT_EQUAL(0.0, di.getDistance(1));
    CPPUNIT_ASSERT_EQUAL(3.0, di.getDistance(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(2));
    CPPUNIT_ASSERT_EQUAL(1ULL, di.getParent(1));

    std::vector<unsigned long long> v = {1, 2};
    CPPUNIT_ASSERT_MESSAGE(printVector(v) + printVector(di.getPath(2)), v == di.getPath(2));

    CPPUNIT_ASSERT_THROW(di.getParent(3), std::exception);
    CPPUNIT_ASSERT_THROW(di.getDistance(3), std::exception);
    CPPUNIT_ASSERT_THROW(di.getPath(3), std::exception);
}

void dijkstratestclass1::testSaveInfo() {
    Graph *g = new GraphMatrix(4, true);
    g->addEdge(1, 2, 2.0);
    g->addEdge(2, 3, 2.0);
    g->addEdge(1, 3, 5.0);
    /**
     *    1 --(2.0)--- 2
     *     \          /
     *      \        /
     *      (5.0)   (2.0)
     *        \    /
     *         \  /
     *          3
     */

    Dijkstra di(g, 1ULL);
    const char file[] = "tmp/testDijkstraSaveInfo.txt";
    di.saveInfo(file);

    std::ifstream is;
    is.open(file);
    std::string s;

    std::getline(is, s);    CPPUNIT_ASSERT("source = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("distance[1] = 0, parent[1] = 1, path[1] = 1" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("distance[2] = 2, parent[2] = 1, path[2] = 1 2" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("distance[3] = 4, parent[3] = 2, path[3] = 1 2 3" == s);
    std::getline(is, s);    CPPUNIT_ASSERT("distance[4] = undef, parent[4] = undef, path[4] = undef" == s);

    is.close();
}