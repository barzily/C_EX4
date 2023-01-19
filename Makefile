CC = gcc
FLAGS = -Wall -g
AR = ar
.PHONY: clean all

graph: main.o graphlib.a
	$(CC) $(FLAGS) -o graph main.o graphlib.a

main.o: main.c graph.h 
	$(CC) $(FLAGS) -c main.c 

Dijkstra.o: algo.c graph.h
	$(CC) $(FLAGS) -c algo.c

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

graphlib.a: algo.o graph.o
	$(AR) -rcs graphlib.a algo.o graph.o

all: graph
clean: 
	rm -f *.o *.a graph


