#include "eh_bipartido.h"
#include <iostream>
#include <vector>
#include <cmath>

// Construtor da classe GrafoBipartido
GrafoBipartido::GrafoBipartido(int numVertices)
    : Grafo(numVertices, false, false, false) {}

// Implementação dos métodos virtuais da classe base
void GrafoBipartido::adicionarAresta(int origem, int destino, int peso) {
    adjacencias[origem][destino] = peso;
    adjacencias[destino][origem] = peso; // Grafo não direcionado
}

void GrafoBipartido::removerAresta(int origem, int destino) {
    adjacencias[origem][destino] = 0;
    adjacencias[destino][origem] = 0; // Grafo não direcionado
}

void GrafoBipartido::imprimeGrafo() const {
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

int GrafoBipartido::getGrau(int vertice) const {
    int grau = 0;
    for (int j = 0; j < numVertices; ++j) {
        if (adjacencias[vertice][j] != 0) {
            grau++;
        }
    }
    return grau;
}

bool GrafoBipartido::existeAresta(int origem, int destino) const {
    return adjacencias[origem][destino] != 0;
}

bool GrafoBipartido::ehConexo() const {
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

bool GrafoBipartido::ehCompleto() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (adjacencias[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool GrafoBipartido::ehArvore() const {
    return ehConexo() && !temCiclo();
}

bool GrafoBipartido::temCiclo() const {
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

// Método que verifica se o grafo é bipartido por força bruta
bool GrafoBipartido::ehBipartido() {
    int totalParticoes = std::pow(2, numVertices);
    for (int mascara = 0; mascara < totalParticoes; ++mascara) {
        std::vector<int> conjuntoA, conjuntoB;

        for (int v = 0; v < numVertices; ++v) {
            if (mascara & (1 << v)) {
                conjuntoA.push_back(v);
            } else {
                conjuntoB.push_back(v);
            }
        }

        bool isBipartido = true;

        for (size_t i = 0; i < conjuntoA.size() && isBipartido; ++i) {
            for (size_t j = i + 1; j < conjuntoA.size() && isBipartido; ++j) {
                if (adjacencias[conjuntoA[i]][conjuntoA[j]] != 0) {
                    isBipartido = false;
                }
            }
        }

        for (size_t i = 0; i < conjuntoB.size() && isBipartido; ++i) {
            for (size_t j = i + 1; j < conjuntoB.size() && isBipartido; ++j) {
                if (adjacencias[conjuntoB[i]][conjuntoB[j]] != 0) {
                    isBipartido = false;
                }
            }
        }


        if (isBipartido) {
            return true;
        }
    }
    return false;
}
