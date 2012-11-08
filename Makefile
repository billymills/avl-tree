CPP = g++
CFLAGS = -Wall -Wextra

SRC = ./src
BUILD = ./build


$(BUILD)/ntest:	$(SRC)/node_test.cpp $(SRC)/Node.o
	$(CPP) $(CFLAGS) -o $(BUILD)/ntest $(SRC)/node_test.cpp $(SRC)/Node.o


clean:
	rm -f *.o
	rm -f *~
	cd $(SRC); $(MAKE) clean
	cd $(BUILD); rm -f ntest
