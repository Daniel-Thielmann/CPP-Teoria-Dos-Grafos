#include "Grafo.h"
#include <iostream>

// Construtor
Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;

    // Alocação dinâmica da matriz de adjacências
    adjacencias = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencias[i] = new int[numVertices]();
    }
}

// Destrutor
Grafo::~Grafo() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjacencias[i];
    }
    delete[] adjacencias;
}

// Adiciona uma aresta
void Grafo::adicionarAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        adjacencias[origem][destino] = 1;
        adjacencias[destino][origem] = 1;
    }
}

// Remove uma aresta
void Grafo::removerAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        adjacencias[origem][destino] = 0;
        adjacencias[destino][origem] = 0;
    }
}

// Imprime a matriz de adjacências
void Grafo::imprimirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencias[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Obtém o grau de um vértice
int Grafo::getGrau(int vertice) {
    if (vertice < 0 || vertice >= numVertices) return -1;

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) { // Verifica se há aresta
            grau++;
        }
    }
    return grau;
}
