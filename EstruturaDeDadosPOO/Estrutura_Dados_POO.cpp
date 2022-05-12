#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class No{
    private:
        int valor;
        No *prox;
    public:
        No();
        No(int);
        void setValor(int);
        int getValor();
        void setProx(No *n); 
        No* getProx(); 
};

class Lista{
    public:
        Lista();
        Lista(int);
        void InsertInit(int valor);
        void InsertFinal(int valor);
        void RemoveInit();
        void RemoveFinal();
        void DetruirLista();
        void VoltarMenu();

        virtual void tPrint();
        No* getInicio(); 
        No* getFinal();

        void setInicio(No *n);
        void setFinal(No *n);
    private:
        No *inicio;
        No *fim;
};

class Pilha:public Lista{
    public:
        Pilha();
        void inserePilha(int);
        void removePilha();
        void tPrintPilha();
        void DetruirPilha();
        void VoltarMenu();
};

class Fila:public Lista{
    public:
        Fila();
        void insereFila(int);
        void removeFila();
        void tPrintFila();
        void DetruirFila();
        void VoltarMenu();
};

/*
*    CONSTRUCAO DOS NOS
*/

No::No(){
    setProx(NULL);
    setValor(0);
}
No::No(int valor){
    setProx(NULL);
    setValor(valor);
}
int No::getValor(){
    return(valor);
}   
void No::setValor(int v){
    valor = v;
}
No *No::getProx(){
    return prox;
}
void No::setProx(No *n){
    prox = n;
}
/**
 * CONTRUCAO DA LISTA
 * 
 */

Lista::Lista(){
    setInicio(NULL);
    setFinal(NULL);
}

void Lista::DetruirLista(){

    struct No *aux;

    if(inicio->getValor() == NULL){
        cout << "Nao ha valores" << endl;
    }
    else{
        aux = inicio;
        cout << "\nItens:\n" << endl;
        while (aux->getValor()){
            RemoveInit();
            
        }
    }
    cout << endl;
}

void Lista::InsertInit(int valor){
    No *novo = new No(valor);
    if(fim == NULL){
        fim = novo;
    }
    novo->setValor(valor);
    novo->setProx(inicio);
    inicio = novo;
}
void Lista::InsertFinal(int valor){
    No *novo = new No(valor);
    No *aux = fim;
    if (inicio == NULL){
        inicio = novo;
    }
    else{
        aux->setProx(novo);
    }
    novo->setProx(NULL);        
    fim = novo;
}
void Lista::RemoveInit(){
    if(inicio->getValor() == NULL){
        cout << "\nLista esta vazia\n" << endl;
    }
    else{
        if (inicio->getProx() == NULL){
            fim = NULL;
        }
        No *aux = inicio;
        inicio = aux->getProx();
        free(aux);
        aux = NULL;
    }
}


void Lista::RemoveFinal(){
    No *aux = inicio;

    if (inicio == NULL){
        cout << "\nLista esta vazia\n" << endl;
    }
    else{
        while (aux->getProx() != fim){
            aux = aux->getProx();
        }
        if(inicio->getProx() == NULL){
            inicio = NULL;
        }
        free(fim);
        fim = aux;
    }
}

void Lista::tPrint(){
    struct No *aux;
    if(inicio == NULL){
        cout << "Nao ha valores" << endl;
    }
    else{
        aux = inicio;
        cout << "\nItens:\n" << endl;
        while (aux != fim->getProx()){
            cout << aux->getValor() << " ";
            aux = aux->getProx();
        }
    }
    cout << endl;
}
No* Lista::getInicio(){
    return inicio;
}
void Lista::setInicio(No *n){
    inicio = n;
}
No* Lista::getFinal(){
    return fim;
}
void Lista::setFinal(No *n){
    fim = n;
}

/**
 *    PILHAS
 * 
 */

Pilha::Pilha(){
    setInicio(NULL);
    setFinal(NULL);
}
void Pilha::inserePilha(int valor){
    InsertInit(valor);
}
void Pilha::removePilha(){
    RemoveInit();
}
void Pilha::tPrintPilha(){
    tPrint();
}
void Pilha::DetruirPilha(){
    DetruirLista();
}

/*
*      FILAS 
*/

Fila::Fila(){
    setInicio(NULL);
    setFinal(NULL);
}
void Fila::insereFila(int valor){
    InsertFinal(valor);
}
void Fila::removeFila(){
    RemoveInit();
}
void Fila::tPrintFila(){
    tPrint();
}
void Fila::DetruirFila(){
    DetruirLista();
}


//=====================================================================================
int op, valor;

int opFila(){
    Lista *lista;
    lista = new Lista();
    do{
        cout << endl;
        cout << "========= METODO LISTA =========" << endl;
        cout << "0 - Inserir no inicio da lista" << endl;
        cout << "1 - Inserir no final da lista" << endl;
        cout << "2 - Remover do Inicio da lista" << endl;
        cout << "3 - Remover do final da lista" << endl;
        cout << "4 - Destruir lista\n" << endl;
        cout << "5 - Sair\n" << endl;
        cout << "6 - Voltar ao Menu Principal\n" << endl;
        cin >> op;
        switch (op)
        {
            case 0: //inserir no inicio lista
                cout << "Digite um valor para inserir no inicio: ";
                cin >> valor;
                lista->InsertInit(valor);
                lista->tPrint();
                break;
            case 1://Inserir no final da lista
                cout << "Digite um valor para inserir no final: ";
                cin >> valor;
                lista->InsertFinal(valor);
                lista->tPrint();
                break;
            case 2://Remover do Inicio da lista
                lista->RemoveInit();
                lista->tPrint();
                break;
            case 3: //Remover do final da lista
                lista->RemoveFinal();
                lista->tPrint();
                break;
            case 4://destruir lista
                lista->DetruirLista();
                lista->tPrint();
                break;
            case 5://destruir lista
                cout << "Saindo...";
                break;
            case 6: //Voltar ao Menu Principal
                cout << "Voltando..";
                break;

        default:
            cout << "Opcao invalida";
            break;
        }

    }while (op != 5);
}

int opPilha(){
    Pilha *pilha;
    pilha = new Pilha();
    do{
        cout << "========= METODO PILHA =========" << endl;
        cout << "0 - Inserir na pilha" << endl;
        cout << "1 - Remover da pilha" << endl;
        cout << "2 - Destruir pilha\n" << endl;
        cout << "3 - Sair\n" << endl;
        
        cin >> op;

    switch (op) {
            case 0:
                cout << "Digite um valor para inserir na pilha: ";
                cin >> valor;
                pilha->inserePilha(valor);
                pilha->tPrintPilha();
                break;
            case 1:
                pilha->removePilha();
                pilha->tPrintPilha();
                break;
            case 2: 
                pilha->DetruirPilha();
                cout <<"Pilha Destruida";
                pilha->tPrintPilha();
                break;
            default:
                cout << "Opcao invalida";
                break;
            }
    }while (op != 3);
}

int opLista(){
    Fila *fila;
    fila = new Fila();
    do{
        cout << "========= METODO FILA =========" << endl;
        cout << "0 - Inserir na fila" << endl;
        cout << "1 - Remover da fila" << endl;
        cout << "2 - Destruir fila e sair" << endl;
        cin >> op;
        switch (op) {
            case 0: ///inserre na fila
                cout << "Digite um valor para inserir na fila: ";
                cin >> valor;
                fila->insereFila(valor);
                fila->tPrintFila();
                break;
            case 1://remove da fila
                fila->removeFila();
                fila->tPrintFila();
                break;                    
            case 2://Destruir fila
                fila->DetruirFila();
                fila->tPrintFila();
                cout <<"Fila Destruida";
                break;              
            default:
                cout << "Opcao invalida!"<<endl;
                break;
        }
    }while(op != 11);
}

//=====================================================================================

int main(){
    do{
        cout << "========= METODOS =========" << endl;
        cout << "0 - FILA" << endl;
        cout << "1 - PILHA" << endl;
        cout << "2 - LISTA" << endl;
        cin >> op;

    switch (op){
        case 0: 
            opFila();
            break;
        case 1:
            opPilha();
            break;
        case 2:
            opLista();
            break;
        case 3:
            cout << "Saindo...";
            break;
        }
        
    }while(op ==3);
        
   return 0;

}