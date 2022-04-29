#include <stdio.h>
#include <stdlib.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
node *pop(node *PILHA);


int main(void)
{
 node *PILHA = (node *) malloc(sizeof(node));
 if(!PILHA){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
 inicia(PILHA);
 int opt;

 do{
  opt=menu();
  opcao(PILHA,opt);
 }while(opt);

 free(PILHA);
 return 0;
 }
}

void inicia(node *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}

int menu (void) {
    int opt;
    printf ("***BEM VINDO AO PROGRAMA PILHAS***");
    printf ("Escolha a opcao\n");
    printf ("0. Sair\n");
    printf ("1. Limpar Pilha\n");
    printf ("2. Mostrar Pilha\n");
    printf ("4. Empilhar\n");
    printf ("5. Desempilhar\n");
    
    return opt;
}

