#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H
#include "grafo.h"
#include "./estrutura_de_dados/listaEncad.h"
#include <string>

using namespace std;

class GrafoLista {

protected:
    int m_numVertices;  // Número de vértices  m é de membro, para dizer que não é uma variável qualquer
    int m_numArestas;   // Número de arestas
    listaEncad vertices; // Lista contendo os vertices
    No** m_listaAdjacencia; // Lista de adjacência
    listaEncad* vizinhos;    // Lista de adjacência (arestas vizinhos)

public:
     GrafoLista(string path);  // Construtor
   virtual ~GrafoLista();         // Destrutor  , é virtual pq quem de fato opera o destrutor é a classe filha
     
};




#endif