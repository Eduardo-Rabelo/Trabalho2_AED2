#include "Palavra.hpp"
#include <iostream>
using namespace std;

Palavra::Palavra(){
    this->palavra="";
    this->frequencia=0;
}
Palavra::Palavra(string palavra){
    this->palavra = palavra;
    this->frequencia=0;
}
void Palavra::add(){
    this->frequencia+=1;
}
void Palavra::imprime(){
    cout << "\n\nPalavra: " << this->palavra;
    cout << "\nFrequencia: " << this->frequencia;
}
int Palavra::getFrequencia(){
    return this->frequencia;
}