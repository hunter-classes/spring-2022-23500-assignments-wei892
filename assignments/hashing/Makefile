main: main.o Person.o Node.o List.o
	g++ -o main main.o Person.o Node.o List.o

tests: tests.o Person.o Node.o List.o
	g++ -o tests tests.o Person.o Node.o List.o

Person.o: Person.cpp Person.h

Node.o: Node.cpp Node.h Person.h

List.o: List.cpp List.h Node.h Person.h

clean:
	rm -f *.o *~
