#include "listaSequencial.h"

struct listaSequencial_ {
	CIDADE *lista[TAM_MAX]; //Vetor de TAD Cidade com tamanho TAM_MAX
	int inicio; //Inicio da Lista
	int fim; //Primeira posicao livre para insercao de dados
};

LISTA_SEQUENCIAL *listaSequencial_criar(void){
	LISTA_SEQUENCIAL *listaSequencial = (LISTA_SEQUENCIAL *) malloc(sizeof(LISTA_SEQUENCIAL));
	if (listaSequencial != NULL){
		listaSequencial->inicio = inicial;
		listaSequencial->fim = listaSequencial->inicio; //Lista vazia
	}
	return (listaSequencial);
}

//Inserindo um elemento no final da lista sequencial
bool listaSequencial_inserir(LISTA_SEQUENCIAL *l, CIDADE *cidade){
	int fim;
    if ((l != NULL) && !listaSequencial_cheia(l)){
        (l->lista[l->fim]) = cidade;
        l->fim++;
        return(true);
    }
	return(false);
}

void listaSequencial_apagar(LISTA_SEQUENCIAL **listaSequencial){
	int i, j;
	LISTA_ENCADEADA *listaEncadeada; //Apagando a listaEncadeada que esta ligada a cada elemento da listaSequencial

	if(*listaSequencial == NULL) 
		return;

	j = listaSequencial_tamanho(*listaSequencial); // Variavel Auxiliar
	for(i=0; i<j; i++){
		listaEncadeada = cidade_getListaEncadeada((*listaSequencial)->lista[i]); 
		listaEncadeada_apagar(&listaEncadeada); //Apagando a listaEncadeada associada ao elemento da listaSequencial[i]
		cidade_apagar(&(*listaSequencial)->lista[i]); //Apagando a cidade da listaSequencial[i];
	}

	free(listaEncadeada);
	free(*listaSequencial);
	*listaSequencial = NULL;
}

int listaSequencial_tamanho(LISTA_SEQUENCIAL *listaSequencial){
	return(listaSequencial->fim);
}

bool listaSequencial_vazia(LISTA_SEQUENCIAL *listaSequencial){
	return(listaSequencial->inicio == listaSequencial->fim);
}

bool listaSequencial_cheia(LISTA_SEQUENCIAL *listaSequencial){
	if(listaSequencial->fim >= TAM_MAX){
		return(true);
	}
	return(false);
}

void listaSequencial_imprimir(LISTA_SEQUENCIAL *l){
	for(int i=0; i < l->fim; i++)
		printf("Posicao: %d Cidade[%d]\n", i, cidade_getChave(l->lista[i]));
}

CIDADE *listaSequencial_busca(LISTA_SEQUENCIAL *l, int chave){
	for(int i = 0; i < l->fim; ++i) //Realizando a busca sequencial dado uma chave
		if(cidade_getChave(l->lista[i]) == chave)
			return (l->lista[i]);
}