CC=g++
CFLAGS=-std=c++11 -g -O2
a.out: whatday.cpp lib.cpp
	$(CC) -o a.out whatday.cpp lib.cpp $(CFLAGS)
