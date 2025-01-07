#include "eh_direcionado.h"
#include "grafo_lista.h"

int eh_direcionado(const GrafoLista& grafo)  // Função que verifica se o grafo tem arestas com direcionamento
{
    return grafo.ehDirecionado();   // Retorna valor armazenado em grafo
}