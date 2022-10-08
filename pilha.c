#include "pilha.h"

struct pilha{
    CIDADE *cidades[TAM_MAX]; // Array que contem os ponteiros para os itens 
    int tamanho; // Topo da pilha
};

// Criando uma Pilha 
PILHA *pilha_criar(void){
    PILHA *pilha;
    pilha = (PILHA*) malloc(sizeof(PILHA));
    if(pilha != NULL)
        pilha->tamanho = 0;
    return pilha;
}

void pilha_apagar(PILHA **pilha){
    free(*pilha);
    pilha == NULL;
}

// Verificando se a Pilha esta vazia
bool pilha_vazia(PILHA *pilha){
    if(pilha != NULL)
        if(pilha->tamanho == 0)
            return true;
    return false;
}

// Verificando se a Pilha esta cheia 
bool pilha_cheia(PILHA *pilha){
    if(pilha != NULL)
        if(pilha->tamanho == TAM_MAX)
            return true;
    return false;
}

// Retornando a quantidade de elementos da pilha
int pilha_tamanho(PILHA *pilha){
    if(pilha == NULL)
        return -1;
    return pilha->tamanho;
}

// Retorno mas não apagando o elemento do topo da pilha
CIDADE *pilha_topo(PILHA *pilha){
    if(pilha == NULL)
        return NULL;
    return pilha->cidades[pilha->tamanho-1];
}

// Empilhando um item na pilha
bool pilha_empilhar(PILHA *pilha, CIDADE *cidade){
    if(pilha != NULL && !pilha_cheia(pilha)){
        pilha->cidades[pilha->tamanho] = cidade;
        pilha->tamanho++;
        return true;
    }
    return false;
}

// Desempilhando o último itema da pilha
CIDADE *pilha_desempilhar(PILHA *pilha){
    if(pilha != NULL && !pilha_vazia(pilha)){
        CIDADE *cidadeAux = pilha_topo(pilha); // Copiando item para uma variavel auxiliar
        pilha->cidades[pilha->tamanho-1] == NULL; /* Tirando item da pilha (obs.: A responsabilidade de 
apagar o item da memoria eh do programa usuario) */
        pilha->tamanho--;
        return (cidadeAux);
    }
    return NULL;
}