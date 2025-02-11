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
    explicit GrafoLista(const std::string& arquivo);
    ~GrafoLista();

    void adicionarAresta(int origem, int destino, int peso = 1) override;
    void removerAresta(int origem, int destino) override;

    void deleta_no(int id); 
    void deleta_aresta2(int origem, int destino);
    void novo_no(int id, int peso);
    void deleta_aresta(int id); 
    void nova_aresta(int origem, int destino, int peso, bool direcionado); 

    void imprimeGrafo() const override;
    int getGrau(int vertice) const override;
    bool existeAresta(int origem, int destino) const override;
    bool ehConexo() const override;
    bool ehCompleto() const override;
    bool ehArvore() const override;
    bool temCiclo() const override;
   
};

#endif // GRAFO_LISTA_H
