all: hello try .PHONY
	
.PHONY: clean

CC = gcc
CFLAGS = -Wall -Wextra -g
	
hello:
	echo "Hello, make!"

try:
	echo "This is a small try from makefile"
	# $(CC) $(CFLAGS) -c test.cpp -o test.exe
	./test

clean:
	rm -f ./*.[exe,o]