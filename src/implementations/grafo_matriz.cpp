#include "grafo_matriz.h"
#include <iostream>

using namespace std;

grafo_matriz::grafo_matriz(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado, int pesoVerticesices[]) : Grafo(numVertices, ponderadoVertices, ponderadosArestas, direcionado)
{

	if (direcionado == 1)  // caso grafo direcionado aloca uma matriz com o duplo ponteiro grafo e prenche com 0 para cada aresta por padr�o
	{
		grafo = new int* [numVertices];
		for (int i = 0; i < numVertices; i++)
		{
			grafo[i] = new int[numVertices]();
		}

		for (int j = 0;j < numVertices; j++)
		{
			for (int k = 0; k < numVertices; k++)
			{
				grafo[j][k] = 0;
			}
		}
	}
	else   // caso n�o direcionado aloca uma array que representa uma matriz triangular com 0 para cada aresta por padr�o
	{

		int x = tam_lista(numVertices);
		grafo = new int* [1];
		grafo[0] = new int[x];
		for (int h = 0; h < x; h++)
		{
			grafo[0][h] = 0;
		}
	}


	if (ponderadoVertices == 0)   // caso vertices n�o ponderados todos possuem valor 1(pensei em deixar um array de 1 mas pra q?)
	{
		pesoVerticesices = new int(1);
	}
	else     // caso vertices ponderados � alocado um array com o valor de cada vertice
	{
		pesoVerticesices = new int[numVertices];
		for (int k = 0; k < numVertices; k++)
		{
			this->pesoVerticesices[k] = pesoVerticesices[k];
		}
	}
}

int grafo_matriz::tam_lista(int a)	// fun��o que retorna o tamanho de uma array que representa uma matriz triangular quadrada de a colunas/linhas
{
	return (a * (a + 1)) / 2;
}

grafo_matriz :: ~grafo_matriz()
{

	if (direcionado == 1)    // caso grafo direcionado ir� deletar uma matriz
	{
		for (int i = 0; i < numVertices; i++)
		{
			delete[] grafo[i];
		}
		delete[] grafo;
	}
	else     // caso grafo n�o direcionado ir� deletar uma array
	{
		delete[] grafo[0];
		delete[] grafo;
	}

	delete[] pesoVerticesices;
}

void grafo_matriz::adiciona_aresta(int a, int b, int c) // 'a' vertice de origem 'b' vertice de destino 'c' peso da aresta
{
	if (a != b)
	{
		if (direcionado == 1)
		{
			if (ponderadosArestas == 1)
			{
				grafo[a - 1][b - 1] = c;
			}
			else
			{
				grafo[a - 1][b - 1] = 1;
			}
		}
		else
		{

			if (ponderadosArestas == 1)
			{
				if (a < b)
				{
					grafo[0][a + tam_lista(b - 1) - 1] = c;
				}
				else
				{
					grafo[0][b + tam_lista(a - 1) - 1] = c;
				}
			}

			else
			{
				if (a < b)
				{
					grafo[0][a + tam_lista(b - 1) - 1] = 1;
				}
				else
				{
					grafo[0][b + tam_lista(a - 1) - 1] = 1;
				}
			}
		}
	}
}

void grafo_matriz::imprime_grafo()
{
	if (direcionado == 1)
	{
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				cout << grafo[i][j] << "  ";
			}
			cout << endl;
		}

	}
	else
	{
		int x = 0;
		for (int i = 0; i < numVertices; i++)
		{
			for (int j = 0; j < numVertices; j++)
			{
				if (i >= j)
				{
					cout << grafo[0][x] << "  ";
					x++;
				}
				else
					cout << "0  ";

			}
			cout << endl;
		}
	}
}


// Verifica se todos os termos se conectam
bool grafo_matriz::ehConexo()
{
	if(numVertices == 0)
		return true;
	bool * verticeVerificado;
	verticeVerificado = new bool[numVertices];
	for(int i = 0; i < numVertices; i++)
		verticeVerificado[i] = false;
	dfsConexao(0, verticeVerificado);
	for(int i = 0; i < numVertices; i++)
		if(verticeVerificado[i] == false)
			return false;
	return true;
}

// Função auxiliar de ehConexo que verifica se todos os vertices serao encontrados ao começar pelo vertice de indice 0
void grafo_matriz::dfsConexao(int vertice, bool * verticeVerificado){
	verticeVerificado[vertice] = true;
	if(direcionado)
	{
		for(int i = 0; i < numVertices; i++)
			if((!verticeVerificado[i] && vertice != i && grafo[vertice][i] != 0))
				dfsConexao(i,verticeVerificado);
	}
	else{
		int x = 0;
		for (int i = 0; i < numVertices; i++){ 
            for (int j = 0; j < i; j++, x++){ 
                if ((i == vertice || j == vertice) && i != j) {
                    int vizinho;
					if (i == vertice)
						vizinho = j;
					 else
						vizinho = i;
                    if (!verticeVerificado[vizinho] && grafo[0][x] != 0)
                        dfsConexao(vizinho, verticeVerificado);
				}
			}
		}
	}
	return;
}

// Função que verifica se todos os vertices fazem conexao entre si
bool grafo_matriz::ehCompleto()
{
	if(direcionado){
		for(int i = 0; i < numVertices; i++)
			for(int j = 0; j < numVertices; j++){
				if(i != j && grafo[i][j] == 0)
					return false;
        }
	}
	else{
		int x = tam_lista(numVertices);
		for(int i = 0; i < numVertices; i++)
			if(grafo[0][i] == 0)
				return false;
	}
	return true;
}

// Função que verifica se eh uma arvore
bool grafo_matriz::ehArvore()
{
	int numeroArestas = 0;
	if(!ehConexo())
		return false;
	if(direcionado){
		for(int i = 0; i < numVertices; i++)
			for(int j = 0; j < numVertices; j++)
				if(j != i && grafo[i][j] != 0)
					numeroArestas++;
	}
	else{
		for(int i = 0; i < tam_lista(numVertices); i++)
			if(grafo[0][i] != 0)
				numeroArestas++;
	}
	if(temCiclo())
		return false;
	return true;
}

// Função auxiliar para verificar se tem ciclo
bool grafo_matriz::temCiclo()
{

}