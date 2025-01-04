#ifndef GRAFO_MATRIZ_H
#define GRAFO_MATRIZ_H

#include <vector>
#include <iostream>
#using namespace std;



class grafo_matriz
{
private:

	const int MAX = 50; // numero maximo de vertices (ainda vai ser trocado )
	int vertices[MAX];
	int matriz[MAX][MAX]; // matriz do grafo direcionado
	int lista[MAX]; // lista do grafo não direcionado
	int n; // numero de vertices
	bool pond_v; //vertices  0 == não ponderado  1 == ponderado
	bool pond_a; //arestas 0 == não ponderado  1 == ponderado
	bool dir; // 0 == não direcionado 1 == direcionado
	int tam_lista(int a);

public:

	grafo_matriz(int a, bool b, bool c, bool d, int v[]);
	~grafo_matriz();
	void adiciona_aresta(int a, int b,int c);
	bool eh_direcionado();
	bool vertice_ponderado();
	bool aresta_ponderada();
	
};

#endif