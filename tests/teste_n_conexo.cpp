#include <iostream>
#include "../src/implementations/n_conexo.h"

void testeNConexo() {
    // Cria um grafo com 6 vértices
    GrafoConexo grafo(6);

    // Adiciona arestas para criar 2 componentes conexas
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(2, 3);

    // Esperado: 4 componentes (vértices 4 e 5 são isolados)
    const int esperado = 4;

    // Calcula o número de componentes conexas
    int resultado = grafo.nConexo();

    // Exibe o resultado do teste
    std::cout << "Teste n_conexo:\n";
    std::cout << "Numero de componentes conexas: " << resultado << std::endl;
    std::cout << "Resultado esperado: " << esperado << std::endl;
    std::cout << "Teste " << (resultado == esperado ? "PASSOU" : "FALHOU") << "\n";
}
