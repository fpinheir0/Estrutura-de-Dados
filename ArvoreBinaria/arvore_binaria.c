#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no *esq;
	struct no *dir;
	int num;
}No;

typedef struct arvore{
	No *raiz;
}Arvore;


