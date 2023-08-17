#ifndef HEAP_HPP
#define HEAP_HPP
#include <iostream>
#include <vector>
using namespace std;
class heap
{
private:
    int tam;
    vector<int> palavras;
    void insere(int p);
    void opera();

public:
    heap(int tam, int v[]);
    void imprime();
};

#endif
