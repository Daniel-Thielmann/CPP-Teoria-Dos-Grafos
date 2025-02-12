#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "../core/Grafo.h"

class GrafoMatriz : public Grafo {
private:
    int* pesoVertices;
    int** grafo;

public:
    GrafoMatriz(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado, int pesoVertices[]);
    ~GrafoMatriz();

    void adicionarAresta(int origem, int destino, int peso = 1) override;
    void removerAresta(int origem, int destino) override;
    void imprimeGrafo() const override;
    int getGrau(int vertice) const override;
    bool existeAresta(int origem, int destino) const override;
    bool ehConexo() const override;
    bool ehCompleto() const override;
    bool ehArvore() const override;
    bool temCiclo() const override;
    int* getArestas(int id) const override;
};

#endif // GRAFO_MATRIZ_H
