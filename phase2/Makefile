CC=gcc
CFLAGS=-I.
DEPS = function_def.h
OBJ = functions.o main.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

a: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


