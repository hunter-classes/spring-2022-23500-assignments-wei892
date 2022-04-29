main: main.o Node.o List.o stack.o queue.o
	g++ -o main main.o Node.o List.o stack.o queue.o

tests: tests.o Node.o List.o stack.o queue.o
	g++ -o tests tests.o Node.o List.o stack.o queue.o

main.o: main.cpp Node.h List.h stack.h queue.h

tests.o: tests.cpp Node.h List.h stack.h queue.h

Node.o: Node.cpp Node.h

List.o: List.cpp List.h Node.h

stack.o: stack.cpp stack.h List.h

queue.o: queue.cpp queue.h

clean: 
	rm -f *.o *~
