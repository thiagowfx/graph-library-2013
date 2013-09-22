CPPFLAGS = -Wall -Wextra -g -lm -O2

graph_test: graph.cpp graph_test.cpp graph.h
	g++ $^ -o $@ $(CPPFLAGS)

test:
	./graph_test
	rm tmp.txt

view:
	less output.txt
