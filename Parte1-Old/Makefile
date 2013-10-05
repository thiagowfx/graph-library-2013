CPPFLAGS = -Wall -Wextra -g -lm -O2

graph_test: graph.cpp graph_test.cpp graph.h
	g++ $^ -o $@ $(CPPFLAGS)

estudo1: graph.cpp estudo1.cpp graph.h
	g++ $^ -o $@ $(CPPFLAGS)

estudo2: graph.cpp estudo2.cpp graph.h
	g++ $^ -o $@ $(CPPFLAGS)

test:
	make
	./graph_test

clean:
	rm tmp.txt
	rm output.exp
