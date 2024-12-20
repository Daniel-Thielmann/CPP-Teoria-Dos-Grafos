#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include "grafo.h"
#include <list>

using namespace std;

class GrafoLista {

private:
    int numVertices;  // Número de vértices
    int numArestas;   // Número de arestas
    list<int> vertices; // Lista contendo os vertices
    list<int>* vizinhos;    // Lista de adjacência (vizinhos)

public:
     GrafoLista(int numVertices);  // Construtor
    ~GrafoLista();         // Destrutor
     

    
    void adicionarVertice(int id); // Adicionar um vértice
    void adicionarAresta(int origem, int destino); // Adicionar uma aresta
    void exibirGrafo();    // Exibir o grafo
};




#endif