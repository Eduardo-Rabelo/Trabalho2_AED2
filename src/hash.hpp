#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include "bloco.hpp"
#include <vector>
#define tam 10

using namespace std;
class tabelaHash{
    private:
        bloco hashBlocos[tam];

    public:
        tabelaHash();
        void teste();
    
};
#endif