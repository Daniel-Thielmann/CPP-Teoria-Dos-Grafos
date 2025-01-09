#include "eh_bipartido.h"
#include <iostream>

// Construtor da classe GrafoBipartido
GrafoBipartido::GrafoBipartido(int numVertices) : Grafo(numVertices) {}

// Método que verifica se o grafo é bipartido
bool GrafoBipartido::ehBipartido() {
    int numVertices = getNumVertices();
    int** adjacencias = getAdjacencias();

    // Array para armazenar as cores dos vértices
    int* cores = (int*)malloc(numVertices * sizeof(int));
    for (int i = 0; i < numVertices; ++i) {
        cores[i] = -1; // Inicializa as cores como não atribuídas
    }

    bool isBipartido = true;

    // Array para simular uma fila
    int* fila = (int*)malloc(numVertices * sizeof(int));

    // Função auxiliar para realizar BFS
    auto bfs = [&](int vertice) {
        int inicio = 0, fim = 0;

        fila[fim++] = vertice;
        cores[vertice] = 0; // Atribui a primeira cor

        while (inicio < fim && isBipartido) {
            int u = fila[inicio++];
            for (int v = 0; v < numVertices; ++v) {
                if (adjacencias[u][v] != 0) { // Existe aresta
                    if (cores[v] == -1) { // Não colorido
                        cores[v] = 1 - cores[u];
                        fila[fim++] = v;
                    } else if (cores[v] == cores[u]) { // Conflito de cores
                        isBipartido = false;
                    }
                }
            }
        }
    };

    // Itera sobre todos os vértices para verificar bipartição
    for (int i = 0; i < numVertices && isBipartido; ++i) {
        if (cores[i] == -1) { // Vértice não visitado
            bfs(i);
        }
    }

    // Libera memória alocada
    free(cores);
    free(fila);

    return isBipartido;
}
