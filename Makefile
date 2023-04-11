CFLAGS = -Wall -g -O2 -std=c99 -Wno-unused-result
LIB = leitura.o liblistacarect.o liblistanum.o libimprimir.o libseparar.o libcodificar.o

all: main

main: main.o $(LIB)
	gcc $(CFLAGS) main.o $(LIB) -o beale

liblistacarect.o: liblistacarect.c liblistacarect.h
	gcc $(CFLAGS) -c liblistacarect.c

liblistanum.o: liblistanum.c liblistanum.h
	gcc $(CFLAGS) -c liblistanum.c

libimprimir.o: libimprimir.c libimprimir.h
	gcc $(CFLAGS) -c libimprimir.c

libseparar.o: libseparar.c libseparar.h
	gcc $(CFLAGS) -c libseparar.c

libcodificar.o: libcodificar.c libcodificar.h
	gcc $(CFLAGS) -c libcodificar.c

leitura.o: leitura.c leitura.h
	gcc $(CFLAGS) -c leitura.c

main.o : main.c 
	gcc $(CFLAGS) -c main.c

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf beale