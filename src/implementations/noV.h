#ifndef NOV_H
#define NOV_H

#include "vertice.h"

class NoV { // Classe que representa um nó de uma lista de vértices
public:
    Vertice* v;    // Ponteiro para o vértice
    NoV* proximo;  // Próximo nó na lista

    NoV(Vertice* vertice) : v(vertice), proximo(nullptr) {} // Construtor
};

#endif