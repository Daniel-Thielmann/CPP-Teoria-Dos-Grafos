#ifndef GET_GRAU_H
#define GET_GRAU_H

#include "../core/grafo.h"

class GrafoGrau : public Grafo {
public:
    // Construtor e destrutor herdados
    GrafoGrau(int numVertices) : Grafo(numVertices) {}

    // Método que calcula o grau de um vértice
    int getGrau(int vertice);
};

#endif // GET_GRAU_H
