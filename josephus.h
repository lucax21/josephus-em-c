#include <stdbool.h>

struct js{
	char letra_nome;
};

typedef struct elemento *Lista;

Lista *cria_lista();

void libera_lista(Lista *li);

void imprime_lista(Lista *li);

bool insere_lista_final(Lista *li, struct js dado);

bool josephus(Lista *li, int num, char let);

bool busca_soldado(Lista *li, int pos, char *nome, char let_inic);

bool remove_soldado(Lista *li, char let, char *let_ret);
