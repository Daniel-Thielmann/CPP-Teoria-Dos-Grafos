#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
using namespace std;

//Classe base do grafo//

class Grafo {
private:
    int numVertices;                        // Número de vértices
    vector<vector<int>> adjacencias;        // Lista de adjacência

public:

    Grafo(int numVertices);                 // Construtor

    // --- Funções responsáveis por Daniel  --- //

    void adicionarAresta(int u, int v);     // Adiciona uma aresta u-v
    bool eh_bipartido();                    // Verifica se o grafo é bipartido
    void exibirGrafo();                     // Exibe o grafo

    // --- --- --- --- --- --- --- --- -- --- //

};

#endif
