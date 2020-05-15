all: stack main
	g++ Stack.o StackTest.o -o out
stack: Stack.cpp
	g++ -c Stack.cpp
main: StackTest.cpp
	g++ -c StackTest.cpp
clean:
	rm -f *.o out
