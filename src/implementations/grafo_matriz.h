#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include "../core/Grafo.h"
#include <iostream>
using namespace std;

class grafo_matriz : public Grafo
{
private:

	int * pesoVerticesices;  // valor de cada pesoVerticesicesice
	int ** grafo; // vector para substituir lista e matriz
	int tam_lista(int a);  // fun��o que retorna o tamanho de uma array que representa uma matriz triangular quadrada de a colunas/linhas


public:

	grafo_matriz(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado, int pesoVerticesices[]);
	~grafo_matriz();
	void adiciona_aresta(int a, int b,int c);
	void imprime_grafo() override;
	bool ehConexo() override;
	void dfsConexao(int vertice, bool *verticeVerificado);
	bool ehArvore() override;
	bool temCiclo();
	bool ehCompleto() override;
	int* getArestas(int id) const override;


	
};

#endif // GRAFO_MATRIZ_H