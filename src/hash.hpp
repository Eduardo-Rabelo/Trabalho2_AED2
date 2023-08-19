#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include "bloco.hpp"
#include <vector>
#define tam 13

using namespace std;
class tabelaHash{
    private:
        bloco hashBlocos[tam];
        int calculoHash(string p);
        int calculo2Hash(string p);
    public:
        tabelaHash();
        void teste();
        void inserir(Palavra p);
        void imprimeHash();
    
};
#endif