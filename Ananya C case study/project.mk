a.exe : functions.o main.o
	gcc functions.o main.o

main.o : main.c function_def.h
	gcc -c main.c