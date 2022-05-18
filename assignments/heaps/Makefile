main: main.o heap.o
	g++ -o main main.o heap.o

tests: tests.o heap.o
	g++ -o tests tests.o heap.o

heap.o: heap.cpp heap.h

clean:
	rm -f *~ *.o

