#ifndef GRAFOMATRIZ_H
#define GRAFOMATRIZ_H

#include <iostream>
#include <cstdlib>

// Definição da estrutura do grafo
typedef struct {
    int num_nos;           // Número de nós no grafo
    int **matriz_adj;      // Matriz de adjacência
} GrafoMatriz;

// Função para criar um grafo com 'n' nós
GrafoMatriz* cria_grafo(int n);

// Função para deletar um nó do grafo
void deleta_no(GrafoMatriz *grafo, int no);

// Função para imprimir a matriz de adjacência
void imprime_grafo(GrafoMatriz *grafo);

#endif // GRAFOMATRIZ_H