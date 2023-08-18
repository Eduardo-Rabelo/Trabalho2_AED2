#include "bloco.hpp"
#include <iostream>
using namespace std;

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