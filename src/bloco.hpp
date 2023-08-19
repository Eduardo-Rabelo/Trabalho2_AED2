#ifndef BLOCO_HPP
#define BLOCO_HPP
#include "Palavra.hpp"
#include <iostream>
using namespace std;
class bloco{
    private:
        Palavra palavra;
        bloco *ant,*prox;
    public:
        bloco();
        bloco(Palavra p);
        int getFrequencia();
        Palavra getPalavra();
        bloco *getProx();
        void setProx(bloco *b);
        void add();
        //~bloco();

};
#endif