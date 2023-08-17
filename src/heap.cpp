#include "heap.hpp"
#include <iostream>
using namespace std;

heap::heap(int tam, int v[]){
    
    this->tam = tam;
    for(int i=0; i < this->tam; i++){
        insere(v[i]);
    }
   opera();
}
void heap::insere(int p){
    this->palavras.push_back(p);
}

void heap::opera(){
    int aux;
    for(int i=(this->tam/2 - 1); i>0 ; i--){
       if(this->palavras[i] > this->palavras[2*i]){
            aux=this->palavras[i];
            this->palavras[i]= this->palavras[2*i];
            this->palavras[2*i] = aux;
       }
       if(this->palavras[i] > this->palavras[(2*i)+1]){
            aux=this->palavras[i];
            this->palavras[i]= this->palavras[(2*i)+1];
            this->palavras[(2*i)+1] = aux;
       }
    }
    if(this->palavras[0] > this->palavras[1]){
            aux=this->palavras[0];
            this->palavras[0]= this->palavras[1];
            this->palavras[1] = aux;
    }
    if(this->palavras[0] > this->palavras[2]){
        aux=this->palavras[0];
        this->palavras[0]= this->palavras[2];
        this->palavras[2] = aux;
    }
}

void heap::imprime(){
    for(int i=0;i<this->tam;i++){
        cout << this->palavras[i] << " ";
    }
}