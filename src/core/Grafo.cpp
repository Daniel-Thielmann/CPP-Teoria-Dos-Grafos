#include "Grafo.h"
#include <iostream>
#include <stdexcept>

// Construtor
Grafo::Grafo(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado)
    : numVertices(numVertices), ponderadoVertices(ponderadoVertices),
      ponderadosArestas(ponderadosArestas), direcionado(direcionado) {
    inicializarMatriz();

    grafo = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        grafo[i] = new int[numVertices]();
    }

}

// Destrutor
Grafo::~Grafo() {
    for (int i = 0; i < numVertices; ++i) {
    delete[] grafo[i];
    }
    delete[] grafo;
}


void Grafo::inicializarMatriz() {
    adjacencias = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencias[i] = new int[numVertices]();
    }
}


// Adiciona uma aresta
void Grafo::adicionarAresta(int origem, int destino, int peso) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        adjacencias[origem][destino] = peso;
        if (!direcionado) {
            adjacencias[destino][origem] = peso;
        }
    }
}


// Remove uma aresta
void Grafo::removerAresta(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        throw std::out_of_range("Índice de vértice fora dos limites.");
    }
    adjacencias[origem][destino] = 0;
    if (!direcionado) {
        adjacencias[destino][origem] = 0;
    }
}

// Imprime a matriz de adjacências
void Grafo::imprimeGrafo() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencias[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Obtém o grau de um vértice
int Grafo::getGrau(int vertice) const {
    if (vertice < 0 || vertice >= numVertices) {
        throw std::out_of_range("Índice de vértice fora dos limites.");
    }

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) {
            grau++;
        }
    }
    return grau;
}

// Verifica se existe uma aresta entre dois vértices
bool Grafo::existeAresta(int origem, int destino) const {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        return false;
    }
    return adjacencias[origem][destino] != 0;
}

// Verifica se o grafo é completo
bool Grafo::ehCompleto() const {
    // Um grafo completo deve ter todas as arestas possíveis entre os vértices.
    // Para isso, a matriz de adjacência (ou lista de adjacência) deve ser preenchida corretamente.

    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i != j) { // Ignora a diagonal (arestas do vértice para si mesmo)
                if (adjacencias[i][j] == 0) { // Se uma conexão estiver ausente, não é completo
                    return false;
                }
            }
        }
    }

    return true; // Todas as conexões foram verificadas e existem
}