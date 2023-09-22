#include "huffman.hpp"
#include "blocoR.hpp"
#include "heap.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

huffman::huffman() {

}
void huffman::insere(blocoR r) {
	this->filaPrioridade.push_back(r);
}




/*
void Huffman_Tree::constroi() {
	while (this->filaPrioridade_.size() > 1) {
		std::shared_ptr<NO_Huffman> x = this->filaPrioridade_[0];
		std::shared_ptr<NO_Huffman> y = this->filaPrioridade_[1];

		auto z = std::make_shared<NO_Huffman>("#", x->getFrequencia() + y->getFrequencia());

		z->setEsquerda(x);
		z->setDireita(y);

		this->filaPrioridade_.erase(this->filaPrioridade_.begin());
		this->filaPrioridade_.erase(this->filaPrioridade_.begin());

		this->insere(z);

		sort(this->filaPrioridade_.begin(), this->filaPrioridade_.end(), NO_Huffman::compara);
	}
	this->raiz_ = this->filaPrioridade_[0];
}*/




void huffman::constroi() {
	bool fim = false;
	blocoR *x = new blocoR;
	blocoR *y = new blocoR;
	blocoR *z = new blocoR;
	while (fim == false) {

		*x = this->filaPrioridade[0];
		*y = this->filaPrioridade[1];
		cout << "\n\nimprime Z:";
		/*teste.getRecord().imprime();
		teste.setFrequencia(x->getRecord().getFrequencia() + y->getRecord().getFrequencia());
		teste.getRecord().imprime();*/

		z->setFrequencia(x->getRecord().getFrequencia() + y->getRecord().getFrequencia());
		z->setEsq(x);
		z->setDir(y);
		if (y->getPesoDir() > y->getPesoEsq()) {
			z->setPesoDir(y->getPesoDir() + 1);
		} else {
			z->setPesoDir(y->getPesoEsq() + 1);
		}
		if (x->getPesoEsq() > x->getPesoDir()) {
			z->setPesoEsq(x->getPesoEsq() + 1);
		} else {
			z->setPesoEsq(x->getPesoDir() + 1);
		}
		x->setPai(z);
		y->setPai(z);

		z->imprime();

		this->filaPrioridade.erase(this->filaPrioridade.begin());
		this->filaPrioridade.erase(this->filaPrioridade.begin());

		cout << "\n\nIMPRIME X:";
		x->imprime();
		cout << "\n\nIMPRIME Y:";
		y->imprime();
		opera();
		cout << "\n\nDepois do Opera:";
		for (int i = 0;i < (int)this->filaPrioridade.size();i++) {
			this->filaPrioridade[i].imprime();
		}
		this->insere(*z);
		cout << "\n\nDepois do Insere:";
		for (int i = 0;i < (int)this->filaPrioridade.size();i++) {
			this->filaPrioridade[i].imprime();
		}
		cout << "\n\n\n";
		if ((int)this->filaPrioridade.size() == 1) {
			fim = true;
			cout << "\nENTREI no IF\n";
		}
	}
	cout << "\n\n\nACABOU";
	//*this->raiz = filaPrioridade[0];
	cout << "\n\n\nACABOU";
	x = NULL;
	y = NULL;
	z = NULL;
	delete x;
	delete y;
	delete z;
}


void huffman::opera() {

	blocoR aux;
	for (int i = ((int)this->filaPrioridade.size() / 2 - 1); i > 0; i--) {
		if (filaPrioridade[i].getRecord().getFrequencia() > filaPrioridade[2 * i].getRecord().getFrequencia()) {
			aux = filaPrioridade[i];
			filaPrioridade[i] = filaPrioridade[2 * i];
			filaPrioridade[2 * i] = aux;
		}
		if (filaPrioridade[i].getRecord().getFrequencia() > filaPrioridade[(2 * i) + 1].getRecord().getFrequencia()) {
			aux = filaPrioridade[i];
			filaPrioridade[i] = filaPrioridade[(2 * i) + 1];
			filaPrioridade[(2 * i) + 1] = aux;
		}
	}
	if (filaPrioridade[0].getRecord().getFrequencia() > filaPrioridade[1].getRecord().getFrequencia()) {
		aux = filaPrioridade[0];
		filaPrioridade[0] = filaPrioridade[1];
		filaPrioridade[1] = aux;
	}
	if (filaPrioridade[0].getRecord().getFrequencia() > filaPrioridade[2].getRecord().getFrequencia()) {
		aux = filaPrioridade[0];
		filaPrioridade[0] = filaPrioridade[2];
		filaPrioridade[2] = aux;
	}
}














void huffman::central() {
	constroi();
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			//cout << "\n\nRecursão:";
			centralRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void huffman::centralRecursivo(blocoR *br) {
	if (br != NULL) {
		centralRecursivo(br->getEsq());
		br->getRecord().imprime();
		centralRecursivo(br->getDir());
	}
	return;
}


void huffman::preOrdem() {
	constroi();
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			preOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void huffman::preOrdemRecursivo(blocoR *br) {
	if (br != NULL) {

		br->getRecord().imprime();
		preOrdemRecursivo(br->getEsq());
		preOrdemRecursivo(br->getDir());
	}
	return;
}

void huffman::posOrdem() {
	constroi();
	if (this->raiz != NULL) {
		if (raiz != NULL) {
			posOrdemRecursivo(this->raiz);
		} else {
			cout << "Arvore vazia";
		}

	}

}

void huffman::posOrdemRecursivo(blocoR *br) {
	if (br != NULL) {
		posOrdemRecursivo(br->getEsq());
		posOrdemRecursivo(br->getDir());
		br->getRecord().imprime();
	}
	return;
}