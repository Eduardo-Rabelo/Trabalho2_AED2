#include "heap.hpp"
#include "Palavra.hpp"
#include "hash.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
#define k 3;
const int numberOfFiles = 2;

int main(){
    
  /*
   // int x[8] = {7,6,5,4,3,2,1,9};
   int contpessoas=0;
    Palavra p("Carlos"),p2("joao"),p3("y"),p4("aaaa");
    contpessoas=4;
    
    for(int i=0;i<10;i++){
        p.add();
        if(i>0){
            p2.add();
        }
        if(i>1){
            p3.add();
        }
        if(i>2){
            p4.add();
        }
    }
    int y=k;
    Palavra vp[y]={p,p2,p3,p4};
 
   for(int i=0;i<contpessoas;i++){
    vp[i].imprime();

   }
   cout << "\n\n";
   heap h(contpessoas,vp);
   h.imprime();
    cout << "\n\n\n";

    Palavra o("lsdsdasda");
    for(int i=0;i<30;i++){
        o.add();
    }
    h.addPalavra(o);

    cout <<"\n\n\n";
    h.imprime();
    cout <<"\n\n\n";
    tabelaHash a;
    a.teste();
    cout <<"\n\n\n";
    
    char x='a';
    int lk=(int)x;
    string st="ap";
    lk=(int)st[0];
    cout << "a:" << lk;
    cout << "\n\n\n";
    
    Palavra palavra1("A"),palavra2("N"),palavra3("["),palavra4("B");

    string str="klop";
    cout << "sizeof(p):" << str.size();
    a.inserir(o);
    a.inserir(o);
    a.inserir(o);
    //a.inserir(palavra1);
   // a.inserir(palavra2);
    a.inserir(palavra1);
    a.inserir(palavra2);
    a.inserir(palavra1);
    a.inserir(palavra2);
    a.inserir(palavra2);
    a.inserir(palavra2);
     a.inserir(palavra1);
     a.inserir(palavra3);
      a.inserir(palavra4);
    palavra2.imprime();
    cout << "\n\n\n";
    cout << "\n\n\n";
    a.imprimeHash();
    cout << "\n\n\n";
    
    Palavra *vp2 = a.vetor(y);
    cout << "\n\n\n\n\n\n\nVetor:\n\n";
    for(int i=0; i < y; i++ ){
        vp2[i].imprime();
    }
    heap he(y,vp2);
    delete[] vp2;
    cout << "\n\n\nHeap:\n\n";
    he.imprime();
    
    cout << "\n\n\n";
    p.imprime();
    cout << "\n\n\n";
    he.addPalavra(p);
    he.imprime();
    
    cout << "\n\n\n";
    he.addPalavra(p2);
    he.imprime();
    Palavra poi("poi");
    cout << "\n\n\n";
    if(he.addPalavra(poi)){
        cout << "\n\nAdicionou\n\n";
    }else{
        cout << "\n\nNão Adicionou\n\n";
    }
    he.imprime();
    string str23;
    int f;
    cout << "\n\n\nPalavra a ser inserida: ";
    cin >> str23;
    cout << str23;
    cout << "\nFrequencia:";
    cin >> f;
    Palavra dpa(str23);
    for(int i=0;i<f;i++){
        dpa.add();
    }
    if(he.addPalavra(dpa)){
        cout << "\n\nAdicionou\n\n";
    }else{
        cout << "\n\nNão Adicionou\n\n";
    }
    cout << "\n\n\n";
    he.imprime();
    cout << "\n\n\n";
*/

    for(int i = 1; i < (numberOfFiles+1); i++){
        string fileName,a,str;
        stringstream ss;
        ss << i;
        ss >> a;
        fileName="dataset/input";
        fileName.append(a).append("txt");
        cout << "\n\nfileame:" << fileName << "\n\n";
        ifstream file(fileName);
        for(int j=0; j < 10; j++){
    			getline(file,str);
    			cout << str << "\n";
    		}

        file.close();

    }
    

    //Palavra vp3[y] = vp2;

}