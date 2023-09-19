#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>
#include "blocoR.hpp"
using namespace std;
class avl {
private:
	blocoR *raiz;
	blocoR *morto;
	//blocoR *dir, *esq;
	void centralRecursivo(blocoR *br);
	void preOrdemRecursivo(blocoR *br);
	void posOrdemRecursivo(blocoR *br);
	bool comparacaoAlfabetica(string a, string b);

public:
	avl();
	bool TVazia();

	void inserir(Palavra r);
	void central();
	void preOrdem();
	void posOrdem();
	void meuInserir(blocoR r);

	int getPesoEsq(blocoR *br);
	int getPesoDir(blocoR *br);
	//bool getPesoTotal(blocoR r);
	void rebalanceia();

	void rebalanceia(blocoR *br, bool dir);
	void calculaPesoEsq(blocoR *br);
	void calculaPesoDir(blocoR *br);

	bool filhoDireito(blocoR *br);
	bool filhoEsquerdo(blocoR *br);
};
#endif