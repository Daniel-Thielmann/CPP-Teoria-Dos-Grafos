#ifndef GRAFO_H
#define GRAFO_H

class Grafo {
private:
    int** grafo;

protected:
    int numVertices;
    bool ponderadoVertices;
    bool ponderadosArestas;
    bool direcionado;
    int** adjacencias; // Matriz de adjacência
    void inicializarMatriz();

public:
    Grafo(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado);
    virtual ~Grafo();

    virtual void adicionarAresta(int origem, int destino, int peso = 1) = 0;
    virtual void removerAresta(int origem, int destino) = 0;
    virtual void imprimeGrafo() const = 0; 
    virtual int getGrau(int vertice) const = 0;
    virtual bool existeAresta(int origem, int destino) const = 0;
    virtual bool ehConexo() const = 0;
    virtual bool ehCompleto() const = 0;
    virtual bool ehArvore() const = 0;
    virtual bool temCiclo() const = 0;
};

#endif // GRAFO_H
