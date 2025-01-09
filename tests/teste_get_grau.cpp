#include "../src/implementations/get_grau.h"
#include <iostream>

void testeGetGrau() {
    GrafoGrau grafo(4);

    // Adiciona arestas ao grafo
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);

    // Testa os graus de cada vértice
    std::cout << "Teste getGrau:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Vértice " << i << ": Grau = " << grafo.getGrau(i) << std::endl;
    }

    // Testa com um vértice inválido
    std::cout << "Teste com vértice inválido (-1): Grau = " << grafo.getGrau(-1) << std::endl;
}
