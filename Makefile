all: caminhoCidade.o listaEncadeada.o cidade.o listaSequencial.o main.o
	gcc caminhoCidade.o listaEncadeada.o cidade.o listaSequencial.o main.o -o caixeiroViajante -std=c99 -Wall

caminhoCidade.o:
	gcc -c caminhoCidade.c -o caminhoCidade.o

listaEncadeada.o:
	gcc -c listaEncadeada.c -o listaEncadeada.o

cidade.o:
	gcc -c cidade.c -o cidade.o

listaSequencial.o:
	gcc -c listaSequencial.c -o listaSequencial.o

main.o:
	gcc -c main.c -o main.o
	  
clean:
	rm *.o caixeiroViajante

run:
	./caixeiroViajante