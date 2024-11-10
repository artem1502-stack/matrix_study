all: our_program

our_program: main.o fun.o gauss.o det.o
	@gcc -o our_program main.o fun.o gauss.o det.o

main.o: main.c
	@gcc -c main.c

gauss.o: gauss.c
	@gcc -c gauss.c

fun.o: fun.c
	@gcc -c fun.c

det.o: det.c
	@gcc -c det.c

linal.o: linal.c
	@gcc -c linal.c
