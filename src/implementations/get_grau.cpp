#include "get_grau.h"
#include <iostream>
#include <vector>

// Construtor que utiliza o da classe base
GrafoGrau::GrafoGrau(int numVertices)
    : Grafo(numVertices, false, false, false) {}

// Implementação dos métodos virtuais
void GrafoGrau::adicionarAresta(int origem, int destino, int peso) {
    adjacencias[origem][destino] = peso;
    adjacencias[destino][origem] = peso; // Grafo não direcionado
}

void GrafoGrau::removerAresta(int origem, int destino) {
    adjacencias[origem][destino] = 0;
    adjacencias[destino][origem] = 0; // Grafo não direcionado
}

void GrafoGrau::imprimeGrafo() const {
    std::cout << "Lista de Adjacência:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << ": ";
        for (int j = 0; j < numVertices; ++j) {
            if (adjacencias[i][j] != 0) {
                std::cout << j << " ";
            }
        }
        std::cout << std::endl;
    }
}

int GrafoGrau::getGrau(int vertice) const {
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

bool GrafoGrau::existeAresta(int origem, int destino) const {
    return adjacencias[origem][destino] != 0;
}

bool GrafoGrau::ehConexo() const {
    std::vector<bool> visitado(numVertices, false);
    std::vector<int> fila;

    fila.push_back(0);
    visitado[0] = true;

    while (!fila.empty()) {
        int v = fila.back();
        fila.pop_back();

        for (int i = 0; i < numVertices; ++i) {
            if (adjacencias[v][i] != 0 && !visitado[i]) {
                visitado[i] = true;
                fila.push_back(i);
            }
        }
    }

    for (bool v : visitado) {
        if (!v) {
            return false;
        }
    }
    return true;
}

bool GrafoGrau::ehCompleto() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (adjacencias[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool GrafoGrau::ehArvore() const {
    return ehConexo() && !temCiclo();
}

bool GrafoGrau::temCiclo() const {
    std::vector<bool> visitado(numVertices, false);
    auto dfs = [&](int v, int parent, auto& dfs_ref) -> bool {
        visitado[v] = true;
        for (int i = 0; i < numVertices; ++i) {
            if (adjacencias[v][i] != 0) {
                if (!visitado[i]) {
                    if (dfs_ref(i, v, dfs_ref)) {
                        return true;
                    }
                } else if (i != parent) {
                    return true;
                }
            }
        }
        return false;
    };

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i] && dfs(i, -1, dfs)) {
            return true;
        }
    }
    return false;
}
