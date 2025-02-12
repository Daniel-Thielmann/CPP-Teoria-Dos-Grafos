// grafo_lista.h
#ifndef GRAFO_LISTA_H
#define GRAFO_LISTA_H

#include "../core/Grafo.h"
#include <string>
#include "listaV.h" // Inclua o cabeçalho que define ListaV
#include <stdexcept>
#include "vertice.h"
#include "listaA.h"
#include "listaV.h"

class GrafoLista : public Grafo {
private:
    ListaV vertices; // Lista de vértices
    int** grafo; // Matriz de adjacência
    void dfsConexao(Vertice* vertice, bool* visitado) const;

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
    int* getArestas(int id) const;


private:
    void adicionaVertice(int id, int peso);    // Adiciona um vértice ao grafo
    void adicionaAresta(int origem, int destino, int peso); // Adiciona uma aresta ao grafo
   
};

#endif // GRAFO_LISTA_H
