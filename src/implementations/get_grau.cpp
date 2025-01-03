#include "get_grau.h"

int GrafoGrau::getGrau(int vertice) {
    int** adjacencias = getAdjacencias(); // Obtém matriz de adjacências
    int numVertices = getNumVertices();  // Obtém número de vértices

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) { // Verifica se há aresta
            grau++;
        }
    }
    return grau; // Retorna o grau do vértice
}
