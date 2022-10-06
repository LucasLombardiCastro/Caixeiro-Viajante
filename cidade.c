#include <stdlib.h>
#include <stdio.h>
#include "cidade.h"

struct cidade_{ 
    int chave;
    LISTA_ENCADEADA *proximasCidades;
    bool visitada; /* 0 -> Nao visitada   1 -> Visitada */
};

CIDADE *cidade_criar(int chave, LISTA_ENCADEADA *proximasCidades){
          CIDADE *cidade;
          
          cidade = (CIDADE *) malloc(sizeof(CIDADE));
          
          if (cidade != NULL){
             cidade->chave = chave;
             cidade->proximasCidades = proximasCidades;
             cidade->visitada = 0;
             return(cidade);
          }
          return(NULL);
}

bool cidade_apagar(CIDADE **cidade){
   if (*cidade != NULL){
      free (*cidade);
      *cidade = NULL; 
      return(true);
   }
   return(false);
}

int cidade_getChave(CIDADE *cidade){
    if (cidade != NULL)
      return(cidade->chave);
    exit(1);
}


bool cidade_getVisitada(CIDADE *cidade){
  if (cidade != NULL)
      return(cidade->visitada);
    exit(1);
}


bool cidade_setVisitada(CIDADE *cidade){
    if(cidade != NULL){
    cidade->visitada = !(cidade->visitada);
    return (true);
  }
  return (false);
}

LISTA_ENCADEADA *cidade_getListaEncadeada(CIDADE *cidade){
  if(cidade != NULL)
    return (cidade->proximasCidades);
  return NULL;
}
