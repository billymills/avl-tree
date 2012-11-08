CPP = g++
CFLAGS = -Wall -Wextra

SRC = ./src
BUILD = ./build

all: $(BUILD)/ntest $(BUILD)/atest

$(BUILD)/ntest:	$(SRC)/node_test.cpp $(SRC)/Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/ntest $(SRC)/node_test.cpp $(SRC)/Node.o

$(BUILD)/atest: $(SRC)/avl_test.cpp $(SRC)/AVL.o $(SRC)/Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/atest $(SRC)/avl_test.cpp $(SRC)/AVL.o $(SRC)/Node.o

clean:
	rm -f *.o
	rm -f *~
	cd $(SRC); $(MAKE) clean
	cd $(BUILD); rm -f ntest
	cd $(BUILD); rm -f atest
