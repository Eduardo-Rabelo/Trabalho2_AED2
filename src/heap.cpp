#include "heap.hpp"
#include <iostream>
using namespace std;

heap::heap(int tam, Palavra v[]) {

    this->tam = tam;
    for (int i = 0; i < this->tam; i++) {
        insere(v[i]);
    }
    opera();
}
heap::heap() {
    this->tam = 0;
}
void heap::insere(Palavra p) {
    this->palavras.push_back(p);
}

void heap::opera() {
    Palavra aux;
    for (int i = (this->tam / 2 - 1); i > 0; i--) {
        if (this->palavras[i].getFrequencia() > this->palavras[2 * i].getFrequencia()) {
            aux = this->palavras[i];
            this->palavras[i] = this->palavras[2 * i];
            this->palavras[2 * i] = aux;
        }
        if (this->palavras[i].getFrequencia() > this->palavras[(2 * i) + 1].getFrequencia()) {
            aux = this->palavras[i];
            this->palavras[i] = this->palavras[(2 * i) + 1];
            this->palavras[(2 * i) + 1] = aux;
        }
    }
    if (this->palavras[0].getFrequencia() > this->palavras[1].getFrequencia()) {
        aux = this->palavras[0];
        this->palavras[0] = this->palavras[1];
        this->palavras[1] = aux;
    }
    if (this->palavras[0].getFrequencia() > this->palavras[2].getFrequencia()) {
        aux = this->palavras[0];
        this->palavras[0] = this->palavras[2];
        this->palavras[2] = aux;
    }
}

void heap::imprime() {
    for (int i = 0;i < this->tam;i++) {
        this->palavras[i].imprime();
    }
}
bool heap::addPalavra(Palavra p) {
    if (p.getFrequencia() > this->palavras[0].getFrequencia()) {
        this->palavras[0] = p;
        opera();
        return true;
    } else {
        return false;
    }
}

vector<Palavra> heap::getPalavras() {
    return this->palavras;
}