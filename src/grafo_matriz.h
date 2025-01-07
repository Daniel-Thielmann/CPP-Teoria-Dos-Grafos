#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include <vector>
#include <iostream>
using namespace std;



class grafo_matriz
{
private:

	int * vert;  // valor de cada vertice
	int ** grafo; // vector para substituir lista e matriz

	int n; // numero de vertices
	bool pond_v; //vertices  0 == não ponderados  1 == ponderados
	bool pond_a; //arestas 0 == não ponderadas  1 == ponderadas
	bool dir; // 0 == não direcionado 1 == direcionado
	int tam_lista(int a);  // função que retorna o tamanho de uma array que representa uma matriz triangular quadrada de a colunas/linhas


public:

	grafo_matriz(int a, bool b, bool c, bool d, int v[]);
	~grafo_matriz();
	void adiciona_aresta(int a, int b,int c);
	bool eh_direcionado();
	bool vertice_ponderado();
	bool aresta_ponderada();
	void imprime_grafo();

	
};

#endif