#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

// Definição da estrutura do grafo
typedef struct {
    int num_nos;           // Número de nós no grafo
    int **matriz_adj;      // Matriz de adjacência
} GrafoMatriz;

// Função para criar um grafo com 'n' nós
GrafoMatriz* cria_grafo(int n) {
    GrafoMatriz *grafo = (GrafoMatriz*) malloc(sizeof(GrafoMatriz));
    grafo->num_nos = n;

    // Alocação dinâmica da matriz de adjacência
    grafo->matriz_adj = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        grafo->matriz_adj[i] = (int*) calloc(n, sizeof(int));
    }

    return grafo;
}

// Função para deletar um nó do grafo
void deleta_no(GrafoMatriz *grafo, int no) {
    if (no < 0 || no >= grafo->num_nos) {
        cout << "Nó inválido!" << endl;
        return;
    }

    //  Liberar a memória da linha e coluna do nó a ser removido
    free(grafo->matriz_adj[no]); // Liberar a linha do nó

    //  Deslocar as linhas para cima a partir da linha do nó a ser removido
    for (int i = no; i < grafo->num_nos - 1; i++) {
        grafo->matriz_adj[i] = grafo->matriz_adj[i + 1];
    }

    //  Deslocar as colunas para a esquerda a partir da coluna do nó a ser removido
    for (int i = 0; i < grafo->num_nos - 1; i++) {
        for (int j = no; j < grafo->num_nos - 1; j++) {
            grafo->matriz_adj[i][j] = grafo->matriz_adj[i][j + 1];
        }
    }

    //  Reduzir o número de nós no grafo
    grafo->num_nos--;

    //  Realocar a matriz de adjacência para o novo tamanho
    grafo->matriz_adj = (int**) realloc(grafo->matriz_adj, grafo->num_nos * sizeof(int*));
    for (int i = 0; i < grafo->num_nos; i++) {
        grafo->matriz_adj[i] = (int*) realloc(grafo->matriz_adj[i], grafo->num_nos * sizeof(int));
    }
}

// Função para imprimir a matriz de adjacência
void imprime_grafo(GrafoMatriz *grafo) {
    cout << "Matriz de Adjacência:" << endl;
    for (int i = 0; i < grafo->num_nos; i++) {
        for (int j = 0; j < grafo->num_nos; j++) {
            cout << grafo->matriz_adj[i][j] << " ";
        }
        cout << endl;printf("\n");
    }
}

