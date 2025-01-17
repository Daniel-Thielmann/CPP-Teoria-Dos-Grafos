#ifndef GRAFO_H 
#define GRAFO_H

class Grafo {
protected:
    int** adjacencias; // Matriz de adjacências
    int numVertices;   // Número de vértices

    bool ponderadoVertices; // Peso dos vértices: 0 = não ponderados, 1 = ponderados
    bool ponderadosArestas; // Peso das arestas: 0 = não ponderadas, 1 = ponderadas
    bool direcionado;       // Direcionamento: 0 = não direcionado, 1 = direcionado

public:
    Grafo(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado);  // Construtor
    Grafo(int numVertices);
    virtual ~Grafo(); // Destrutor

    void adicionarAresta(int origem, int destino);
    void removerAresta(int origem, int destino);
    void imprimirGrafo();
    int getGrau(int vertice);

    bool ehDirecionado();
    bool verticePonderado();
    bool arestaPonderada();
    int get_ordem();

    virtual void imprime_grafo();
    virtual bool ehConexo();
    virtual bool ehArvore();
    virtual bool ehCompleto();

    // Métodos getters
    int** getAdjacencias() const { return adjacencias; }
    int getNumVertices() const { return numVertices; }

    // Método para verificar se existe uma aresta
    bool existeAresta(int origem, int destino) const;
};

#endif // GRAFO_H
