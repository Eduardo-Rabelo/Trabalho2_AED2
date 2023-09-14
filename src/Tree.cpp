#include "Tree.hpp"
#include "blocoR.hpp"
#include <iostream>
using namespace std;

Tree::Tree() {
	this->raiz = NULL;
	this->morto = NULL;
}

bool Tree::TVazia() {
	if (this->raiz == NULL) {
		return true;
	} else {
		return false;
	}
}

void Tree::teste(record r) {
	blocoR *bp;
	blocoR b(r);
	bp = &b;
	bp->getRecord().imprime();
}
/*
void Tree::inserir(record r) {
	int cont = 0;
	blocoR b(r);
	blocoR *aux;
	aux = &b;
	aux->getRecord().imprime();
	bool end = false;
	blocoR *br;

	if (TVazia()) {
		this->raiz = aux;
	}

	else {
		this->raiz->getRecord().imprime();
		br = this->raiz;
		while (end == false) {
			cout << cont << "\n";
			cont++;
			if (r.getKey() < br->getRecord().getKey()) {
				if (br->getEsq() != NULL) {
					br = br->getEsq();
				} else {
					br->setEsq(aux);
					end = true;
				}
			} else if (r.getKey() > br->getRecord().getKey()) {
				if (br->getDir() != NULL) {
					br = br->getDir();
				} else {
					br->setDir(aux);
					end = true;
				}
			} else if (r.getKey() == br->getRecord().getKey()) {
				r.imprime();
				br->getRecord().imprime();
				cout << "ERRO KEY IGUAL";
				end = true;
			}
		}
	}
}*/

void Tree::meuInserir(blocoR r) {
	bool end = false;

	blocoR *br, *aux = new blocoR(r);
	//aux = &r;
	aux->setDir(this->morto);
	aux->setEsq(this->morto);
	if (this->raiz == NULL) {
		this->raiz = aux;
		this->raiz->setDir(this->morto);
		this->raiz->setEsq(this->morto);
		this->raiz->getRecord().imprime();
		this->raiz->verFilhos();
		cout << "\n\n";
	}

	else {
		br = raiz;
		while (end == false) {
			if (aux->getRecord().getKey() > br->getRecord().getKey()) {
				if (br->getDir() == NULL) {
					br->setDir(aux);
					end = true;
				} else {
					br = br->getDir();
				}
			} else if (aux->getRecord().getKey() < br->getRecord().getKey()) {
				if (br->getEsq() == NULL) {
					br->setEsq(aux);
					end = true;
				} else {
					br = br->getEsq();
				}
			} else {
				cout << "\n\nERRO IGUAL\n\n";
				end = true;
			}
		}
	}
	aux = NULL;
	delete aux;
	br = NULL;
	delete br;
}

void Tree::central() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			centralRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void Tree::centralRecursivo(blocoR *br) {
	if (br != NULL) {
		centralRecursivo(br->getEsq());
		br->getRecord().imprime();
		centralRecursivo(br->getDir());
	}
	return;
}


void Tree::preOrdem() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			preOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void Tree::preOrdemRecursivo(blocoR *br) {
	if (br != NULL) {

		br->getRecord().imprime();
		preOrdemRecursivo(br->getEsq());
		preOrdemRecursivo(br->getDir());
	}
	return;
}

void Tree::posOrdem() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			posOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void Tree::posOrdemRecursivo(blocoR *br) {
	if (br != NULL) {
		posOrdemRecursivo(br->getEsq());
		posOrdemRecursivo(br->getDir());
		br->getRecord().imprime();
	}
	return;
}
/*
void insertTree(Tree **t, Record r){

  if(TVazia(t)){
	*t = (Tree*)malloc(sizeof(Tree));
	(*t)->esq = NULL;
	(*t)->dir = NULL;
	(*t)->reg = r;

  } else {

	if(r.key < (*t)->reg.key){
	  insertTree(&(*t)->esq, r);
	}

	if(r.key > (*t)->reg.key){
	  insertTree(&(*t)->dir, r);
	}

  }

}*/