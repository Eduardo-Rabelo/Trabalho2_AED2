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
        hashBlocos[position].add();
    }
    else if(hashBlocos[position].getPalavra().getNome()== p.getNome()){
        hashBlocos[position].add();
    }
    else{
        position = calculo2Hash(p.getNome());
        if(hashBlocos[position].getPalavra().getNome()== ""){
            hashBlocos[position]=*b;
            hashBlocos[position].add();
        }
        else if(hashBlocos[position].getPalavra().getNome()== p.getNome()){
            hashBlocos[position].add();
        }


        else if(hashBlocos[position].getProx()==NULL){
            //b->add();
           // cout << "\n\nb->getPalavra().getNome(): " << b->getPalavra().getNome() << "\n\n";
            hashBlocos[position].setProx(b);
            hashBlocos[position].getProx()->add();
            //cout << "\n\nhashBlocos[position].getProx()->getPalavra().getNome(): " << hashBlocos[position].getProx()->getPalavra().getNome() << "\n\n";
        }
        else{
            while(aux->getProx()!= NULL){
                aux = aux->getProx();
                if(aux->getPalavra().getNome() == p.getNome()){
                    aux->add();
                    return;
                }
            }
            b->add();
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
    int cont= 0;
    for(int i=0;i<tam;i++){
        cont++;
        aux = &hashBlocos[i];
        hashBlocos[i].getPalavra().imprime();
        if (hashBlocos[i].getProx()!= NULL)
        {
            while(aux->getProx()!= NULL){
                
                aux = aux->getProx();
                aux->getPalavra().imprime();
                cont++;
            }
            
        }
        
    }
    cout << "\n\ncont: " << cont;
}