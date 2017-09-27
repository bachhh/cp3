CC=g++
CFLAGS=-std=c++11 -g
a.out: whatday.cpp lib.cpp
	$(CC) -o a.out whatday.cpp lib.cpp $(CFLAGS)
