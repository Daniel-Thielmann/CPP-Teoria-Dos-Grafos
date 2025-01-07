#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include <string>
#include "vertice.h"
#include "listaV.h"

using namespace std;

class GrafoLista { // Classe que representa um grafo usando listas 
private:
    ListaV vertices;          // Lista de vértices
    bool direcionado;         // Indica se o grafo é direcionado
    bool ponderadoVertices;   // Indica se os vértices têm peso
    bool ponderadoArestas;    // Indica se as arestas têm peso

public:
    GrafoLista(string nomeArquivo); // Construtor que carrega o grafo de um arquivo
    ~GrafoLista();                              // Destrutor para limpar a memória

    void imprimeGrafo() const;                 // Imprime o grafo no formato lista de adjacência
    bool arestasPonderadas() const;            // Retorna se as arestas têm peso
    bool temCiclo() const;                     // Verifica se o grafo direcionado contém ciclos
    bool ehCompleto() const;                   // Verifica se o grafo é completo
    const ListaV& getVertices() const; // Retorna uma referência constante para os vértices
    bool ehConexo() const; // Verifica se o grafo é conexo          
    void dfsConexao(Vertice* vertice, bool* visitado) const; // DFS para verificar a conexão do grafo
    bool verificaCicloUtil(Vertice* vertice, bool* visitado, bool* pilhaRecursao) const; // Verifica ciclos em grafos direcionados
    bool verificaCicloNaoDirecionado(Vertice* vertice, bool* visitado, int pai) const; // Verifica ciclos em grafos não direcionados
    bool temCicloNaoDirecionado() const; // Verifica se o grafo nao direcionado contém ciclos
    bool ehDirecionado() const; // Verifica se o grafo é direcionado
    bool vertice_ponderado() const; // Verifica se o grafo tem vertices com pesos


private:
    void adicionaVertice(int id, int peso);    // Adiciona um vértice ao grafo
    void adicionaAresta(int origem, int destino, int peso); // Adiciona uma aresta ao grafo
   
};

#endif // GRAFO_LISTA_H
