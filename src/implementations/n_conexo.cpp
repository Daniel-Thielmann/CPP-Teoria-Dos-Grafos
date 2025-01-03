#include "n_conexo.h"

GrafoConexo::GrafoConexo(int numVertices) : Grafo(numVertices) {
    // Construtor vazio, mas necessário para inicializar a classe base
}

int GrafoConexo::nConexo() {
    int numVertices = getNumVertices();  // Obtém o número de vértices
    int** adjacencias = getAdjacencias(); // Obtém a matriz de adjacências

    bool* visitado = new bool[numVertices]; // Array para marcar vértices visitados
    for (int i = 0; i < numVertices; ++i) {
        visitado[i] = false;
    }

    int componentes = 0;

    // Função auxiliar para realizar BFS
    auto bfs = [&](int vertice) {
        int* fila = new int[numVertices];
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
        delete[] fila;
    };

    // Itera sobre todos os vértices para identificar componentes conexas
    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            bfs(i);
            componentes++;
        }
    }

    delete[] visitado;
    return componentes;
}
