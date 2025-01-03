#include "eh_bipartido.h"

// Construtor da classe GrafoBipartido
GrafoBipartido::GrafoBipartido(int numVertices) : Grafo(numVertices) {}

// Método que verifica se o grafo é bipartido
bool GrafoBipartido::ehBipartido() {
    int numVertices = getNumVertices();
    int** adjacencias = getAdjacencias();

    int* cores = new int[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        cores[i] = -1; // Inicializa as cores como não atribuídas
    }

    bool isBipartido = true;

    auto bfs = [&](int vertice) {
        int* fila = new int[numVertices];
        int inicio = 0, fim = 0;

        fila[fim++] = vertice;
        cores[vertice] = 0; // Primeira cor

        while (inicio < fim && isBipartido) {
            int u = fila[inicio++];
            for (int v = 0; v < numVertices; ++v) {
                if (adjacencias[u][v] != 0) { // Existe aresta
                    if (cores[v] == -1) { // Não colorido
                        cores[v] = 1 - cores[u];
                        fila[fim++] = v;
                    } else if (cores[v] == cores[u]) {
                        isBipartido = false;
                    }
                }
            }
        }
        delete[] fila;
    };

    for (int i = 0; i < numVertices && isBipartido; ++i) {
        if (cores[i] == -1) {
            bfs(i);
        }
    }

    delete[] cores;
    return isBipartido;
}

