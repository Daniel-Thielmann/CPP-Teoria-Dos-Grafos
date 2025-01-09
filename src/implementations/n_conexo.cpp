#include "n_conexo.h"
#include <iostream>

// Construtor da classe GrafoConexo
GrafoConexo::GrafoConexo(int numVertices) : Grafo(numVertices) {}

// Método que calcula o número de componentes conexas
int GrafoConexo::nConexo() {
    int numVertices = getNumVertices();  // Obtém o número de vértices
    int** adjacencias = getAdjacencias(); // Obtém a matriz de adjacências

    // Array dinâmico para marcar vértices visitados
    bool* visitado = (bool*)malloc(numVertices * sizeof(bool));
    for (int i = 0; i < numVertices; ++i) {
        visitado[i] = false;
    }

    int componentes = 0;

    // Array para simular uma fila
    int* fila = (int*)malloc(numVertices * sizeof(int));

    // Função auxiliar para realizar BFS
    auto bfs = [&](int vertice) {
        int inicio = 0, fim = 0;

        fila[fim++] = vertice;
        visitado[vertice] = true;

        while (inicio < fim) {
            int u = fila[inicio++];
            for (int v = 0; v < numVertices; ++v) {
                if (adjacencias[u][v] != 0 && !visitado[v]) {
                    visitado[v] = true;
                    fila[fim++] = v;
                }
            }
        }
    };

    // Itera sobre todos os vértices para identificar componentes conexas
    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            bfs(i);
            componentes++;
        }
    }

    // Liberação de memória
    free(visitado);
    free(fila);

    return componentes;
}
