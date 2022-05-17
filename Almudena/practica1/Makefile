FLAGS = -Wall -Wextra

all: main ficheros estandar

main: ficheros estandar menu.c 
	gcc $(FLAGS) menu.c estandar.o ficheros.o -I ./ -o main.bin
	rm -f *.o

ficheros: ficheros.h ficheros.c
	gcc $(FLAGS) -c ficheros.c -I ./ -o ficheros.o

estandar: estandar.h estandar.c
	gcc $(FLAGS) -c estandar.c -I ./ -o estandar.o
