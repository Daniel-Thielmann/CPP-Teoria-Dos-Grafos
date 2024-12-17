#include <iostream>
#include "grafo.h"
#include "include/funcoes/eh_bipartido.h"

// Construtor
Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;
    adjacencias.resize(numVertices);
}

// Adiciona uma aresta entre os vértices u e v
void Grafo::adicionarAresta(int u, int v) {
    adjacencias[u].push_back(v);
    adjacencias[v].push_back(u); // Para grafos não direcionados
}

// Verifica se o grafo é bipartido
bool Grafo::eh_bipartido() {
    return ::eh_bipartido(adjacencias, numVertices); // Chama a função global eh_bipartido
}

// Exibe a lista de adjacências do grafo
void Grafo::exibirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << ": ";
        for (int v : adjacencias[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}
