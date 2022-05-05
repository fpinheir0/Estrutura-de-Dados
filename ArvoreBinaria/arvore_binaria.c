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
void insere_no(No *minharaiz, int num);
void pesquisa_no(No *minharaiz, int num);
No* acha_menor(No *minharaiz);
int acha_maior(int a, int b);
No *remove_no(No *minharaiz, int num);
int altura(No *minharaiz);
void exibir_emordem(No *minharaiz);
void exibir_preordem(No *minharaiz);
void exibir_posordem(No *minharaiz);
void deletar_arv(No *minharaiz);

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

void insere_no(No *minharaiz, int num){
	if(num < minharaiz->num){
		if(minharaiz->esq){
			insere_no(minharaiz->esq, num);
		}else{
			No *novo = cria_no(num);
			minharaiz->esq = novo;
		}
	}else{
		if(minharaiz->dir){
			insere_no(minharaiz->dir, num);
		}else{
			No *novo = cria_no(num);
			minharaiz->dir = novo;
		}
	}
}

void pesquisa_no(No *minharaiz, int num){
	if(minharaiz == NULL){
		printf("Numero %d nao esta presente na arvore\n",num);
	}else if(num < minharaiz->num){
		pesquisa_no(minharaiz->esq, num);
	}else if(num > minharaiz->num){
		pesquisa_no(minharaiz->dir, num);
	}else{
		printf("O numero %d esta presente na arvore\n", num);
	}
}

No* acha_menor(No *minharaiz){
	if(minharaiz->esq == NULL){
		return minharaiz;
	}
	return acha_menor(minharaiz->esq);
}

int acha_maior(int a, int b){
	if(a>b){
		return a;
	}else
		return b;
}

No *remove_no(No *minharaiz, int num){
	No *aux;
	if(minharaiz==NULL){
		printf("Numero ausente\n");
	}else if(num < minharaiz->num){
		minharaiz->esq = remove_no(minharaiz->esq, num);
	}else if(num > minharaiz->num){
		minharaiz->dir = remove_no(minharaiz->dir, num);
	}else if(minharaiz->esq == NULL && minharaiz->dir == NULL){
		aux = minharaiz;
		free(minharaiz);
		return NULL;
	}else if(minharaiz->esq == NULL){
		aux = minharaiz->dir;
		free(minharaiz);
		return aux;
	}else if(minharaiz->dir == NULL){
		aux = minharaiz->esq;
		free(minharaiz);
		return aux;
	}else{
		No *menor = acha_menor(minharaiz->dir);
		minharaiz->num = menor->num;
		minharaiz->dir = remove_no(minharaiz->dir, menor->num);
	}
	return minharaiz;
}

int altura(No *minharaiz){
	if((minharaiz==NULL)||(minharaiz->esq==NULL&&minharaiz->dir==NULL)){
	return 0;
	}else{
	return 1 + acha_maior(altura(minharaiz->esq), altura(minharaiz->dir));
	}
}

void exibir_emordem(No *minharaiz){
	if(minharaiz!=NULL){
	exibir_emordem(minharaiz->esq);
	printf("%d ",minharaiz->num);
	exibir_emordem(minharaiz->dir);
	}
}

void exibir_preordem(No *minharaiz){
	if(minharaiz!=NULL){
	printf("%d ",minharaiz->num);
	exibir_preordem(minharaiz->esq);
	exibir_preordem(minharaiz->dir);
	}
}

void exibir_posordem(No *minharaiz){
	if(minharaiz!=NULL){
	exibir_posordem(minharaiz->esq);
	exibir_posordem(minharaiz->dir);
	printf("%d ",minharaiz->num);
	}
}

void deletar_arv(No *minharaiz){
	No *esquerda;
	No *direita;
	while(minharaiz->esq!=NULL){
	esquerda = minharaiz->esq;
	remove_no(minharaiz, esquerda->num);
	}
	while(minharaiz->dir!=NULL){
	direita = minharaiz->dir;
	remove_no(minharaiz, direita->num);
	}
	free(minharaiz);
}


int main(){
	int x=0,opcao=0,opcao2=0,cont=0,opc=1;

	while(opc==1){
	printf("\nDigite um numero que sera a raiz de sua arvore: ");
	scanf("%d",&x);
	Arvore *minharaiz = cria_arvore(x);
		opcao = 0;
		while(opcao==0){
		printf("\nInserir numero = 1\nEfetuar busca = 2\nRemover numero = 3\nVerificar altura = 4\nImprimir numeros = 5\nDeletar arvore = 6\nOpcao = ");
		scanf("%d",&opcao2);

		if(opcao2==1){
		printf("\nDigite um numero para ser inserido na arvore: ");
		scanf("%d",&x);
		insere_no(minharaiz->raiz, x);
		opcao=0;

		}else if(opcao2==2){
		printf("\nDigite um numero para ser pesquisado na arvore: ");
		scanf("%d",&x);
		pesquisa_no(minharaiz->raiz, x);
		opcao=0;
	
		}else if(opcao2==3){
		printf("\nDigite um numero para ser deletado da arvore: ");
		scanf("%d",&x);
		if(altura(minharaiz->raiz)==0){
		remove_no(minharaiz->raiz, x);
		printf("\nVoce removeu o unico elemento da arvore\n");
		opcao=1;
		}else{
		remove_no(minharaiz->raiz, x);
		opcao=0;
		}

		}else if(opcao2==4){
		cont = altura(minharaiz->raiz);
		printf("\nAltura = %d\n",cont);
		opcao=0;
		
		}else if(opcao2==5){
		printf("\nImprimir in-ordem = 1, pre-ordem = 2 ou pos-ordem = 3\n");
		scanf("%d",&opcao2);
			if(opcao2==1){
			exibir_emordem(minharaiz->raiz);
			}else if(opcao2==2){
			exibir_preordem(minharaiz->raiz);
			}else{
			exibir_posordem(minharaiz->raiz);
			}
		printf("\n");
		opcao=0;
		
		}else if(opcao2==6){
		deletar_arv(minharaiz->raiz);
		free(minharaiz);
		break;
		}
}
	printf("\nPara comecar outra arvore = 1\nPara encerrar o programa = 2\nOpcao = ");
	scanf("%d",&opc);
}	
	return 0;
}