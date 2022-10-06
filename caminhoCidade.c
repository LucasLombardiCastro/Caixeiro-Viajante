#include <stdlib.h>
#include <stdio.h>
#include "caminhoCidade.h"

struct caminhoCidade_{
    int cidadeOrigem;
    int cidadeDestino;
    int distancia;
    bool visitada;
};

CAMINHO_CIDADE *caminhoCidade_criar(int cidadeOrigem, int cidadeDestino, int distancia){
    CAMINHO_CIDADE *caminhoCidade;
          
    caminhoCidade = (CAMINHO_CIDADE *) malloc(sizeof(CAMINHO_CIDADE));
    
    if (caminhoCidade != NULL){
        caminhoCidade->distancia = distancia;
        caminhoCidade->cidadeOrigem = cidadeOrigem;
        caminhoCidade->cidadeDestino = cidadeDestino;
        return(caminhoCidade);
    }
    return(NULL);
}

bool caminhoCidade_apagar(CAMINHO_CIDADE **caminhoCidade){
    if (*caminhoCidade != NULL){
        free (*caminhoCidade);
        *caminhoCidade = NULL; 
        return(true);
    }
   return(false);
}

int caminhoCidade_getCidadeOrigem(CAMINHO_CIDADE *caminhoCidade){
    if(caminhoCidade != NULL)
        return (caminhoCidade->cidadeOrigem);
    exit(1); 
}

int caminhoCidade_getCidadeDestino(CAMINHO_CIDADE *caminhoCidade){
    if(caminhoCidade != NULL)
        return (caminhoCidade->cidadeDestino);
    exit(1); 
}

int caminhoCidade_getDistancia(CAMINHO_CIDADE *caminhoCidade){
    if(caminhoCidade != NULL)
        return (caminhoCidade->distancia);
    exit(1); 
}

bool caminhoCidade_getVisitada(CAMINHO_CIDADE *caminhoCidade){
    if(caminhoCidade != NULL)
        return (caminhoCidade->visitada);
    exit(1); 
}

bool caminhoCidade_setVisitada(CAMINHO_CIDADE *caminhoCidade){
    if(caminhoCidade != NULL){
        caminhoCidade->visitada = !(caminhoCidade->visitada);
        return (true);
  }
  return (false);
}