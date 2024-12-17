#include <iostream>
#include "funcoes/eh_bipartido.h"
#include <queue>

// Verifica se o grafo é bipartido
bool eh_bipartido(const std::vector<std::vector<int>>& adjacencias, int numVertices) {
    // Vetor que armazena a "cor" de cada vértice:
    // -1: não visitado, 0: primeira cor, 1: segunda cor
   std::vector<int> cor(numVertices, -1);

    // Fila utilizada para a busca em largura (BFS)
    std::queue<int> fila;

    // Percorre todos os vértices do grafo
    for (int i = 0; i < numVertices; ++i) {
        // Se o vértice ainda não foi visitado, inicia um BFS a partir dele
        if (cor[i] == -1) {  
            cor[i] = 0;    // Atribui a cor 0 ao vértice inicial
            fila.push(i);  // Adiciona o vértice à fila para processá-lo

            // Inicia o processo de BFS
            while (!fila.empty()) {
                int u = fila.front(); // Pega o vértice da frente da fila
                fila.pop();           // Remove o vértice da fila

                // Processa todos os vizinhos do vértice 'u'
                for (int v : adjacencias[u]) {
                    if (cor[v] == -1) {  // Se o vértice 'v' ainda não foi visitado
                        cor[v] = 1 - cor[u]; // Atribui a cor oposta ao vértice 'u'
                        fila.push(v);    // Adiciona 'v' à fila para ser processado
                    } 
                    // Se o vértice 'v' já foi visitado e tem a mesma cor que 'u'
                    else if (cor[v] == cor[u]) {
                        return false; // O grafo não é bipartido (conflito de cores)
                    }
                }
            }
        }
    }
    // Se nenhum conflito foi encontrado, o grafo é bipartido
    return true;
}