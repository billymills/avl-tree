CPP = g++
CFLAGS = g++

BUILD = ../build

$(BUILD)/ntest: node_test.cpp Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/ntest node_test.cpp Node.o

Node.o:	Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp

clean:
	rm -f *.o
	rm -f *~
