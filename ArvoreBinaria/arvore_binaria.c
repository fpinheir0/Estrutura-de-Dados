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

No* cria_no(int num);
Arvore* cria_arvore(int num);
void insere_no(No *tree, int num);
void pesquisa_no(No *tree, int num);
No* acha_menor(No *tree);
int acha_maior(int a, int b);
No *remove_no(No *tree, int num);
int altura(No *tree);
void exibir_emordem(No *tree);
void exibir_preordem(No *tree);
void exibir_posordem(No *tree);
void deletar_arv(No *tree);

No* cria_no(int num){
	No *tree;
	tree = (No*) malloc(sizeof(No));

	tree->esq = NULL;
	tree->dir = NULL;
	tree->num =  num;

	return tree;
}

Arvore* cria_arvore(int num){
	Arvore *tree;
	tree = (Arvore*) malloc(sizeof(Arvore));
	tree->raiz = cria_no(num);

	return tree;
}

void insere_no(No *tree, int num){
	if(num < tree->num){
		if(tree->esq){
			insere_no(tree->esq, num);
		}else{
			No *novo = cria_no(num);
			tree->esq = novo;
		}
	}else{
		if(tree->dir){
			insere_no(tree->dir, num);
		}else{
			No *novo = cria_no(num);
			tree->dir = novo;
		}
	}
}



