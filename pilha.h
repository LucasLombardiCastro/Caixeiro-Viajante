#ifndef PILHA_H
    #define PILHA_H

    #include "cidade.h"
    #define TAM_MAX 12

    #include <stdbool.h>

    typedef struct pilha PILHA; 

    PILHA *pilha_criar(void);
    void pilha_apagar(PILHA **pilha);
    bool pilha_vazia(PILHA *pilha);
    bool pilha_cheia(PILHA *pilha);
    int pilha_tamanho(PILHA *pilha);
    CIDADE *pilha_topo(PILHA *pilha);
    bool pilha_empilhar(PILHA *pilha, CIDADE *cidade);
    CIDADE *pilha_desempilhar(PILHA *pilha);
    
#endif