all: arrayList main
	g++ ArrayList.o main.o -o out
arrayList: ArrayList.cpp
	g++ -c ArrayList.cpp
main: main.cpp
	g++ -c main.cpp
clean:
	rm *.o out