#ifndef GRAFO_H
#define GRAFO_H

class Grafo {
protected:
    int** adjacencias; // Matriz de adjacências
    int numVertices;   // Número de vértices

    bool ponderadoVertices; //pesoVerticesicesices  0 == n�o ponderados  1 == ponderados
	bool ponderadosArestas; //arestas 0 == n�o ponderadas  1 == ponderadas
	bool direcionado; // 0 == n�o direcionado 1 == direcionado

public:
    Grafo(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado);  // Construtor
    virtual ~Grafo();        // Destrutor

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
};

#endif // GRAFO_H
