#include <iostream>
#include "./core/Grafo.h"
#include "./implementations/eh_bipartido.h"
#include "./implementations/n_conexo.h"
#include "./implementations/get_grau.h"

int main() {
    // Criação de um grafo com 6 vértices
    Grafo grafo(6);

    // Adicionando arestas ao grafo
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 3);
    grafo.adicionarAresta(3, 4);
    grafo.adicionarAresta(4, 5);

    // Exibindo a matriz de adjacências
    std::cout << "Matriz de adjacencias do grafo:\n";
    grafo.imprimirGrafo();

    // Testando se o grafo é bipartido
    GrafoBipartido grafoBipartido(6);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (grafo.existeAresta(i, j)) { // Evita adicionar arestas inexistentes
                grafoBipartido.adicionarAresta(i, j);
            }
        }
    }
    std::cout << "\nO grafo eh bipartido? " 
              << (grafoBipartido.ehBipartido() ? "Sim" : "Nao") << "\n";

    // Calculando o número de componentes conexas
    GrafoConexo grafoConexo(6);
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (grafo.existeAresta(i, j)) { // Adiciona apenas as arestas reais
                grafoConexo.adicionarAresta(i, j);
            }
        }
    }
    int componentes = grafoConexo.nConexo();
    std::cout << "\nNumero de componentes conexas: " << componentes << "\n";

    // Calculando o grau de cada vértice
    std::cout << "\nGrau de cada vertice:\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "Vertice " << i << ": Grau = " << grafo.getGrau(i) << "\n";
    }

    return 0;
}
