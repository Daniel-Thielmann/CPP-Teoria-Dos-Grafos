#include <iostream>
#include "no.h"


	No::No(int valor) // construtor
	{
		this->valor= valor;
		this->prox = NULL;
	}

	int No::getValor() // obtém o valor do nó
	{
		return valor;
	}

	No* No::getProx() // obtém o próximo No
	{
		return prox;
	}

	void No::setProx(No* p) // seta o próximo No
	{
		prox = p;
	}
