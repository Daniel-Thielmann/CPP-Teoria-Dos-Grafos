#ifndef NO_H
#define NO_H

class No {
private:
    int id; // Identificador do vértice
    int valor; //valor do vertice
    No* prox; //
    No* ant;

public:
    No(int valor);           // Construtor
    int getValor();          // Obtém o valor
    No* getProx();           // Obtém o próximo nó
    No* getAnt();           // Obtém o próximo nó
    void setProx(No* p);     // Define o próximo nó
};

#endif
