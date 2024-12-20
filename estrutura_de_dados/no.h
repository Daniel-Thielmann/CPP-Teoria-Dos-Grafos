#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include <iostream>

class No
{
private:
	int valor;
	No* prox;
public:
	
    No(int valor); // construtor
	int getValor(); // obtém o valor
	No* getProx(); // obtém o próximo No
	void setProx(No* p); // seta o próximo No
	
};

#endif