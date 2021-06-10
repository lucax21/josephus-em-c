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
	if(li == NULL || (*li) == NULL)
		return 0;
	bool ret1 = 0, ret2=0;
	char letra, letra2;
	int x=1;
	
	ret1 = busca_soldado(li, num, &letra, let);
	ret2 = remove_soldado(li, letra, &letra2);
	while(x != 14){
	//	letra = letra2;
		ret1 = busca_soldado(li, num, &letra, letra2);
		ret2 = remove_soldado(li, letra, &letra2);
		printf("test\n");
		x++;
	}

	return 1;
}	

bool busca_soldado(Lista *li, int pos, char *nome, char let_inic){
	if(li == NULL || (*li) == NULL)
		return 0;
	
	Elem *no = *li;
      	while(no->prox != (*li) && no->dados.letra_nome != let_inic)
		no = no->prox;
	
	int i = 1;
	while(i < pos){
		no = no->prox;
		i++;
	}
	
	*nome = no->dados.letra_nome;

	return 1;
}

bool remove_soldado(Lista *li, char let, char *let_ret){
	if(li == NULL || (*li) == NULL)
		return 0;
	Elem *no = *li;
	if(no->dados.letra_nome == let){
		if(no == no->prox){
			printf("O ultimo soldado foi: %c \n", no->dados.letra_nome);
			free(no);
			*li = NULL;
			return 1;
		}
		else{
			Elem *ult = *li;
			while(ult->prox != (*li))
				ult = ult->prox;
			ult->prox = (*li)->prox;
			*li = (*li)->prox;
			printf("---O soldado %c foi removido\n", no->dados.letra_nome);
			*let_ret = no->prox->dados.letra_nome;
			free(no);
			return 0;
		}
	}
	Elem *ant = no;
	no = no->prox;
	while(no != (*li) && no->dados.letra_nome != let){
		ant = no;
		no = no->prox;
	}
	if(no == *li)
		return 0;
	ant->prox = no->prox;
	printf("###O soldado %c foi removido\n", no->dados.letra_nome);
	*let_ret = no->prox->dados.letra_nome;
	free(no);
	return 0;
}
