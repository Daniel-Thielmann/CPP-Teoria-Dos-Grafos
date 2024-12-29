#include <iostream>
#include <cstdlib>
#include "funcoes/eh_completo.h"
#include "./grafo_lista.h"

using namespace std;

bool ehCompleto(const GrafoLista& grafo) { // Função que verifica se o grafo é completo
    const ListaV& vertices = grafo.getVertices(); // Obtém a lista de vértices
    int numVertices = vertices.tamanho();         // Obtém o número de vértices

    NoV* noVertice = vertices.getRaiz();        // Obtém o nó raiz
    while (noVertice) {           // Enquanto houver vértices na lista
        if (noVertice->v->arestas.tamanho() != numVertices - 1) {   // Se o vértice não tem o número correto de arestas
            return false; // O grafo não é completo
        }
        noVertice = noVertice->proximo; // Move para o próximo vértice
    }
    return true;  // O grafo é completo
}
