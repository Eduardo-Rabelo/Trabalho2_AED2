#ifndef BLOCOR_HPP
#define BLOCOR_HPP
#include "Palavra.hpp"
#include <iostream>
using namespace std;
class blocoR {
private:
    Palavra r;
    blocoR *esq, *dir, *pai;
    //int nivel;
    int pesoDir;
    int pesoEsq;
    int pesoTotal;
    void calculaPesoTotal();
public:
    blocoR();
    blocoR(Palavra r);
    Palavra getRecord();
    static bool compara(blocoR *a, blocoR *b) {
        return a->getRecord().getFrequencia() < b->getRecord().getFrequencia();
    }

    blocoR *getDir();
    void setDir(blocoR *b);
    blocoR *getEsq();
    void setEsq(blocoR *b);
    blocoR *getPai();
    void setPai(blocoR *b);

    //int getNivel();
    //void setNivel(int n);

    int getPesoDir();
    void setPesoDir(int p);
    void addPesoDir();

    int getPesoEsq();
    void setPesoEsq(int p);
    void addPesoEsq();

    int getPesoTotal();


    void setRecord(Palavra r);
    bool verDir();
    bool verEsq();
    void verFilhos();

    void imprime();
    void setFrequencia(int f);
    //~bloco();

};
#endif