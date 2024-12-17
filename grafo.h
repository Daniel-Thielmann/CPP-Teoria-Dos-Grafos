#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
using namespace std;

class Grafo {
private:
    int numVertices;                    // Número de vértices
    vector<vector<int>> adjacencias;    // Lista de adjacência

public:

    // --- Funções responsáveis por Daniel  --- //

    Grafo(int numVertices);             // Construtor
    void adicionarAresta(int u, int v); // Adiciona uma aresta u-v
    bool eh_bipartido();                // Verifica se o grafo é bipartido
    int n_conexo();                     // Retorna o número de componentes conexas
    int get_grau(int vertice);          // Retorna o grau de um vértice específico

    // --- --- --- --- --- --- --- --- -- --- //

};

#endif
