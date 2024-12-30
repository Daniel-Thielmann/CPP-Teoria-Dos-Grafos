#include "get_grau.h"

// Calcula o grau de um vértice específico
int get_grau(const std::vector<std::vector<int>>& adjacencias, int vertice) {
    // Verifica se o índice do vértice está dentro dos limites
    if (vertice < 0 || vertice >= adjacencias.size()) {
        return -1; // Retorna -1 para indicar um erro
    }

    // O grau do vértice é o número de arestas conectadas a ele
    return adjacencias[vertice].size();
}
