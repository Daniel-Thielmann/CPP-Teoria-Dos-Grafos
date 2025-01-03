#include <iostream>
#include "../src/implementations/eh_bipartido.h"

void testeEhBipartido() {
    GrafoBipartido grafo(4);

    // Adiciona arestas para um grafo bipartido
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);

    // Testa se o grafo é bipartido
    bool resultado = grafo.ehBipartido();
    std::cout << "Teste eh_bipartido: " << (resultado ? "PASSOU" : "FALHOU") << std::endl;
}
