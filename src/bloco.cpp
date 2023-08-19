#include "bloco.hpp"
#include <iostream>
using namespace std;

bloco::bloco(){
    Palavra p;
    this->palavra=p;
    this->ant=NULL;
    this->prox=NULL;
}
bloco::bloco(Palavra p){
    this->palavra=p;
    this->ant=NULL;
    this->prox=NULL;
}
Palavra bloco::getPalavra(){
    return this->palavra;
}
int bloco::getFrequencia(){
    return this->palavra.getFrequencia();
}

void bloco::add(){
    this->palavra.add();
}

bloco * bloco::getProx(){
    return this->prox;
}
void bloco::setProx(bloco *b){
    this->prox = b;
}