#include <iostream>
#include "listaEncad.h"

 



listaEncad::listaEncad(){
   this->cabeca = NULL;
   this->cauda = NULL;

}

listaEncad::~listaEncad(){ 
   delete cabeca;
}

void listaEncad::criaNo(int valor){
   this->cabeca = new No(valor);  //Cria um novo nó
   cauda = cabeca;
}

void listaEncad::exibeLista(){
    std::cout << " \nImprimindo toda a lista \n";
    No* c = cabeca;

    if(ehVazia()){
        std::cout<< "A lista está vazia \n";
    }
    else{
        while(c!=NULL){
            std::cout << c->getValor();
            if (c->getProx() != NULL) { // Adiciona "->" entre os elementos
            std::cout << " -> ";
        }
            c = c->getProx();
        }
     std::cout << std::endl;
    }
}

bool listaEncad::ehVazia(){
 
    if (cabeca == nullptr) {
        return true;
    } else {
        return false;
    }


}

void listaEncad::insereFinal(int valor)
	{
		No* novoNo = new No(valor);

		if(ehVazia())
		{
			cabeca = novoNo;
			cauda = novoNo;
		}
		else
		{
			cauda->setProx(novoNo);
			cauda = novoNo;
		}
	}

int listaEncad::getTamanho()
	{
		if(ehVazia()) // se for vazia, entã retorna 0
			return 0;

		No* c = cabeca;
		int tam = 0;
		
		// percorre a lista
		do
		{
			c = c->getProx();
			tam++;
		}
		while(c);
		
		return tam;
	}

