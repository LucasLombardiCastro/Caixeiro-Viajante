all: caminhoCidade.o listaEncadeada.o cidade.o listaSequencial.o pilha.o main.o
	gcc caminhoCidade.o listaEncadeada.o cidade.o listaSequencial.o pilha.o main.o -o caixeiroViajante -std=c99 -Wall -g

caminhoCidade.o:
	gcc -c caminhoCidade.c -o caminhoCidade.o

listaEncadeada.o:
	gcc -c listaEncadeada.c -o listaEncadeada.o

cidade.o:
	gcc -c cidade.c -o cidade.o

listaSequencial.o:
	gcc -c listaSequencial.c -o listaSequencial.o

pilha.o:
	gcc -c pilha.c -o pilha.o

main.o:
	gcc -c main.c -o main.o
	  
clean:
	rm *.o caixeiroViajante

run:
	valgrind ./caixeiroViajante