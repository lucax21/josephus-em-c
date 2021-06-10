#include <stdio.h>
#include "josephus.h"

void main(){
	Lista *li;
	struct js j;
	char inicio_cont, letra;
	int num, x;

	li = cria_lista();
	do{
		printf("Digite a primeira letra do nome do soldado: \n");
		scanf("%c%*c", &letra);
		j.letra_nome = letra;
		
		if(letra != ':'){
			if(insere_lista_final(li, j)){
				//printf("sucesso\n");
			}else{
				//printf("erro\n");
			}
		}
	//	printf("flag %d\naudhusahd %c\n", aa, j.letra_nome);
	}	while(letra != ':');
	
	printf("letra\n");
	scanf("%c%*c", &inicio_cont);
	printf("num\n");
	scanf("%d", &num);

	x = josephus(li, num, inicio_cont);

	imprime_lista(li);

	libera_lista(li);
}
