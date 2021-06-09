#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "josephus.h"

struct elemento {
	struct js dados;
	struct elemento *prox;
};

typedef struct elemento Elem;

Lista *cria_lista(){
	Lista *li = (Lista*)malloc(sizeof(Lista));
	if(li != NULL)
		*li = NULL;
	return li;
}

void libera_lista(Lista *li){
	if(li != NULL && (*li) != NULL){
		Elem *aux, *no = *li;
		while((*li) != no->prox){
			aux = no;
			no = no->prox;
			free(aux);
		}
		free(no);
		free(li);
	}
}

void imprime_lista(Lista *li){
	if(li == NULL)
		printf("lista nao existe\n");
	else if((*li) == NULL)
		printf("lista vazia\n");
	else{
		Elem *aux = *li;
		do{
			printf(" %c ", aux->dados.letra_nome);
			aux = aux->prox;
		}while(aux != (*li));
		printf("\n");
	}
}

bool insere_lista_final(Lista *li, struct js dado){
	if(li == NULL)
		return 0;
	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL)
		return 0;
	no->dados = dado;
	if((*li) == NULL){
		*li = no;
		no->prox = no;
	}
	else{
		Elem *aux = *li;
		while(aux->prox != (*li))
			aux = aux->prox;

		aux->prox = no;
		no->prox = *li;
	}

	return 1;
}

bool josephus(Lista *li, int num, char let){
	if()
}

