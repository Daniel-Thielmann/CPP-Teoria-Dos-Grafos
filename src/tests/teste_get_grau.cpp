#include "../implementations/get_grau.h"
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
        std::cout << "Vertice " << i << ": Grau = " << grafo.getGrau(i) << std::endl;
    }

    // Testa com um vértice inválido
    int resultado = grafo.getGrau(-1);
    if (resultado == -1) {
        std::cout << "Vertice invalido retornou corretamente -1." << std::endl;
    } else {
        std::cout << "Erro: Vertice invalido não retornou -1." << std::endl;
    }
}
