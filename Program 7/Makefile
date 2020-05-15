all: matrix main 
	g++ Matrix.o main.o -o out
matrix: Matrix.cpp
	g++ -c Matrix.cpp
main: main.cpp
	g++ -c main.cpp
clean:
	rm *.o out
	