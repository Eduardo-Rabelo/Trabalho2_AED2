#ifndef ARVORE_HPP
#define ARVORE_HPP
#include <iostream>
#include "record.hpp"
#include "blocoR.hpp"
#include "record.hpp"
using namespace std;

class Tree {
private:
	blocoR *raiz;
	blocoR *morto;
	//blocoR *dir, *esq;
	void centralRecursivo(blocoR *br);
	void preOrdemRecursivo(blocoR *br);
	void posOrdemRecursivo(blocoR *br);

public:
	Tree();
	bool TVazia();

	void inserir(record r);
	void central();
	void preOrdem();
	void posOrdem();
	void teste(record r);
	void meuInserir(blocoR r);
	/*void insertTree_alt(Tree **t, Record r);


	void pesquisa(Tree **t, Tree **aux, Record r);
	Tree *pesquisa_alt(Tree **t, int key);
	Tree *pesquisa_alt_nr(Tree *t, int key);

	int isInTree(Tree *t, Record r);

	void removeTree(Tree **t, Record r);
	void antecessor(Tree **t, Tree *aux);
	/*
		void preordem(Tree *t);
		void central(Tree *t);
		void posordem(Tree *t);
		void widthPath(Tree *t);
	*/
};
#endif