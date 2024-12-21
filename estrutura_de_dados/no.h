#ifndef NO_H
#define NO_H

class No {
private:
    int valor;
    No* prox;

public:
    No(int valor);           // Construtor
    int getValor();          // Obtém o valor
    No* getProx();           // Obtém o próximo nó
    void setProx(No* p);     // Define o próximo nó
};

#endif
