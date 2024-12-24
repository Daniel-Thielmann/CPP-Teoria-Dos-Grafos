#include "../listaEncad.h"
#include "../no.h"
#include "../grafo_lista.h"
#include <iostream>
#include "../include/funcoes/eh_conexo.h"

using namespace std;

// Função auxiliar para DFS
void dfs(int vertice, bool* visitado, listaEncad* listaAdjacencia, int nVertice) {
    visitado[vertice] = true;

    // Percorre a lista de adjacência do vértice atual
    No* atual = listaAdjacencia[vertice].getCabecaNo();
    while (atual != nullptr) {
        int vizinho = atual->getValor();
        if (!visitado[vizinho]) {
            dfs(vizinho, visitado, listaAdjacencia, nVertice);
        }
        atual = atual->getProx();
    }
}

// Função para verificar se o grafo é conexo
bool eConexo(listaEncad* listaAdjacencia, int nVertice) {
    bool* visitado = new bool[nVertice]; // Array para marcar os vértices visitados
    for (int i = 0; i < nVertice; i++) {
        visitado[i] = false; // Inicializa todos como não visitados
    }

    // Inicia a DFS a partir do vértice 0
    dfs(0, visitado, listaAdjacencia, nVertice);

    // Verifica se todos os vértices foram visitados
    for (int i = 0; i < nVertice; i++) {
        if (!visitado[i]) {
            delete[] visitado; // Libera memória
            return false; // Se algum vértice não foi visitado, o grafo não é conexo
        }
    }

    delete[] visitado; // Libera memória
    return true;
}
