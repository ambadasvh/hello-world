CXX=g++
CFLAGS=-g -Wall
RM=/bin/rm -f
INCDIR=../include/
INC=-I. -I$(INCDIR)
LIBS=

BIN=msg

all: $(BIN)

main.o: $(INCDIR)test.h main.cpp
	$(CXX) $(CFLAGS) $(INC) -c main.cpp

test_1.o: $(INCDIR)test.h test_1.cpp
	$(CXX) $(CFLAGS) $(INC) -c test_1.cpp

$(BIN): main.o test_1.o
	$(CXX) $(CFLAGS) $(INC) -o $(BIN) main.o test_1.o

clean:
	$(RM) *.o $(BIN)

