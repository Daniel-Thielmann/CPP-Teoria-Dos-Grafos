#include "grafo_lista.h"
#include <iostream>
#include "include/funcoes/eh_completo.h"
#include "include/funcoes/aresta_ponderada.h"
#include "include/funcoes/eh_arvore.h"

using namespace std;

int main() {  

    try {
        GrafoLista grafo("teste.txt");
        cout << "Grafo carregado com sucesso!" << endl;
        grafo.imprimeGrafo();

        if (ehCompleto(grafo) == true) {
            std::cout << "O grafo é completo." << std::endl;
        } else {
            std::cout << "O grafo não é completo." << std::endl;
        }

        if(arestasPonderadas(grafo) == true) {
            std::cout << "As arestas são ponderadas." << std::endl;
        } else {
            std::cout << "As arestas não são ponderadas." << std::endl;
        }
       if(ehArvore(grafo) == true) {
            std::cout << "O grafo é uma arvore." << std::endl;
        } else {
            std::cout << "O grafo não é uma arvore." << std::endl;
        }
        if(grafo.ehConexo() == true) {
            std::cout << "O grafo é conexo." << std::endl;
        } else {
            std::cout << "O grafo não é conexo." << std::endl;
        }
        if(grafo.ehDirecionado() == true) {
           
           if(grafo.temCiclo() == true) {
            std::cout << "O grafo tem ciclo." << std::endl;
        } else { 
            std::cout << "O grafo não tem ciclo." << std::endl;
        }
        } else {
            if(grafo.temCicloNaoDirecionado() == true) {
            std::cout << "O grafotem ciclo." << std::endl;
        } else { 
            std::cout << "O grafo não tem ciclo." << std::endl; 
        }
        }
    } catch (...) {
        std::cerr << "Erro inesperado!" << std::endl;
        return EXIT_FAILURE;
    }



    return 0;
}

