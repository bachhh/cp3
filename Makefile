CC=g++
CFLAGS=-std=c++11 -g -O2

all:
	${CC} ${FILE} -o a.out ${CFLAGS}

