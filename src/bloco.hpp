#ifndef BLOCO_HPP
#define BLOCO_HPP
#include "Palavra.hpp"
#include <iostream>
using namespace std;
class bloco{
    private:
        Palavra palavra;
        Palavra *ant,*prox;
    public:
        bloco();
        bloco(Palavra p);
        int getFrequencia();
        Palavra getPalavra();
        void add();

};
#endif