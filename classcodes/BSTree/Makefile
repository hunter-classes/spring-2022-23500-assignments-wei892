BJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: main.o BSTree.o Node.o
	g++ -o main main.o BSTree.o Node.o

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h

clean:
	rm -f $(OBJECTS)
