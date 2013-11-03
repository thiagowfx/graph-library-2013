// No header:
/** Retorna a distância média do grafo. */
double getAverageDist() const;

// No fonte:
double getAverageDist() const {
  double averageDist = 0.0;

  // somar tudo
  for (int u = 1; u <= G->getN(); ++u) {
    for (int v = 1; v <= G->getN(); ++v) {
      if (D[u][v] != INF)
	averageDist += D[u][v];
    }
  }

  // agora dividir
  averageDist /= ((G->getN() * (G->getN() - 1))/double(2));

  return averageDist;
}

// Teste (.h):
CPPUNIT_TEST(testAverDist);

// ...

void testAverDist();


// Teste (.cpp):
void floydtestclass1::testAverDist() {
  Graph *gm = new GraphMatrix(5, true);
  gm->addEdge(1, 2, 2.0);
  gm->addEdge(2, 3, 2.0);
  gm->addEdge(1, 3, 2.0);
  gm->addEdge(4, 5, 1.0);

  Floyd f(gm);
  CPPUNIT_ASSERT_EQUAL(1.3, f.getAverageDist());

  Graph *gl = new GraphList(3, true);
  gl->addEdge(1, 2, 2.0);
  gl->addEdge(2, 3, 2.0);
  gl->addEdge(1, 3, 2.0);

  Floyd _f(gl);
  CPPUNIT_ASSERT_EQUAL(4.0, _f.getAverageDist());

  delete gl;
  delete gm;
}
