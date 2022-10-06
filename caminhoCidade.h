#ifndef CAMINHO_CIDADE_H
	#define CAMINHO_CIDADE_H

	#include <stdio.h>
	#include <stdbool.h> 
	#include <stdlib.h>

	typedef struct caminhoCidade_ CAMINHO_CIDADE;

	CAMINHO_CIDADE *caminhoCidade_criar(int cidadeOrigem, int cidadeDestino, int distancia);
	bool caminhoCidade_apagar(CAMINHO_CIDADE **caminhoCidade);
    int caminhoCidade_getCidadeOrigem(CAMINHO_CIDADE *caminhoCidade);
    int caminhoCidade_getCidadeDestino(CAMINHO_CIDADE *caminhoCidade);
	int caminhoCidade_getDistancia(CAMINHO_CIDADE *caminhoCidade);
    bool caminhoCidade_getVisitada(CAMINHO_CIDADE *caminhoCidade);
    bool caminhoCidade_setVisitada(CAMINHO_CIDADE *caminhoCidade);

#endif
