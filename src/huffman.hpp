#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Palavra.hpp"
#include "blocoR.hpp"
#include "heap.hpp"

using namespace std;

class huffman {
private:
	vector<blocoR> filaPrioridade;
	blocoR *raiz;

	void centralRecursivo(blocoR *br);
	void preOrdemRecursivo(blocoR *br);
	void posOrdemRecursivo(blocoR *br);

public:
	huffman();

	void insere(blocoR r);
	void constroi();

	void central();
	void preOrdem();
	void posOrdem();

	void opera();
};

#endif