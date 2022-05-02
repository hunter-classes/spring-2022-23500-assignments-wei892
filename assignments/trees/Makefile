main: main.o Node.o Tree.o
	g++ -o main main.o Node.o Tree.o

tests: tests.o Node.o Tree.o
	g++ -o tests tests.o Node.o Tree.o

main.o: main.cpp Node.h Tree.h

tests.o: tests.cpp Node.h Tree.h

Node.o: Node.cpp Node.h

Tree.o: Tree.cpp Tree.h

clean:
	rm -f *.o *~
