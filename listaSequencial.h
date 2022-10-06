#ifndef LISTA_SEQUENCIAL_H

    #define LISTA_SEQUENCIAL_H
    #include <stdbool.h>

    #include "cidade.h"
    #define TAM_MAX 12
    #define inicial 0
    #define ERRO -32000

    typedef struct listaSequencial_ LISTA_SEQUENCIAL;

    LISTA_SEQUENCIAL *listaSequencial_criar(void);
    bool listaSequencial_inserir(LISTA_SEQUENCIAL *listaSequencial, CIDADE *cidade);
    void listaSequencial_apagar(LISTA_SEQUENCIAL **listaSequencial);
    int listaSequencial_tamanho(LISTA_SEQUENCIAL *listaSequencial);
    bool listaSequencial_vazia(LISTA_SEQUENCIAL *listaSequencial);
    bool listaSequencial_cheia(LISTA_SEQUENCIAL *listaSequencial);
    void listaSequencial_imprimir(LISTA_SEQUENCIAL *listaSequencial);
    CIDADE *listaSequencial_busca(LISTA_SEQUENCIAL *l, int chave);

#endif