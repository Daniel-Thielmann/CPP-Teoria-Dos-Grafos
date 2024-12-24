#ifndef EH_CONEXO_h
#define EH_CONEXO_h
#include "../../listaEncad.h"
#include "../grafo_lista.h"

void dfs(int vertice, bool* visitado, listaEncad* listaAdjacencia, int nVertice); // depth-first search -> busca em profundidade (mais facil de implementar, ruim para grafos esparcos)
bool eConexo(listaEncad* listaAdjacencia, int nVertice);



#endif

