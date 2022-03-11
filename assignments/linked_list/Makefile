main: main.o Node.o List.o OList.o ONode.o
	g++ -o main main.o Node.o List.o OList.o ONode.o

test: test.cpp Node.o List.o Olist.o ONode.o
	g++ -o main main.o Node.o List.o OList.o ONode.o

main.o: main.cpp Node.h List.h OList.h ONode.h

List.o: List.cpp List.h Node.h 

OList.o: OList.cpp OList.h ONode.h

Node.o: Node.cpp Node.h

ONode.o: ONode.cpp ONode.h

clean:
	rm -f *.o *~
