#include "grafo_matriz.h"
#include <iostream>

using namespace std;

grafo_matriz::grafo_matriz(int a, bool b, bool c, bool d, int v[])
{

	n = a;
	pond_v = b;
	pond_a = c;
	dir = d;

	if (dir == 1)  // caso grafo direcionado aloca uma matriz com o duplo ponteiro grafo e prenche com 0 para cada aresta por padrão
	{
		grafo = new int* [n];
		for (int i = 0; i < n; i++)
		{
			grafo[i] = new int[n]();
		}

		for (int j = 0;j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				grafo[j][k] = 0;
			}
		}
	}
	else   // caso não direcionado aloca uma array que representa uma matriz triangular com 0 para cada aresta por padrão
	{

		int x = tam_lista(a);
		grafo = new int* [1];
		grafo[0] = new int[x];
		for (int h = 0; h < x; h++)
		{
			grafo[0][h] = 0;
		}
	}


	if (pond_v == 0)   // caso vertices não ponderados todos possuem valor 1(pensei em deixar um array de 1 mas pra q?)
	{
		vert = new int(1);
	}
	else     // caso vertices ponderados é alocado um array com o valor de cada vertice
	{
		vert = new int[n];
		for (int k = 0; k < n; k++)
		{
			vert[k] = v[k];
		}
	}
}

int grafo_matriz::tam_lista(int a)	// função que retorna o tamanho de uma array que representa uma matriz triangular quadrada de a colunas/linhas
{
	return (a * (a + 1)) / 2;
}

grafo_matriz :: ~grafo_matriz()
{

	if (dir == 1)    // caso grafo direcionado irá deletar uma matriz
	{
		for (int i = 0; i < n; i++)
		{
			delete[] grafo[i];
		}
		delete[] grafo;
	}
	else     // caso grafo não direcionado irá deletar uma array
	{
		delete[] grafo[0];
		delete[] grafo;
	}

	delete[] vert;
}

void grafo_matriz::adiciona_aresta(int a, int b, int c) // 'a' vertice de origem 'b' vertice de destino 'c' peso da aresta
{
	if (dir == 1)
	{
		if (pond_a == 1)
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

		if (pond_a == 1)
		{
			if (a <= b)
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
			if (a <= b)
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

void grafo_matriz::imprime_grafo()
{
	if (dir == 1)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << grafo[i][j] << "  ";
			}
			cout << endl;
		}

	}
	else
	{
		int x = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
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

bool grafo_matriz::eh_direcionado()
{
	return dir;
}

bool grafo_matriz::vertice_ponderado()
{
	return pond_v;
}



bool grafo_matriz::aresta_ponderada()
{
	return pond_a;
}

