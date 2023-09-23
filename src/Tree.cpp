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

void Tree::meuInserir(blocoR r) {
	bool end = false;

	blocoR *br = new blocoR(r), *aux = new blocoR(r);
	//aux = &r;
	aux->setDir(this->morto);
	aux->setEsq(this->morto);
	aux->setPai(this->morto);

	if (this->raiz == NULL) {
		this->raiz = aux;
		this->raiz->setDir(this->morto);
		this->raiz->setEsq(this->morto);
		this->raiz->setPai(this->morto);
		this->raiz->getRecord().imprime();
		//this->raiz->verFilhos();
		//cout << "\nEntrei no if\n";
	}

	else {
		br = raiz;
		while (end == false) {
			if (aux->getRecord().getNome() == br->getRecord().getNome()) {
				//cout << "\n\nERRO IGUAL\n\n";
				end = true;
			} else if (aux->getRecord().getFrequencia() > br->getRecord().getFrequencia()) {
				//cout << "\nDIREITA\n";
				if (br->getDir() == NULL) {
					br->setDir(aux);
					br->getDir()->setPai(br);
					end = true;
				} else {
					br = br->getDir();
				}
			} else if (aux->getRecord().getFrequencia() <= br->getRecord().getFrequencia()) {
				//cout << "\nESQUERDA\n";
				if (br->getEsq() == NULL) {
					br->setEsq(aux);
					br->getEsq()->setPai(br);
					end = true;
				} else {
					br = br->getEsq();
				}
			}
		}
	}

	/*cout << "PAI:";
	if (aux->getPai() != this->morto) {
		aux->getPai()->getRecord().imprime();
	}
	cout << "\nFIMPAI\n\n\n\n\n";*/

	aux = NULL;
	delete aux;
	br = NULL;
	delete br;
}
/*
void Tree::pesquisa(string str) {
	record *re = new record(str);
	blocoR *r = new blocoR(*re);

	if (this->raiz == NULL) {
		cout << "\n\nÁrvore Vazia\n\n";
	} else {
		pesquisaRecursiva(*r);
	}
}
void Tree::pesquisaRecursiva(blocoR r) {
	blocoR *br = new blocoR(r), *aux = new blocoR(r);
	aux = &r;
	if (this->raiz == NULL) {
		cout << "\n\nÁrvore Vazia\n\n";
	} else {
		br = raiz;
		if (!comparacaoAlfabetica(aux->getRecord().getNome(), br->getRecord().getNome())) {
			pesquisaRecursiva(*(br->getDir()));
		} else {
			pesquisaRecursiva(*(br->getEsq()));
		}
	}
}*/

void Tree::central() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			//cout << "\n\nRecursão:";
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

bool Tree::comparacaoAlfabetica(string a, string b) {

	if (a.size() < b.size()) {
		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i] < b[i]) {
				return true;
			} else if (a[i] > b[i]) {
				return false;
			}
		}
		return true;
	} else {
		for (int i = 0; i < (int)b.size(); i++) {
			if (a[i] < b[i]) {
				return true;
			} else if (a[i] > b[i]) {
				return false;
			}
		}
		return true;
	}
}
/*
void insertTree(Tree **t, Record r){

  if(TVazia(t)){
	*t = (Tree*)malloc(sizeof(Tree));
	(*t)->esq = NULL;
	(*t)->dir = NULL;
	(*t)->reg = r;

  } else {

	if(r.Nome < (*t)->reg.Nome){
	  insertTree(&(*t)->esq, r);
	}

	if(r.Nome > (*t)->reg.Nome){
	  insertTree(&(*t)->dir, r);
	}

  }

}*/