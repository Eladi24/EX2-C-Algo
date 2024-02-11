CC=gcc
AR=ar
OBJECTS_MAING=my_graph.o
OBJECTS_MAINK=my_Knapsack.o
OBJECTS_LIB=my_mat.o
FLAGS= -Wall -g
CFLAGS= -Wall -fPIC
#libclassmat.a

all: my_graph my_Knapsack
my_graph: $(OBJECTS_MAING) libclassmat.a
	$(CC) $(FLAGS) -o my_graph $(OBJECTS_MAING) libclassmat.a
my_Knapsack: $(OBJECTS_MAINK) libclassmat.a
	$(CC) $(FLAGS) -o my_Knapsack $(OBJECTS_MAINK) libclassmat.a
libclassmat.a: $(OBJECTS_LIB)
	$(AR) -rcs libclassmat.a $(OBJECTS_LIB)
$(OBJECTS_MAING): my_graph.c my_mat.h
	gcc -c my_graph.c
$(OBJECTS_MAINK): my_Knapsack.c my_mat.h
	$(CC) -c my_Knapsack.c
$(OBJECTS_LIB): my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c
.PHONY: clean all

clean:
	rm -f *.o *.a *.so my_graph my_Knapsack
