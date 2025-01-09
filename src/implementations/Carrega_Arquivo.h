#ifndef CARREGA_ARQUIVO_H_INCLUDED
#define CARREGA_ARQUIVO_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Estrutura para representar uma aresta com origem, destino e peso
struct Aresta {
    int origem;
    int destino;
    int peso;
};

// Classe que representa um grafo
class Grafo {
public:
    int num_vertices;       // Número total de vértices no grafo
    Aresta** adjacencias;   // Matriz de adjacências para representar as conexões entre os vértices

    // Construtor: Inicializa o grafo com o número especificado de vértices
    Grafo(int vertices);

    // Adiciona uma aresta ao grafo, especificando origem, destino e peso
    void adicionar_aresta(int origem, int destino, int peso);

    // Exibe a representação do grafo no console
    void exibir_grafo();

    // Destrutor: Libera a memória alocada para a matriz de adjacências
    ~Grafo();
};

// Função para carregar um grafo a partir de um arquivo
Grafo carrega_grafo(const string& nome_arquivo);


#endif // CARREGA_ARQUIVO_H_INCLUDED
