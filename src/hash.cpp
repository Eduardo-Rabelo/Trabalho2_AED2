#include "hash.hpp"
#include <iostream>
using namespace std;

tabelaHash::tabelaHash(){

}
void tabelaHash::teste(){
    for(int i=0;i<tam;i++){
        if(this->hashBlocos[i].getPalavra().getNome()==""){
            cout << "Nome" << i << "\n";
        }
        cout << "Frequencia:" << this->hashBlocos[i].getPalavra().getFrequencia() << "\n\n\n";
    }
}
