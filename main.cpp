#include <iostream>
#include <vector>
#include "grafo.h"
#include "include/funcoes/eh_bipartido.h"

int main() {
    // Número de vértices no grafo
    int numVertices = 5;

    // Lista de adjacência para representar o grafo
    std::vector<std::vector<int>> adjacencias(numVertices);

    // Função auxiliar para adicionar arestas no grafo
    auto adicionarAresta = [&](int u, int v) {
        adjacencias[u].push_back(v);
        adjacencias[v].push_back(u); // Para grafo não direcionado
    };

    // Adiciona arestas ao grafo
    adicionarAresta(0, 1);
    adicionarAresta(1, 2);
    adicionarAresta(2, 3);
    adicionarAresta(3, 4);
    adicionarAresta(4, 0); // Esta aresta cria um ciclo ímpar

    // Exibe a lista de adjacências
    std::cout << "Lista de Adjacência do Grafo:" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << ": ";
        for (int v : adjacencias[i]) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

    // Verifica se o grafo é bipartido
    if (eh_bipartido(adjacencias, numVertices)) {
        std::cout << "O grafo é bipartido!" << std::endl;
    } else {
        std::cout << "O grafo não é bipartido!" << std::endl;
    }

    return 0;
}
