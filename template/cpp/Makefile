TARGET="$F.cpp"
CC=g++
CFLAGS=-std=c++11 -g -O2

# build task specified by env $F
build:
	$(CC) -o a.out $(TARGET) $(CFLAGS)

# test run program with input from $F_input.txt, print to stdout
test: build
	cat $F_input.txt | ./a.out;
	rm a.out

# build and run based on input
run: build
	cat $F_input.txt | ./a.out > output.txt;
	rm a.out

help: ## This help.
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

.PHONY: help
