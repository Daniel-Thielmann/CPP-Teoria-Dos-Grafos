#ifndef N_CONEXO_H
#define N_CONEXO_H

#include "../core/Grafo.h"
#include <iostream>
#include <vector>

class GrafoConexo : public Grafo {
public:
    GrafoConexo(int numVertices);

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

    // Método para calcular o número de componentes conexas
    int nConexo() const; // Adicionado const
};

#endif // N_CONEXO_H
