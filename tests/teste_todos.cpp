#include <iostream>
#include "teste_eh_bipartido.h"
#include "teste_get_grau.h"
#include "teste_n_conexo.h"

int main() {
    std::cout << "===== Testando eh_bipartido =====" << std::endl;
    testeEhBipartido();

    std::cout << "\n===== Testando get_grau =====" << std::endl;
    testeGetGrau();

    std::cout << "\n===== Testando n_conexo =====" << std::endl;
    testeNConexo();

    return 0;
}
