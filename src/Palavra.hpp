#ifndef PALAVRA_HPP
#define PALAVRA_HPP
#include <iostream>
using namespace std;
class Palavra{
    private:
        int frequencia;
        string palavra;
    public:
        Palavra(string palavra);
        Palavra();
        void add();
        void imprime();
        int getFrequencia();
};
#endif