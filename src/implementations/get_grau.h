#ifndef GET_GRAU_H
#define GET_GRAU_H

#include "../core/Grafo.h"
#include <iostream>

class GrafoGrau : public Grafo {
public:
    // Construtor que utiliza o construtor da classe base
    GrafoGrau(int numVertices) : Grafo(numVertices) {}

    // Método que calcula o grau de um vértice
    int getGrau(int vertice);
};

#endif // GET_GRAU_H
