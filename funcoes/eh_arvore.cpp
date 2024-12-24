#include <iostream>
#include "listaEncad.h"
#include "./include/funcoes/tem_ciclo.h"
#include "./include/funcoes/eh_conexo.h"

using namespace std;

bool eh_arvore(listaEncad* listaAdjacencia, int nVertice) {
    // Verifica se o grafo é conexo
    if (!eConexo(listaAdjacencia, nVertice)) {
        return false;
    }

    // Verifica se o grafo não tem ciclo
    if (temCiclo(listaAdjacencia, nVertice)) {
        return false;
    }

    return true;
}