#include "grafo_matriz.h"
#include <iostream>

grafo_matriz::grafo_matriz(int a, bool b, bool c, bool d, int v [])
{

	n = a;
	pond_v = b;
	pond_a = c;
	dir = d;

	if (dir == 1)
	{
		for (int i = 0, i < MAX, i++0)
		{
			for (int j = 0, j < MAX, j++0)
			{
				matriz[i][j] = 0;
			}
		}
	}
	else
	{
		int x = tam_lista(a);
		for (int h = 0, h < x, h ++)
		{
			lista[h]= 0;
		}
	}

	if (pond_v == 0)
	{
		for (int k = 0, k < a, k++)
		{
			vertices[k] = 1;
		}
	}
	else
	{
		for (int k = 0, k < a, k++)
		{
			vertices[k] = v[k];
		}
	}
}

int grafo_matriz::tam_lista(int a)
{
	int x=0;
	for (int i = 1, i <= a, i++)
	{
		x = x + i;
	}
	return x;
}

grafo_matriz :: ~grafo_matriz()
{

}

void grafo_matriz::adiciona_aresta(int a, int b,int c) // 'a' vertice de origem 'b' vertice de chegada 'c' peso da aresta
{
	if (dir == 0)
	{
		if (pond_a == 0)
		{
			if (a <= b)
			{
				lista[a + tam_lista(b - 1)] = 1;
			}
			else
			{
				lista[b + tam_lista(a - 1)] = 1;
			}
		}
		else
		{
			if (a <= b)
			{
				lista[a + tam_lista(b - 1)] = c;
			}
			else
			{
				lista[b + tam_lista(a - 1)] = c;
			}
		}
	}
	else
	{
		if (pond_a == 0)
		{
			matriz[a][b] = 1;
		}
		else
		{
			matriz[a][b] = c;
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

