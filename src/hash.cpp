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
void tabelaHash::inserir(Palavra p){
    int position = calculoHash(p.getNome());
    bloco *b = new bloco(p);
    bloco * aux;
    aux = &hashBlocos[position];

    if(hashBlocos[position].getPalavra().getNome()== ""){
        hashBlocos[position]=*b;
    }
    else if(hashBlocos[position].getPalavra().getNome()== p.getNome()){
        hashBlocos[position].add();
    }
    else{
        position = calculo2Hash(p.getNome());
        if(hashBlocos[position].getPalavra().getNome()== ""){
            hashBlocos[position]=*b;
        }
        else if(hashBlocos[position].getPalavra().getNome()== p.getNome()){
            hashBlocos[position].add();
        }
        else if(hashBlocos[position].getProx()==NULL){
            hashBlocos[position].setProx(b);
        }
        else{
            while(aux->getProx()!= NULL){
                aux = aux->getProx();
            }
            aux->setProx(b);
        }
    }

}

int tabelaHash::calculoHash(string p){
    int soma=0;
    for(int i=0;i<(int)p.size();i++){
        soma+=(int)p[i];
    }

    return(soma%tam);
}
int tabelaHash::calculo2Hash(string p){
    int soma=0;
    for(int i=0;i<(int)p.size();i++){
        soma+=i*(int)p[i];
    }

    return(soma%tam);
}

void tabelaHash::imprimeHash(){
    bloco * aux;
    
    for(int i=0;i<tam;i++){

        aux = &hashBlocos[i];
        hashBlocos[i].getPalavra().imprime();
        if (hashBlocos[i].getProx()!= NULL)
        {
            while(aux->getProx()!= NULL){
                aux->getPalavra().imprime();
                aux = aux->getProx();
            }
            
        }
        
    }
}