#include <stdio.h>
#include <stdlib.h>

typedef struct ponto{
    int x, y;
    struct ponto * proximo;  
} t_ponto;

int main (int argc, char *__argv[]){
    t_ponto * ini_ponto;
    t_ponto * proximo_ponto;
    int resp;

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
                    
}

