#include <iostream>
#include "./implementations/grafo_lista.h"
#include "./implementations/grafo_matriz.h"

int main() {
    try {
        // Criando um grafo utilizando a representação em lista de adjacência
        std::cout << "==== Representação com Lista de Adjacência ====" << std::endl;
        GrafoLista grafoLista("grafo.txt"); // Lê o grafo a partir de um arquivo
        grafoLista.imprimeGrafo();

        std::cout << "\nPropriedades do Grafo (Lista de Adjacência):" << std::endl;
        std::cout << "O grafo é conexo? " << (grafoLista.ehConexo() ? "Sim" : "Não") << std::endl;
        std::cout << "O grafo é completo? " << (grafoLista.ehCompleto() ? "Sim" : "Não") << std::endl;

        // Criando um grafo utilizando a representação em matriz de adjacência
        std::cout << "\n==== Representação com Matriz de Adjacência ====" << std::endl;
        int pesosVertices[] = {1, 2, 3, 4, 5, 6}; // Exemplo de pesos para vértices
        GrafoMatriz grafoMatriz(6, false, false, false, pesosVertices);

        // Adicionando arestas ao grafo
        grafoMatriz.adicionarAresta(0, 1, 1);
        grafoMatriz.adicionarAresta(1, 2, 1);
        grafoMatriz.adicionarAresta(2, 3, 1);
        grafoMatriz.adicionarAresta(3, 4, 1);
        grafoMatriz.adicionarAresta(4, 5, 1);

        grafoMatriz.imprimeGrafo();

        std::cout << "\nPropriedades do Grafo (Matriz de Adjacência):" << std::endl;
        std::cout << "O grafo é conexo? " << (grafoMatriz.ehConexo() ? "Sim" : "Não") << std::endl;
        std::cout << "O grafo é completo? " << (grafoMatriz.ehCompleto() ? "Sim" : "Não") << std::endl;
        std::cout << "O grafo é uma árvore? " << (grafoMatriz.ehArvore() ? "Sim" : "Não") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
