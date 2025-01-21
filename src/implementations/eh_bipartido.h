#ifndef EH_BIPARTIDO_H
#define EH_BIPARTIDO_H

#include "../core/Grafo.h"
#include <cstdlib> 
#include <vector>

class GrafoBipartido : public Grafo {
public:
    GrafoBipartido(int numVertices);

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

    // Método para verificar se o grafo é bipartido
    bool ehBipartido();
};

#endif // EH_BIPARTIDO_H
