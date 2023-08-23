#include "heap.hpp"
#include "Palavra.hpp"
#include "hash.hpp"
#include "bloco.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<locale>

using namespace std;
#define k 3;
const int numberOfFiles = 2;

char toLowerAccent(char c) {
    // Funciona com
    // "áâàãéèêíïóôõúüç" ÁÀÂÃÉÈÊÍÏÓÔÕÚÜÇ"

    int aux = c;

    if (aux == -61)
        return -61;
    else if (aux >= -128 && aux <= -118)
        return (aux + 32);
    else if (aux == -115)
        return (aux + 32);
    else if (aux == -113)
        return (aux + 32);
    else if (aux == -109)
        return (aux + 32);
    else if (aux == -108)
        return (aux + 32);
    else if (aux == -107)
        return (aux + 32);
    else if (aux == -102)
        return (aux + 32);
    else if (aux == -100)
        return (aux + 32);

    return tolower(c);
}

int main() {
    //std::setlocale(LC_ALL, "pt_BR.utf8");
    std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());
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
      */
    tabelaHash a;
    if (true) {
        Palavra palavra1("A"), palavra2("N"), palavra3("["), palavra4("B");

        //string str="klop";
    // cout << "sizeof(p):" << str.size();

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
    }



    cout << "\n\n\n";
    cout << "\n\n\n";
    a.imprimeHash();
    cout << "\n\n\n";
    /*
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
/*
    tabelaHash hp;
    for (int i = 0;i < 60000;i++) {
        string a, st = "palavra";
        stringstream ss;
        ss << i;
        ss >> a;
        st.append(a);
        Palavra p(st);
        hp.inserir(p);

    }
    for (int i = 0;i < 2000;i++) {
        Palavra p2("eduardo");
        hp.inserir(p2);
        Palavra p3("59981");
        hp.inserir(p3);
        Palavra p4("59990");
        hp.inserir(p4);
        Palavra p5("palavra456");
        hp.inserir(p5);
    }
    hp.imprimeHash();
*/

/* tabelaHash acento;
 Palavra testeA("é");
 cout << "testeA.getNome():" << testeA.getNome() << "\n";
 bloco blo(testeA);
 blo.getPalavra().getNome();
 cout << "blo.getPalavra().getNome():" << blo.getPalavra().getNome();//<<  "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
 acento.inserir(testeA);*/
 /////////////////////////////////////////NÃO APAGA COMENTARIO//////////////////////////
    tabelaHash hp;
    for (int i = 2; i < 3; i++) {
        tabelaHash hpt;
        string fileName, a, str;
        stringstream ss;
        ss << i;
        ss >> a;
        fileName = "dataset/input";
        fileName.append(a).append(".txt");
        cout << "\n\nfileame:" << fileName << "\n\n";
        ifstream file(fileName);
        if (file.is_open()) {
            string strPalavra;
            for (int i = 0; i < 27000; i++) {
                getline(file, str);
                //   cout << str << "\n";
                //   cout << "(int)str.size(): " << (int)str.size();
                if (str[(int)str.size() - 1] == '\n') {
                    // cout << "\\n \n\n\n";
                }
                //cout << "\n\n";
                if (str.size() > 0) {
                    // cout << "\n\n\n entrei \n\n\n";
                    for (int j = 0;j < (int)str.size();j++) {
                        //    cout << "\n\n\n entrei no for " << j << " \n\n\n";
                        if (str[j] != '/' && str[j] != '.' && str[j] != ',' && str[j] != '!' && str[j] != '?' && str[j] != ' ' && str[j] != '\n' && str[j] != ';' && str[j] != ':' && str[j] != '-' && str[j] != '"' && str[j] != '\t' && str[j] != '\\' && str[j] != '(' && str[j] != ')' && str[j] != '[' && str[j] != ']' && str[j] != '{' && str[j] != '}' && str[j] != '=' && str[j] != '+' && str[j] != '"') {
                            str[j] = toLowerAccent(str[j]);
                            strPalavra.push_back(str[j]);
                        } else if (str[j] == '-') {
                            if (str[j + 1] == '-' || (j != 0 && str[j - 1] == '-')) {
                                if (strPalavra != "") {
                                    // cout << "\nSTRPALAVRA:";
                                    Palavra p(strPalavra);
                                    hpt.inserir(p);

                                    //  cout << strPalavra << "\n";
                                    strPalavra = "";
                                }

                            } else {
                                str[j] = toLowerAccent(str[j]);
                                strPalavra.push_back(str[j]);
                            }
                        } else {
                            // cout << "\n\n\nEntrei no ELSE\n\n\n";
                            if (strPalavra != "") {
                                // cout << "\nSTRPALAVRA:";
                                Palavra p(strPalavra);
                                hpt.inserir(p);

                                //cout << strPalavra << "\n";
                                strPalavra = "";
                            }
                        }
                    }
                    if (strPalavra != "") {
                        //  cout << "\nSTRPALAVRA:";
                        Palavra p(strPalavra);
                        hpt.inserir(p);
                        // cout << strPalavra << "\n";
                        strPalavra = "";
                    }

                }

            }
            file.close();
        } else {
            cout << "\n\nFile não encontrado\n\n\n";
        }
        hpt.imprimeHash();


        break;
    }

    /*
        for(int i=0;i<60000;i++){
            string a,st="palavra";
            stringstream ss;
            ss << i;
            ss >> a;
            st.append(a);
            Palavra p(st);
            hp.inserir(p);

        }
        for(int i=0;i<2000;i++){
            Palavra p2("eduardo");
            hp.inserir(p2);
            Palavra p3("59981");
            hp.inserir(p3);
            Palavra p4("59990");
            hp.inserir(p4);
            Palavra p5("palavra456");
            hp.inserir(p5);
        }
        hp.imprimeHash();*/

        //Palavra vp3[y] = vp2;
    //////////NÃO APAGA COMENTARIO//////////////////////////
}