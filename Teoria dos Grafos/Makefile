CPPFLAGS = -Wall -Wextra -g

graph_test: graph.cpp graph_test.cpp graph.h
	g++ $^ -o $@ $(CPPFLAGS)

test:
	./graph_test input3.txt
	[[ -e tmp_file.txt ]] && rm tmp_file.txt

view:
	less output.txt
