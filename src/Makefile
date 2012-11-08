CPP = g++
CFLAGS = g++

BUILD = ../build

$(BUILD)/ntest: node_test.cpp Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/ntest node_test.cpp Node.o

$(BUILD)/atest:	avl_test.cpp AVL.o Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/atest avl_test.cpp AVL.o Node.o

Node.o:	Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp

AVL.o: AVL.h AVL.cpp
	$(CPP) $(CFLAGS) -c AVL.cpp

clean:
	rm -f *.o
	rm -f *~
