#ifndef GRAFO_H
#define GRAFO_H

class Grafo {
private:
    int** adjacencias; // Matriz de adjacências
    int numVertices;   // Número de vértices

public:
    Grafo(int numVertices);  // Construtor
    virtual ~Grafo();        // Destrutor

    void adicionarAresta(int origem, int destino);
    void removerAresta(int origem, int destino);
    void imprimirGrafo();
    int getGrau(int vertice);

    // Métodos getters
    int** getAdjacencias() const { return adjacencias; }
    int getNumVertices() const { return numVertices; }
};

#endif // GRAFO_H
