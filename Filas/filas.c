#include <stdio.h>
#include <stdlib.h>

#define MAX 10
 
int array[MAX];
int inicio = 0;
int fim = 0;
 
void inserir(int elemento)
{
    if((fim+1)%MAX==inicio)
    {
        printf("Erro ao inserir\nFila cheia!!\n\n");
        system("pause");
    }
    else
    {
        array[fim]=elemento;
        fim=(fim+1)%MAX;
    }
}
void listar()
{
    int i=inicio;
    if(inicio==fim)
    {
        printf("Fila vazia.\n\n");
        system("pause");
    }
    else
    {
        while(i!=fim)
        {
            if(i+1==fim)
            {
                printf("%d",array[i]);
            }
            else
            {
                printf("%d - ",array[i]);
            }
            i=(i+1)%MAX;
        }
        printf("\n");
        system("pause");
    }
}
 
int remover()
{
    int resp;
    if(inicio==fim)
    {
        printf("Erro ao remover\nFila vazia\n\n");
        system("pause");
    }
    else
    {
        resp=array[inicio];
        inicio=(inicio+1)%MAX;
    }
}
 
void msn()
{
    printf("\t\tBem vindo ao programa Fila!!\n\n");
    printf("1: Inserir.\n");
    printf("2: Remover.\n");
    printf("3: Listar.\n");
    printf("4: Sair.\n\n");
    printf("Digite a opcao desejada: ");
}
 
void Menu()
{
    int op, n;
 
        system("cls");
        msn();
        scanf("%d",&op);
 
        if(op==1)
        {
            printf("Digite o elemento que deseja inserir: ");
            scanf("%d",&n);
            inserir(n);
            printf("Elemento inserido com sucesso\n");
            system("pause");
            Menu();
        }
        else if(op==2)
        {
            remover();
            printf("Elemento removido com sucesso\n\n");
            system("pause");
            Menu();
        }
        else if(op==3)
        {
            listar();
            printf("Precione qualquer tecla para continuar usando o programa.\n");
            system("pause");
            Menu();
        }
        else if(op==4)
        {
            printf("Obrigador por usar nosso programa.\n");
            system("pause");
            return 0;
        }
        else
        {
            printf("Digite a tecla 'serta'\n");
            system("pause");
            Menu();
        }
}
 
int main(int argc,char**argv)
{
    Menu();
 
    system("pause");
    return 0;
}