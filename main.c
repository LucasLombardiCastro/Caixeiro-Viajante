#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "listaSequencial.h"

void preencheLista(LISTA_SEQUENCIAL *listaSequencial, int quantidadeCidades);
void entradaDados(CAMINHO_CIDADE *caminhoCidade, LISTA_SEQUENCIAL *listaSequencial);

int main(void){
    LISTA_SEQUENCIAL *listaSequencial = listaSequencial_criar();
    CAMINHO_CIDADE *caminhoCidade;

    int quantidadeCidades;
    scanf("%d", &quantidadeCidades);

    int cidadeOrigem;
    scanf("%d", &cidadeOrigem);

    //Entrada de dados e insercao dos mesmos nos TADs listaSequencial e listaEncadeada
    preencheLista(listaSequencial, quantidadeCidades);
    entradaDados(caminhoCidade, listaSequencial);
    
    //Para Teste: Imprimindo listas encadeadas associadas as n cidades
    for(int i = 1; i <= quantidadeCidades; ++i){
        printf("Cidade %d:\n", i);
        listaEncadeada_imprimir(cidade_getListaEncadeada(listaSequencial_busca(listaSequencial, i)));
    }

    listaSequencial_apagar(&listaSequencial);
    caminhoCidade_apagar(&caminhoCidade);
    return 0;
}

void preencheLista(LISTA_SEQUENCIAL *listaSequencial, int quantidadeCidades){ //Funcao para preencher a listaSequencial com as cidades
    if(listaSequencial != NULL){
        LISTA_ENCADEADA *listaEncadeada; 
        for(int i = 1; i <= quantidadeCidades; ++i){
            listaEncadeada = listaEncadeada_criar();
            listaSequencial_inserir(listaSequencial,cidade_criar(i, listaEncadeada));
        }
    }
}

void entradaDados(CAMINHO_CIDADE *caminhoCidade, LISTA_SEQUENCIAL *listaSequencial){
    int cidadeOrigemAtual, cidadeDestinoAtual, distancia;
    while(scanf("%d %d %d", &cidadeOrigemAtual, &cidadeDestinoAtual, &distancia) != EOF){
        //Criando uma caminho entre cidades dadas, e inserindo na listaEncadeada associada ao Elemento da ListaSequencial da cidadeOrigem
        caminhoCidade = caminhoCidade_criar(cidadeOrigemAtual, cidadeDestinoAtual, distancia);
        listaEncadeada_inserir(cidade_getListaEncadeada(listaSequencial_busca(listaSequencial, cidadeOrigemAtual)), caminhoCidade);

        //Criando uma caminho entre cidades dadas, e inserindo na listaEncadeada associada ao Elemento da ListaSequencial da cidadeDestino
        caminhoCidade = caminhoCidade_criar(cidadeDestinoAtual, cidadeOrigemAtual, distancia);
        listaEncadeada_inserir(cidade_getListaEncadeada(listaSequencial_busca(listaSequencial, cidadeDestinoAtual)), caminhoCidade);
    }
}