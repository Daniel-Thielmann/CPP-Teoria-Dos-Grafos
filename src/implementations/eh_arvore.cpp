#include "eh_arvore.h"
#include "grafo_lista.h"
#include <iostream>

using namespace std;

bool ehArvore(const GrafoLista& grafo) {
    // Verifica se o grafo tem ciclo
    if (grafo.ehDirecionado()) {
        if (grafo.temCiclo()) { 
            return false; // Grafo direcionado com ciclo não é uma árvore
        }
    } else {
        if (grafo.temCicloNaoDirecionado()) {
            return false; // Grafo não direcionado com ciclo não é uma árvore
        }
    }

    // Verifica se o grafo é conexo
    if (!grafo.ehConexo()) {
        return false; // Grafo desconexo não é uma árvore
    }

    return true; // Se não tem ciclo e é conexo, é uma árvore
}
