#include "get_grau.h"
#include <iostream>

// Implementação do método para calcular o grau de um vértice
int GrafoGrau::getGrau(int vertice) {
    // Obtém a matriz de adjacências e o número de vértices do grafo
    int** adjacencias = getAdjacencias();
    int numVertices = getNumVertices();

    if (vertice < 0 || vertice >= numVertices) {
        std::cerr << "Erro: vertice invalido." << std::endl;
        return -1; // Retorna -1 para indicar erro
    }

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) { // Verifica se há uma aresta
            grau++;
        }
    }
    return grau; // Retorna o grau do vértice
}
