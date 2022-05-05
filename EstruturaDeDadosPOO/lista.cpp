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