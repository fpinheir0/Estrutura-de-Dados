#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    int x, y;
    struct ponto * proximo;  
} t_ponto;

int main (int argc, char *__argv[]){
    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;
    t_ponto * anterior;
    int resp;
    int limpar;

    ini_ponto = (t_ponto *) malloc(sizeof(t_ponto));
        if (ini_ponto == NULL)
            exit(1);
        proximo_ponto = ini_ponto;
            while (1){
                printf("Digite x: ");
                scanf("%d", &proximo_ponto->x);
                printf("Digite y: ");
                scanf("%d", &proximo_ponto->y);
                printf("Deseja continuar ? <1>SIM <Outro Valor> NAO: ");
                scanf("%d", &resp);

                    if (resp == 1){
                        proximo_ponto -> proximo = (t_ponto *)malloc(sizeof(t_ponto));
                        proximo_ponto = proximo_ponto -> proximo;
                    }else
                        break;
            }
           printf("\n");
            proximo_ponto->proximo = NULL;
            proximo_ponto = ini_ponto;
            printf("Esses so os elementos da sua lista:\n\n");
            while (proximo_ponto != NULL){
                printf("x: %d, y: %d\n", proximo_ponto->x, proximo_ponto->y);
                proximo_ponto = proximo_ponto->proximo;
            }

        // printf("\nInforme o valor a ser excluido :");
        // scanf("%d", &limpar);
        //     if (ini_ponto->x ==limpar){
        //         anterior=ini_ponto;
        //         ini_ponto=ini_ponto->proximo;
        //         free(anterior);
        //     } else {
        //         proximo_ponto=ini_ponto;
        //             while (proximo_ponto->x!=limpar&&proximo_ponto->proximo!=NULL){
        //               anterior=proximo_ponto;
        //               proximo_ponto=proximo_ponto->proximo;  
        //             } if (proximo_ponto->x==limpar){
        //                 anterior->proximo=proximo_ponto->proximo;
        //                 free(proximo_ponto);
        //             } else printf("\nNao existe na lista.");              
                    
        //     }
        // proximo_ponto=ini_ponto;
        // while (proximo_ponto->proximo!=NULL)
        // {
        //     printf("%d", proximo_ponto->x);
        //     proximo_ponto=proximo_ponto->proximo;
        // }
        
}


