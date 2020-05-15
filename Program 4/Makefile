all: graph test
	g++ Graph.o GraphTest.o -o out
graph:
	g++ -c Graph.cpp
test:
	g++ -c GraphTest.cpp
clean:
	rm GraphTest.o Graph.o out