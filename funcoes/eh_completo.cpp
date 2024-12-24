#include "./include/funcoes/eh_completo.h"
#include <iostream>

using namespace std;

bool ehCompleto(listaEncad* listaAdjacencia, int nVertice) {
    // Para cada vértice, verifica se está conectado a todos os outros vértices
    for (int i = 0; i < nVertice; i++) {
        int count = 0;
        No* atual = listaAdjacencia[i].getCabecaNo();

        // Conta o número de vértices adjacentes
        while (atual != nullptr) {
            count++;
            atual = atual->getProx();
        }

        // Em um grafo completo, o número de arestas para cada vértice deve ser (nVertice - 1) (ele n se conecta consigo mesmo por isso -1)
        if (count != nVertice - 1) {
            return false;
        }
    }
    return true;
}
