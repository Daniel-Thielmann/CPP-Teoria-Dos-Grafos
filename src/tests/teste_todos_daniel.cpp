#include <iostream>
#include "teste_eh_bipartido.h"
#include "teste_get_grau.h"
#include "teste_n_conexo.h"

// Função para executar e exibir o teste de eh_bipartido
void runTesteEhBipartido() {
    std::cout << "===== Testando eh_bipartido =====" << std::endl;
    testeEhBipartido(); // A função testeEhBipartido já exibe os resultados internamente
}

// Função para executar e exibir o teste de get_grau
void runTesteGetGrau() {
    std::cout << "===== Testando get_grau =====" << std::endl;
    testeGetGrau(); // A função testeGetGrau já exibe os resultados internamente
}

// Função para executar e exibir o teste de n_conexo
void runTesteNConexo() {
    std::cout << "===== Testando n_conexo =====" << std::endl;
    testeNConexo(); // A função testeNConexo já exibe os resultados internamente
}

int main() {
    // Executa os testes
    runTesteEhBipartido();
    std::cout << std::endl;

    runTesteGetGrau();
    std::cout << std::endl;

    runTesteNConexo();
    return 0;
}
