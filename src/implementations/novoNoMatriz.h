#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <cstdlib>

// Definição da estrutura do grafo
struct Grafo {
    int **matriz_adj;  // Matriz de adjacência
    int num_nos;       // Número atual de nós
    int capacidade;    // Capacidade atual da matriz
};

// Função para inicializar o grafo
Grafo* criar_grafo();

// Função para redimensionar a matriz de adjacência
void redimensionar_matriz(Grafo *grafo);

// Função para adicionar um novo nó ao grafo
void novo_no(Grafo *grafo);

#endif // GRAFO_H