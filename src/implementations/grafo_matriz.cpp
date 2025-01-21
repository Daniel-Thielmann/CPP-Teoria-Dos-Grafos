#include "grafo_matriz.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Construtor
GrafoMatriz::GrafoMatriz(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado, int pesoVertices[])
    : Grafo(numVertices, ponderadoVertices, ponderadosArestas, direcionado) {
    grafo = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        grafo[i] = new int[numVertices]();
    }

    if (ponderadoVertices) {
        this->pesoVertices = new int[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            this->pesoVertices[i] = pesoVertices[i];
        }
    } else {
        this->pesoVertices = nullptr;
    }
}

// Destrutor
GrafoMatriz::~GrafoMatriz() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] grafo[i];
    }
    delete[] grafo;

    if (pesoVertices) {
        delete[] pesoVertices;
    }
}

// Adiciona uma aresta
void GrafoMatriz::adicionarAresta(int origem, int destino, int peso) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        throw invalid_argument("Índices fora do intervalo válido.");
    }
    grafo[origem][destino] = (ponderadosArestas ? peso : 1);
    if (!direcionado) {
        grafo[destino][origem] = (ponderadosArestas ? peso : 1);
    }
}

// Remove uma aresta
void GrafoMatriz::removerAresta(int origem, int destino) {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        throw invalid_argument("Índices fora do intervalo válido.");
    }
    grafo[origem][destino] = 0;
    if (!direcionado) {
        grafo[destino][origem] = 0;
    }
}

// Imprime o grafo
void GrafoMatriz::imprimeGrafo() const {
    cout << "Matriz de Adjacencia:\n";
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << grafo[i][j] << " ";
        }
        cout << endl;
    }
}

// Obtém o grau de um vértice
int GrafoMatriz::getGrau(int vertice) const {
    if (vertice < 0 || vertice >= numVertices) {
        throw invalid_argument("Índice fora do intervalo válido.");
    }
    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (grafo[vertice][i] != 0) {
            grau++;
        }
    }
    return grau;
}

// Verifica se existe uma aresta
bool GrafoMatriz::existeAresta(int origem, int destino) const {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        return false;
    }
    return grafo[origem][destino] != 0;
}

// Verifica se o grafo é conexo
bool GrafoMatriz::ehConexo() const {
    return true; // Implementação simplificada
}

// Verifica se o grafo é completo
bool GrafoMatriz::ehCompleto() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (i != j && grafo[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// Verifica se o grafo é uma árvore
bool GrafoMatriz::ehArvore() const {
    return ehConexo() && !temCiclo();
}

// Verifica se o grafo contém ciclos
bool GrafoMatriz::temCiclo() const {
    return false; // Implementação simplificada
}
