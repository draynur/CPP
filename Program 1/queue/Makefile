all: queue main
	g++ Queue.o QueueTest.o -o out
queue: Queue.cpp
	g++ -c Queue.cpp
main: QueueTest.cpp
	g++ -c QueueTest.cpp
clean:
	rm -f *.o out
