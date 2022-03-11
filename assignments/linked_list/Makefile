main: main.o Node.o List.o
	g++ -o main main.o Node.o List.o

main.o: main.cpp Node.h List.h

List.o: List.cpp List.h Node.h

Node.o: Node.cpp Node.h

clean:
	rm -f *.o *~
