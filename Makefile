CFLAGS = -Wall -g -O2 -std=c99 -Wno-unused-result
LIB = libleitura.o liblistacarect.o liblistanum.o libimprimir.o libcodificar.o libdecodificar.o

all: main

main: main.o $(LIB)
	gcc $(CFLAGS) main.o $(LIB) -o beale

liblistacarect.o: liblistacarect.c liblistacarect.h
	gcc $(CFLAGS) -c liblistacarect.c

liblistanum.o: liblistanum.c liblistanum.h
	gcc $(CFLAGS) -c liblistanum.c

libimprimir.o: libimprimir.c libimprimir.h
	gcc $(CFLAGS) -c libimprimir.c

libcodificar.o: libcodificar.c libcodificar.h
	gcc $(CFLAGS) -c libcodificar.c

libdecodificar.o: libdecodificar.c libdecodificar.h
	gcc $(CFLAGS) -c libdecodificar.c

libleitura.o: libleitura.c libleitura.h
	gcc $(CFLAGS) -c libleitura.c

main.o : main.c 
	gcc $(CFLAGS) -c main.c

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf beale
