CC=g++
CFLAGS=-c -g -std=c++11

all: main

archive:
	-tar -cf hw5.tar main.cpp graph.cpp graph.h input.txt result.txt Makefile

main: main.o graph.o
	$(CC) main.o graph.o -o main 

main.o: main.cpp graph.h
	$(CC) $(CFLAGS) main.cpp 
	
graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) graph.cpp

clean:
	rm -rf *o main
