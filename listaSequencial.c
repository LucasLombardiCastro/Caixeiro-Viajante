#include "listaSequencial.h"

struct listaSequencial_ {
	CIDADE *lista[TAM_MAX];
	int inicio; //inicio da lista
	int fim; //fim da lista -1a posicao livre para insercao
};

LISTA_SEQUENCIAL *listaSequencial_criar(void){
	LISTA_SEQUENCIAL *listaSequencial = (LISTA_SEQUENCIAL *) malloc(sizeof(LISTA_SEQUENCIAL));
	if (listaSequencial != NULL){
		listaSequencial->inicio = inicial;
		listaSequencial->fim = listaSequencial->inicio; /*lista vazia*/
	}
	return (listaSequencial);
}

// insere um elemento no fim da lista não ordenada // 
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
	if(*listaSequencial == NULL){
		return;
	}
	j = listaSequencial_tamanho(*listaSequencial);
	for(i=0; i<j; i++){
		cidade_apagar(&(*listaSequencial)->lista[i]);
	}
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
	for(int i = 0; i < l->fim; ++i){
		if(cidade_getChave(l->lista[i]) == chave){
			return (l->lista[i]);
		}
	}
}