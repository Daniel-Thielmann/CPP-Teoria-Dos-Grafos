#ifndef TEM_CICLO_H
#define TEM_CICLO_H

#include "../../listaEncad.h"
#include <iostream>

using namespace std;

// Função auxiliar para realizar a busca em profundidade
bool dfsDetectaCiclo(int vertice, bool *visitado, int pai, listaEncad *listaAdjacencia);

// Função principal para verificar se o grafo tem ciclo
bool temCiclo(listaEncad *listaAdjacencia, int nVertice);

#endif
