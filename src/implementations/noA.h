#ifndef NOA_H
#define NOA_H

#include "aresta.h"


class NoA { // Classe que representa um nó de uma lista de arestas
public:
    Aresta* a;    // Ponteiro para a aresta
    NoA* proximo; // Próximo nó na lista

    NoA(Aresta* aresta) : a(aresta), proximo(nullptr) {} // Construtor
};

#endif
