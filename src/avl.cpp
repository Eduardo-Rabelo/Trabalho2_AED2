#include "avl.hpp"
#include "blocoR.hpp"
#include <iostream>
using namespace std;

avl::avl() {
	this->raiz = NULL;
	this->morto = NULL;
}

bool avl::TVazia() {
	if (this->raiz == NULL) {
		return true;
	} else {
		return false;
	}
}

void avl::meuInserir(blocoR r) {
	bool end = false;

	blocoR *br = new blocoR(r), *aux = new blocoR(r);
	//aux = &r;
	aux->setDir(this->morto);
	aux->setEsq(this->morto);
	aux->setPai(this->morto);
	aux->setPesoDir(0);
	aux->setPesoEsq(0);
	aux->setNivel(0);

	if (this->raiz == NULL) {
		this->raiz = aux;
		this->raiz->setDir(this->morto);
		this->raiz->setEsq(this->morto);
		this->raiz->setPai(this->morto);
		this->raiz->setNivel(0);
		this->raiz->getRecord().imprime();
		cout << "\nINSERI RAIZ\n";
		//this->raiz->verFilhos();
		//cout << "\nEntrei no if\n";
	}

	else {
		br = raiz;
		while (end == false) {
			if (aux->getRecord().getNome() == br->getRecord().getNome()) {
				cout << "\n\nERRO IGUAL\n\n";
				end = true;
			} else if (aux->getRecord().getFrequencia() > br->getRecord().getFrequencia()) {
				cout << "\nDIREITA\n";
				if (br->getDir() == NULL) {
					aux->setNivel(br->getNivel() + 1);
					br->setDir(aux);
					br->getDir()->setPai(br);
					cout << "\nINSERI\n";
					aux->imprime();
					cout << "\n\n";
					rebalanceia(br, true, true);
					end = true;
				} else {
					br = br->getDir();
				}
			} else if (aux->getRecord().getFrequencia() <= br->getRecord().getFrequencia()) {
				cout << "\nESQUERDA\n";
				if (br->getEsq() == NULL) {
					aux->setNivel(br->getNivel() + 1);
					br->setEsq(aux);
					br->getEsq()->setPai(br);
					cout << "\nINSERI\n";
					aux->imprime();
					cout << "\n\n";
					rebalanceia(br, false, true);
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

void avl::rebalanceia(blocoR *br, bool dir, bool insertion) {
	blocoR *b = new blocoR();
	b = br;
	if (insertion == true) {
		if (dir) {
			b->addPesoDir();
		} else {
			b->addPesoEsq();
		}
	}

	while (b->getPai() != NULL) {

		rotacoes(b);

		if (filhoDireito(b)) {
			b = b->getPai();
			pesarDireita(b);
		} else if (filhoEsquerdo(b)) {
			b = b->getPai();
			pesarEsquerda(b);
		} else {
			cout << "\n\n\nERRO FILHO\n\n\n";
		}
	}
	b = NULL;
	delete b;

}

void avl::rotacoes(blocoR *br) {
	blocoR *b = new blocoR;
	b = br;
	if (b->getPesoTotal() >= 2) {

		if (b->getDir()->getPesoTotal() >= 0) {
			cout << "\nROTACAO SIMPLES ESQUERDA\n";
			rotacaoSimplesEsquerda(b);
		}

	}

	else if (b->getPesoTotal() <= -2) {
		if (b->getEsq()->getPesoTotal() < 0) {
			cout << "\nROTACAO SIMPLES DIREITA\n";
			rotacaoSimplesDireita(b);////////FFALTA ISSO AINDA
		}
	}
}


void avl::rotacaoSimplesEsquerda(blocoR *br) {
	blocoR *b = new blocoR, *aux = new blocoR;

	b = br->getDir();
	aux = br;

	b->setPai(br->getPai());

	aux->setDir(b->getEsq());
	if (b->getEsq() != NULL) {
		b->getEsq()->setPai(aux);
	}

	b->setEsq(aux);
	if (filhoDireito(aux)) {
		if (aux->getPai() != NULL) {
			aux->getPai()->setDir(b);
		}
	} else {
		if (aux->getPai() != NULL) {
			aux->getPai()->setEsq(b);
		}
		cout << "ELSE FILHO 2";
	}
	aux->setPai(b);
	int intAux = b->getNivel();
	b->setNivel(aux->getNivel());
	aux->setNivel(intAux);

	pesarDireita(aux);
	pesarEsquerda(b);

	aux->imprime();
	b->imprime();
	if (filhoDireito(b)) {
		rebalanceia(b, true, false);
	} else if (filhoEsquerdo(b)) {
		rebalanceia(b, false, false);
	}
	cout << "\n\n\n";
	aux = NULL;
	delete aux;
	b = NULL;
	delete b;

}



void avl::rotacaoSimplesDireita(blocoR *br) {
	blocoR *b = new blocoR, *aux = new blocoR;

	b = br->getEsq();
	aux = br;

	b->setPai(br->getPai());

	aux->setEsq(b->getDir());
	if (b->getDir() != NULL) {
		b->getDir()->setPai(aux);
	}

	b->setDir(aux);

	if (filhoEsquerdo(aux)) {
		if (aux->getPai() != NULL) {
			aux->getPai()->setEsq(b);
		}
	} else {
		if (aux->getPai() != NULL) {
			aux->getPai()->setDir(b);
		}
		cout << "ELSE FILHO 2";
	}

	aux->setPai(b);
	cout << "\nATE AQUI FOI\n";

	int intAux = b->getNivel();
	b->setNivel(aux->getNivel());
	aux->setNivel(intAux);
	aux->imprime();
	b->imprime();
	pesarEsquerda(aux);
	pesarDireita(b);

	aux->imprime();
	b->imprime();
	if (filhoDireito(b)) {
		rebalanceia(b, true, false);
	} else if (filhoEsquerdo(b)) {
		rebalanceia(b, false, false);
	}
	cout << "\n\n\n";

	aux = NULL;
	delete aux;
	b = NULL;
	delete b;


}

void avl::pesarDireita(blocoR *br) {
	blocoR *b = new blocoR;
	b = br;
	if (b->getDir() == NULL) {
		b->setPesoDir(0);
		return;
	}
	if (b->getDir()->getPesoDir() > b->getDir()->getPesoEsq()) {
		b->setPesoDir(b->getDir()->getPesoDir() + 1);
	} else if (b->getDir()->getPesoDir() <= b->getDir()->getPesoEsq()) {
		b->setPesoDir(b->getDir()->getPesoEsq() + 1);
	} else {
		cout << "ERRO DE PESO ";
	}
	b = NULL;
	delete b;
}
void avl::pesarEsquerda(blocoR *br) {
	blocoR *b = new blocoR;
	b = br;
	if (b->getEsq() == NULL) {
		b->setPesoEsq(0);
		return;
	}
	if (b->getEsq()->getPesoDir() > b->getEsq()->getPesoEsq()) {
		b->setPesoEsq(b->getEsq()->getPesoDir() + 1);
	} else if (b->getEsq()->getPesoDir() <= b->getEsq()->getPesoEsq()) {
		b->setPesoEsq(b->getEsq()->getPesoEsq() + 1);
	} else {
		cout << "ERRO DE PESO ";
	}
	b = NULL;
	delete b;
}


bool avl::filhoDireito(blocoR *br) {
	if (br->getPai()->getDir() == br) {
		return true;
	}
	return false;
}
bool avl::filhoEsquerdo(blocoR *br) {
	if (br->getPai()->getEsq() == br) {
		return true;
	}
	return false;
}
/*
void avl::pesquisa(string str) {
	record *re = new record(str);
	blocoR *r = new blocoR(*re);

	if (this->raiz == NULL) {
		cout << "\n\nÁrvore Vazia\n\n";
	} else {
		pesquisaRecursiva(*r);
	}
}
void avl::pesquisaRecursiva(blocoR r) {
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

void avl::central() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			//cout << "\n\nRecursão:";
			centralRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void avl::centralRecursivo(blocoR *br) {
	if (br != NULL) {
		centralRecursivo(br->getEsq());
		br->imprime();
		centralRecursivo(br->getDir());
	}
	return;
}


void avl::preOrdem() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			preOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void avl::preOrdemRecursivo(blocoR *br) {
	if (br != NULL) {

		br->imprime();
		preOrdemRecursivo(br->getEsq());
		preOrdemRecursivo(br->getDir());
	}
	return;
}

void avl::posOrdem() {
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			posOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void avl::posOrdemRecursivo(blocoR *br) {
	if (br != NULL) {
		posOrdemRecursivo(br->getEsq());
		posOrdemRecursivo(br->getDir());
		br->imprime();
	}
	return;
}

bool avl::comparacaoAlfabetica(string a, string b) {

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
int avl::getPesoDir(blocoR r) {
	blocoR *br = new blocoR(r), *aux = new blocoR(r);
	br = &r;
	aux = &r;
	br=
	aux = NULL;
	delete aux;
	br = NULL;
	delete br;
}*/




/*
void insertTree(avl **t, Record r){

  if(TVazia(t)){
	*t = (avl*)malloc(sizeof(avl));
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