CPPFILES = LinkedList.cpp testCase1.cpp testCase2.cpp testCase3.cpp testCase4.cpp testCase5.cpp main.cpp

HFILES = $(CPPFILES:.cpp=.h)

OFILES= $(CPPFILES:.cpp=.o)

CC = g++

all: LinkedListTest

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

LinkedListTest:$(OFILES)
	$(CC) -o LinkedListTest $(OFILES)
	rm *.o

clean:
	rm *.o
	rm LinkedListTest
	rm *.stackdump
