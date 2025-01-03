#include <iostream>
#include "../src/implementations/n_conexo.h" // Inclua o cabeçalho correto


void testeNConexo() {
    GrafoConexo grafo(6);

    // Adiciona arestas para criar 2 componentes conexas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(2, 3);

    // Testa o número de componentes conexas
    int resultado = grafo.nConexo();
    std::cout << "Teste n_conexo: Numero de componentes: " << resultado << std::endl;
    std::cout << "Resultado esperado: " << (resultado == 4 ? "PASSOU" : "FALHOU") << std::endl;
}
