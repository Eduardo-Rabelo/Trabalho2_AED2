#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
#include "Palavra.hpp"
using namespace std;
class heap
{
private:
    int tam;
    vector<Palavra> palavras;
    void insere(Palavra p);
    void opera();

public:
    heap(int tam, Palavra v[]);
    void imprime();
    bool addPalavra(Palavra p);
};

#endif
