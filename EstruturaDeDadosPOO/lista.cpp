#include <iostream>
#include <algorithm>

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

/*CRIANDO CLASSE LISTA*/
class Lista{
    public:
        Lista();
        Lista(int);
        void insereInicio(int valor);
        void insereFinal(int valor);
        void removeInicio();
        void removeFinal();
        virtual void exibe();
        void setInicio(No *n);
        No* getInicio();
        void setFinal(No *n);
        No* getFinal();
    private:
        No *inicio;
        No *fim;
};
/*TRABALHANDO COM NÓS*/
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

