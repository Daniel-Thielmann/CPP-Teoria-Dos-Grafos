#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Definição da estrutura do grafo
struct Grafo {
    int **matriz_adj;  // Matriz de adjacência
    int num_nos;       // Número atual de nós
    int capacidade;    // Capacidade atual da matriz
};

// Função para inicializar o grafo
Grafo* criar_grafo() {
    Grafo *grafo = (Grafo*) malloc(sizeof(Grafo));
    grafo->num_nos = 0;
    grafo->capacidade = 10;

    // Alocação dinâmica da matriz de adjacência
    grafo->matriz_adj = (int**) malloc(grafo->capacidade * sizeof(int*));
    for (int i = 0; i < grafo->capacidade; i++) {
        grafo->matriz_adj[i] = (int*) calloc(grafo->capacidade, sizeof(int));
    }

    return grafo;
}

// Função para redimensionar a matriz de adjacência
void redimensionar_matriz(Grafo *grafo) {
    int nova_capacidade = grafo->capacidade * 2;
    int **nova_matriz = (int**) malloc(nova_capacidade * sizeof(int*));

    // Alocação da nova matriz
    for (int i = 0; i < nova_capacidade; i++) {
        nova_matriz[i] = (int*) calloc(nova_capacidade, sizeof(int));
    }

    // Copiar os valores da matriz antiga para a nova
    for (int i = 0; i < grafo->capacidade; i++) {
        for (int j = 0; j < grafo->capacidade; j++) {
            nova_matriz[i][j] = grafo->matriz_adj[i][j];
        }
    }

    // Liberar a memória da matriz antiga
    for (int i = 0; i < grafo->capacidade; i++) {
        free(grafo->matriz_adj[i]);
    }
    free(grafo->matriz_adj);  // Liberar o ponteiro da matriz antiga

    // Atualizar a matriz e a capacidade do grafo
    grafo->matriz_adj = nova_matriz;
    grafo->capacidade = nova_capacidade;
}

// Função para adicionar um novo nó ao grafo
void novo_no(Grafo *grafo) {
    // Verificar se é necessário redimensionar a matriz
    if (grafo->num_nos >= grafo->capacidade) {
        redimensionar_matriz(grafo);
    }

    // Incrementar o número de nós
    grafo->num_nos++;

    // Inicializar as conexões do novo nó (todas como 0)
    for (int i = 0; i < grafo->num_nos; i++) {
        grafo->matriz_adj[i][grafo->num_nos - 1] = 0;
        grafo->matriz_adj[grafo->num_nos - 1][i] = 0;
    }

    cout << "Novo nó adicionado. Total de nós: " << grafo->num_nos << endl;
}

