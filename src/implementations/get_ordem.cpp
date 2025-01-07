#include "get_ordem.h"
#include "grafo_lista.h"

int get_ordem(const GrafoLista& grafo)  // Função que obtem o número de elementos do grafo
{
    const ListaV& vertices = grafo.getVertices();
    return vertices.tamanho();  // Retorna valor armazenado em garfo pelo tamanho do vetor de vertices
}