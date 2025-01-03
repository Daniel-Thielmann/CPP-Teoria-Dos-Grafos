#include <iostream>
#include "../src/implementations/get_grau.h" // Inclua o cabeçalho correto

void testeGetGrau() {
    GrafoGrau grafo(4);

    // Adiciona arestas para teste
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);

    // Testa os graus
    std::cout << "Teste get_grau:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        int grau = grafo.getGrau(i);
        std::cout << "Vertice " << i << ": Grau = " << grau << std::endl;
    }
}
