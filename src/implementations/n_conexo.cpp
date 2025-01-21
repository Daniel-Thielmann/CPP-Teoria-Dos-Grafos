#include "n_conexo.h"
#include <iostream>
#include <vector>

// Construtor que utiliza o da classe base
GrafoConexo::GrafoConexo(int numVertices)
    : Grafo(numVertices, false, false, false) {}

// Implementação dos métodos virtuais
void GrafoConexo::adicionarAresta(int origem, int destino, int peso) {
    adjacencias[origem][destino] = peso;
    adjacencias[destino][origem] = peso; // Grafo não direcionado
}

void GrafoConexo::removerAresta(int origem, int destino) {
    adjacencias[origem][destino] = 0;
    adjacencias[destino][origem] = 0; // Grafo não direcionado
}

void GrafoConexo::imprimeGrafo() const {
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

int GrafoConexo::getGrau(int vertice) const {
    if (vertice < 0 || vertice >= numVertices) {
        std::cerr << "Erro: vértice inválido." << std::endl;
        return -1;
    }

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) {
            grau++;
        }
    }
    return grau;
}

bool GrafoConexo::existeAresta(int origem, int destino) const {
    return adjacencias[origem][destino] != 0;
}

bool GrafoConexo::ehConexo() const {
    return nConexo() == 1; // Se o número de componentes conexas for 1, o grafo é conexo
}

bool GrafoConexo::ehCompleto() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = i + 1; j < numVertices; ++j) {
            if (adjacencias[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool GrafoConexo::ehArvore() const {
    return ehConexo() && !temCiclo();
}

bool GrafoConexo::temCiclo() const {
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

int GrafoConexo::nConexo() const {
    std::vector<bool> visitado(numVertices, false);
    int componentes = 0;

    auto bfs = [&](int vertice) {
        std::vector<int> fila = {vertice};
        visitado[vertice] = true;

        while (!fila.empty()) {
            int u = fila.back();
            fila.pop_back();

            for (int i = 0; i < numVertices; ++i) {
                if (adjacencias[u][i] != 0 && !visitado[i]) {
                    visitado[i] = true;
                    fila.push_back(i);
                }
            }
        }
    };

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            bfs(i);
            componentes++;
        }
    }
    return componentes;
}
