#ifndef BLOCOR_HPP
#define BLOCOR_HPP
#include "record.hpp"
#include <iostream>
using namespace std;
class blocoR {
private:
    record r;
    blocoR *esq, *dir;
public:
    blocoR(record r);
    record getRecord();
    blocoR *getDir();
    void setDir(blocoR *b);
    blocoR *getEsq();
    void setEsq(blocoR *b);
    void setRecord(record r);
    bool verDir();
    bool verEsq();
    void verFilhos();
    //~bloco();

};
#endif