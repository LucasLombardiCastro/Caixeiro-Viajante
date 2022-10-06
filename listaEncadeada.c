#include "listaEncadeada.h"

typedef struct no_ NO;
struct no_{
	CAMINHO_CIDADE *caminhoCidade;
	NO *proximo;
};

struct listaEncadeada_{
	NO *inicio;
	NO *fim;
	int tamanho; 
};

LISTA_ENCADEADA *listaEncadeada_criar(void){
    LISTA_ENCADEADA *listaEncadeada = (LISTA_ENCADEADA *) malloc(sizeof(LISTA_ENCADEADA));
	    if(listaEncadeada != NULL) {
		    listaEncadeada->inicio = NULL;
		    listaEncadeada->fim = NULL;
		    listaEncadeada->tamanho = 0;
	    }
	return (listaEncadeada);
}

int listaEncadeada_busca(LISTA_ENCADEADA *listaEncadeada, int chave){
	// Buscando o primeiro caminhoCidade ainda nao visitado
	NO *p;
	if (listaEncadeada != NULL){
		p = listaEncadeada->inicio;
		while(caminhoCidade_getVisitada(p->caminhoCidade) && (p != NULL)){
			p = p->proximo;
		}
		if(p != NULL)
			return(caminhoCidade_getCidadeDestino(p->caminhoCidade));
	}
	return(ERRO);
}

// Insere um novo nó no FIM da LISTA_ENCADEADA → LISTA_ENCADEADAs NÃO ORDENADAS //
bool listaEncadeada_inserir(LISTA_ENCADEADA *listaEncadeada, CAMINHO_CIDADE *caminhoCidade){
	if ((!listaEncadeada_cheia(listaEncadeada)) && (listaEncadeada != NULL)) {
		NO *pnovo = (NO *) malloc(sizeof (NO));
		pnovo->caminhoCidade = caminhoCidade;
		pnovo->proximo = NULL;
		
		if(listaEncadeada->inicio == NULL){ //se estiver vazia, o inicio aponta para o 1o nó
			listaEncadeada->inicio = pnovo;
		} else { //ajustar o ponteiro do fim e o que aponta para o próximo
			listaEncadeada->fim->proximo = pnovo;
		}

		listaEncadeada->fim = pnovo;
		listaEncadeada->tamanho++; 
		
		return(true);
	} else {
		return(false);
	}
}

int listaEncadeada_tamanho(LISTA_ENCADEADA *listaEncadeada){
	return(listaEncadeada->tamanho);
}

bool listaEncadeada_cheia(LISTA_ENCADEADA *listaEncadeada){
	NO *no = (NO *) malloc(sizeof(NO));
	if(no != NULL){
		free(no);
		no = NULL;
		return(false);
	}
	return(true);
}

bool listaEncadeada_vazia(LISTA_ENCADEADA *listaEncadeada){
    if(listaEncadeada->fim == listaEncadeada->inicio){
		return(true);
	}
	return(false);
}

void listaEncadeada_apagar(LISTA_ENCADEADA **listaEncadeada){
   NO* atual = (*listaEncadeada)->inicio;
   NO* proximo;
 
   while(atual != NULL){
       proximo = atual->proximo;
       free(atual);
       atual = proximo;
   }
   atual = NULL;
}

void listaEncadeada_imprimir(LISTA_ENCADEADA *listaEncadeada){
	NO *noAtual = listaEncadeada->inicio;
	for(int i = 1; i <= listaEncadeada->tamanho; ++i){
		printf("De %d Para %d --> Distancia: %d \n", caminhoCidade_getCidadeOrigem(noAtual->caminhoCidade), caminhoCidade_getCidadeDestino(noAtual->caminhoCidade), caminhoCidade_getDistancia(noAtual->caminhoCidade));
		noAtual = noAtual->proximo;
	}
}