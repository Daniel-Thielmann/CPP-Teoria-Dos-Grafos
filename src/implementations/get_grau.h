#ifndef GET_GRAU_H
#define GET_GRAU_H

#include "../core/Grafo.h"
#include <iostream>

class GrafoGrau : public Grafo {
public:
    // Construtor que utiliza o construtor da classe base
    GrafoGrau(int numVertices);

    // Métodos virtuais implementados
    void adicionarAresta(int origem, int destino, int peso = 1) override;
    void removerAresta(int origem, int destino) override;
    void imprimeGrafo() const override;
    int getGrau(int vertice) const override;
    bool existeAresta(int origem, int destino) const override;
    bool ehConexo() const override;
    bool ehCompleto() const override;
    bool ehArvore() const override;
    bool temCiclo() const override;
};

#endif // GET_GRAU_H
