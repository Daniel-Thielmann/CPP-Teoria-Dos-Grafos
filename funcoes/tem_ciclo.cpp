#include "../include/funcoes/tem_ciclo.h"
#include <iostream>

using namespace std;

bool dfsDetectaCiclo(int vertice, bool *visitado, int pai, listaEncad *listaAdjacencia) {
    visitado[vertice] = true;

    // Percorre todos os vértices adjacentes ao vértice atual
    No *atual = listaAdjacencia[vertice].getCabecaNo();
    while (atual != nullptr) {
        int vizinho = atual->getValor();

        if (!visitado[vizinho]) {
            // Realiza a chamada recursiva
            if (dfsDetectaCiclo(vizinho, visitado, vertice, listaAdjacencia)) {
                return true;
            }
        } else if (vizinho != pai) {
            // Se o vizinho foi visitado e não é o pai, há um ciclo
            return true;
        }

        atual = atual->getProx();
    }

    return false;
}

bool temCiclo(listaEncad *listaAdjacencia, int nVertice) {
    bool *visitado = new bool[nVertice](); // Inicializa o array com `false`

    // Percorre todos os vértices do grafo
    for (int i = 0; i < nVertice; i++) {
        if (!visitado[i]) {
            if (dfsDetectaCiclo(i, visitado, -1, listaAdjacencia)) {
                delete[] visitado;
                return true;
            }
        }
    }

    delete[] visitado;
    return false;
}
