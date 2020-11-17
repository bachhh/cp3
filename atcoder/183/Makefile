TARGET="$F"
CC=g++
CFLAGS=-std=c++11 -g -O2 -w

.PHONY: help

.DEFAULT_GOAL := help

usage="make -F <target>"

help: ## This help.
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)


build: ## build target with provided flags
	@$(CC) -o a.out $(TARGET).cpp $(CFLAGS)

test: build ## test run program with input from $F_input.txt, print to stdout
	@cat "$(TARGET)_input.txt" | ./a.out;

run: build ## build and run based on input
	@cat "$(TARGET)_input.txt" | ./a.out > output.txt;

clean:
	rm a.out
