#ifndef LISTA_ENCADEADA_H

    #define LISTA_ENCADEADA_H

    #include "caminhoCidade.h"

    #include <stdbool.h>

    #define inicial 0
    #define ERRO -32000
    #define TAM_MAX 12

    typedef struct listaEncadeada_ LISTA_ENCADEADA;

    LISTA_ENCADEADA *listaEncadeada_criar(void);
    bool listaEncadeada_inserir(LISTA_ENCADEADA *listaEncadeada, CAMINHO_CIDADE *caminhoCidade);
    void listaEncadeada_apagar(LISTA_ENCADEADA **listaEncadeada); 
    int listaEncadeada_busca(LISTA_ENCADEADA *listaEncadeada, int chave);
    int listaEncadeada_tamanho(LISTA_ENCADEADA *listaEncadeada);
    bool listaEncadeada_vazia(LISTA_ENCADEADA *listaEncadeada);
    bool listaEncadeada_cheia(LISTA_ENCADEADA *listaEncadeada);
    void listaEncadeada_imprimir(LISTA_ENCADEADA *listaEncadeada);

#endif