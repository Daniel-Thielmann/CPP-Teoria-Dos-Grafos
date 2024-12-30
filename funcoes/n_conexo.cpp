#include "n_conexo.h"
#include <vector>

// Realiza uma BFS para visitar todos os vértices de uma componente conexa
void bfs(int vertice, const std::vector<std::vector<int>>& adjacencias, std::vector<bool>& visitado) {
    std::vector<int> fila; // Vetor para simular uma fila
    fila.push_back(vertice);
    visitado[vertice] = true;

    while (!fila.empty()) {
        int u = fila.back();
        fila.pop_back(); // Remove o último elemento (simula uma fila)

        // Percorre todos os vizinhos do vértice 'u'
        for (int v : adjacencias[u]) {
            if (!visitado[v]) {
                visitado[v] = true;
                fila.push_back(v); // Adiciona o vizinho à fila
            }
        }
    }
}

// Retorna o número de componentes conexas do grafo
int n_conexo(const std::vector<std::vector<int>>& adjacencias, int numVertices) {
    std::vector<bool> visitado(numVertices, false); // Marca se o vértice foi visitado
    int componentes = 0; // Contador de componentes conexas

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            // Se o vértice não foi visitado, inicia uma BFS a partir dele
            bfs(i, adjacencias, visitado);
            componentes++; // Incrementa o número de componentes conexas
        }
    }

    return componentes; // Retorna o número total de componentes conexas
}
