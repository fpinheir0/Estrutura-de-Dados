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

// No* cria_no(int num);
// Arvore* cria_arvore(int num);
// void insere_no(No *tree, int num);
// void pesquisa_no(No *tree, int num);
// No* acha_menor(No *tree);
// int acha_maior(int a, int b);
// No *remove_no(No *tree, int num);
// int altura(No *tree);
// void exibir_emordem(No *tree);
// void exibir_preordem(No *tree);
// void exibir_posordem(No *tree);
// void deletar_arv(No *tree);

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

void pesquisa_no(No *tree, int num){
	if(tree == NULL){
		printf("Numero %d nao esta presente na arvore\n",num);
	}else if(num < tree->num){
		pesquisa_no(tree->esq, num);
	}else if(num > tree->num){
		pesquisa_no(tree->dir, num);
	}else{
		printf("O numero %d esta presente na arvore\n", num);
	}
}

No* acha_menor(No *tree){
	if(tree->esq == NULL){
		return tree;
	}
	return acha_menor(tree->esq);
}

int acha_maior(int a, int b){
	if(a>b){
		return a;
	}else
		return b;
}

No *remove_no(No *tree, int num){
	No *aux;
	if(tree==NULL){
		printf("Numero ausente\n");
	}else if(num < tree->num){
		tree->esq = remove_no(tree->esq, num);
	}else if(num > tree->num){
		tree->dir = remove_no(tree->dir, num);
	}else if(tree->esq == NULL && tree->dir == NULL){
		aux = tree;
		free(tree);
		return NULL;
	}else if(tree->esq == NULL){
		aux = tree->dir;
		free(tree);
		return aux;
	}else if(tree->dir == NULL){
		aux = tree->esq;
		free(tree);
		return aux;
	}else{
		No *menor = acha_menor(tree->dir);
		tree->num = menor->num;
		tree->dir = remove_no(tree->dir, menor->num);
	}
	return tree;
}

int altura(No *tree){
	if((tree==NULL)||(tree->esq==NULL&&tree->dir==NULL)){
	return 0;
	}else{
	return 1 + acha_maior(altura(tree->esq), altura(tree->dir));
	}
}

void exibir_emordem(No *tree){
	if(tree!=NULL){
	exibir_emordem(tree->esq);
	printf("%d ",tree->num);
	exibir_emordem(tree->dir);
	}
}

void exibir_preordem(No *tree){
	if(tree!=NULL){
	printf("%d ",tree->num);
	exibir_preordem(tree->esq);
	exibir_preordem(tree->dir);
	}
}

void exibir_posordem(No *tree){
	if(tree!=NULL){
	exibir_posordem(tree->esq);
	exibir_posordem(tree->dir);
	printf("%d ",tree->num);
	}
}

void deletar_arv(No *tree){
	No *esquerda;
	No *direita;
	while(tree->esq!=NULL){
	esquerda = tree->esq;
	remove_no(tree, esquerda->num);
	}
	while(tree->dir!=NULL){
	direita = tree->dir;
	remove_no(tree, direita->num);
	}
	free(tree);
}


int main(){
	int x=0,opcao=0,opcao2=0,cont=0,opc=1;

	while(opc==1){
	printf("\nDigite um numero que sera a raiz de sua arvore: ");
	scanf("%d",&x);
	Arvore *tree = cria_arvore(x);
		opcao = 0;
		while(opcao==0){
		printf("\nInserir numero = 1\nEfetuar busca = 2\nRemover numero = 3\nVerificar altura = 4\nImprimir numeros = 5\nDeletar arvore = 6\nOpcao = ");
		scanf("%d",&opcao2);

		if(opcao2==1){
		printf("\nDigite um numero para ser inserido na arvore: ");
		scanf("%d",&x);
		insere_no(tree->raiz, x);
		opcao=0;

		}else if(opcao2==2){
		printf("\nDigite um numero para ser pesquisado na arvore: ");
		scanf("%d",&x);
		pesquisa_no(tree->raiz, x);
		opcao=0;
	
		}else if(opcao2==3){
		printf("\nDigite um numero para ser deletado da arvore: ");
		scanf("%d",&x);
		if(altura(tree->raiz)==0){
		remove_no(tree->raiz, x);
		printf("\nVoce removeu o unico elemento da arvore\n");
		opcao=1;
		}else{
		remove_no(tree->raiz, x);
		opcao=0;
		}

		}else if(opcao2==4){
		cont = altura(tree->raiz);
		printf("\nAltura = %d\n",cont);
		opcao=0;
		
		}else if(opcao2==5){
		printf("\nImprimir in-ordem = 1, pre-ordem = 2 ou pos-ordem = 3\n");
		scanf("%d",&opcao2);
			if(opcao2==1){
			exibir_emordem(tree->raiz);
			}else if(opcao2==2){
			exibir_preordem(tree->raiz);
			}else{
			exibir_posordem(tree->raiz);
			}
		printf("\n");
		opcao=0;
		
		}else if(opcao2==6){
		deletar_arv(tree->raiz);
		free(tree);
		break;
		}
}
	printf("\nPara comecar outra arvore = 1\nPara encerrar o programa = 2\nOpcao = ");
	scanf("%d",&opc);
}	
	return 0;
}