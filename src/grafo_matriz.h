#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include <vector>
#include <iostream>
using namespace std;



class grafo_matriz
{
private:

	int * pesoVerticesices;  // valor de cada pesoVerticesicesice
	int ** grafo; // vector para substituir lista e matriz

	int n; // numero de pesoVerticesicesices
	bool ponderadoVertices; //pesoVerticesicesices  0 == n�o ponderados  1 == ponderados
	bool ponderadosArestas; //arestas 0 == n�o ponderadas  1 == ponderadas
	bool direcionado; // 0 == n�o direcionado 1 == direcionado
	int tam_lista(int a);  // fun��o que retorna o tamanho de uma array que representa uma matriz triangular quadrada de a colunas/linhas


public:

	grafo_matriz(int a, bool b, bool c, bool d, int v[]);
	~grafo_matriz();
	void adiciona_aresta(int a, int b,int c);
	bool ehDirecionado();
	bool verticePonderado();
	bool arestaPonderada();
	void imprime_grafo();
	int get_ordem();
	bool ehConexo();
	void dfsConexao(int vertice, bool *verticeVerificado);
	bool ehArvore();
	bool temCiclo();
	bool ehCompleto();

	
};

#endif