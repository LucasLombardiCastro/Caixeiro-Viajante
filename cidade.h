#ifndef CIDADE_H
	#define CIDADE_H
	
    #include "listaEncadeada.h"
    
	#include <stdio.h>
	#include <stdbool.h>
	#include <stdlib.h>

	typedef struct cidade_ CIDADE;

	CIDADE *cidade_criar(int chave, LISTA_ENCADEADA *proximasCidades);
	bool cidade_apagar(CIDADE **cidade);
	int cidade_getChave(CIDADE *cidade);
    bool cidade_getVisitada(CIDADE *cidade);
    bool cidade_setVisitada(CIDADE *cidade);
	LISTA_ENCADEADA *cidade_getListaEncadeada(CIDADE *cidade);

#endif
