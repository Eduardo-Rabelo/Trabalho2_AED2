#include "heap.hpp"
#include "Palavra.hpp"
#include "record.hpp"
#include "Tree.hpp"
#include "avl.hpp"
#include "hash.hpp"
#include "bloco.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<locale>
#include <codecvt>

using namespace std;
const int numberOfFiles = 1;

/*
void tiraCaracterEspecial(string *s) {

    std::locale::global(std::locale(""));
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;

    vector<string> portugues = { "⠝","⠴","⠙","⠼","⠑", "°","º","ª","§","⠳" };
    vector<string> substitui = { "","","","","","","","","","" };

    string str = *s;
    wstring palavra = converter.from_bytes(str);
    //wcout << "Palavra: " << palavra;
    for (int i = 0;i < (int)portugues.size();i++) {
        wstring aux = converter.from_bytes(portugues[i]);
        size_t pos = palavra.find(aux);
        while (pos != string::npos && palavra.find(aux, pos) != string::npos) {
            //  cout << "\nENCONTREI\n";
            palavra.replace(pos, 1, converter.from_bytes(substitui[i]));
            pos = palavra.find(aux, pos);
        }
    }
    wcout << "\nPalavra: " << palavra;
    string new_str = converter.to_bytes(palavra);
    cout << "\nNew_str:" << new_str << "\n";
    //return;
    str.assign(new_str);
    //std::cout << "STR: " << str;
    //std::cout << "\nnew_STR: " << new_str;
    *s = str;
    //std::cout << "\n*s: " << *s;
}
*/

char toLowerAccent(char c) {

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
    std::setlocale(LC_ALL, "pt_BR.utf8");
    std::wcout.imbue(std::locale());


    Palavra r("abcd"), r2("car"), r3("carlos"), r4("d"), r5("e");
    avl t;
    for (int i = 0;i < 3;i++) {
        r2.add();
    }
    for (int i = 0;i < 30;i++) {
        r3.add();
    }
    for (int i = 0;i < 32;i++) {
        r4.add();
    }
    for (int i = 0;i < 11;i++) {
        r5.add();
    }

    r.imprime();
    blocoR br(r);
    blocoR br2(r2), br3(r3), br4(r4), br5(r5);
    cout << "Antes de inserir:\n\n";
    t.meuInserir(br3);
    cout << "\n\nInseriu\n\n";

    t.meuInserir(br2);
    cout << "\n\nInseriu2\n\n";
    t.meuInserir(br5);
    cout << "\n\nInseriu3\n\n";
    t.meuInserir(br4);
    cout << "\n\nInseriu4\n\n";

    cout << "\n\nCentral: \n\n";
    t.central();
    cout << "\n\nPreOrdem: \n\n";
    t.preOrdem();
    cout << "\n\nPosOrdem: \n\n";
    t.posOrdem();
    cout << "\n\n\ntchau\n\n\n";


    tabelaHash hp;
    for (int i = 1; i <= numberOfFiles; i++) {
        tabelaHash hpt;
        Tree tre;
        avl avlT;
        string fileName, a, str;
        stringstream ss;
        ss << i;
        ss >> a;
        fileName = "dataset/input";
        if (a != "1") {
            fileName.append(a);
        }


        fileName.append(".txt");

        std::cout << "\n\nfileame:" << fileName << "\n\n";
        ifstream file(fileName);
        if (file.is_open()) {
            string strPalavra;
            while (getline(file, str)) {
                if (str.size() > 0) {
                    for (int j = 0;j < (int)str.size();j++) {
                        if (str[j] != '/' && str[j] != '.' && str[j] != ',' && str[j] != '!' && str[j] != '?' && str[j] != ' ' && str[j] != '\n' && str[j] != ';' && str[j] != ':' && str[j] != '-' && str[j] != '"' && str[j] != '\t' && str[j] != '\\' && str[j] != '(' && str[j] != ')' && str[j] != '[' && str[j] != ']' && str[j] != '{' && str[j] != '}' && str[j] != '=' && str[j] != '+' && str[j] != '"') {
                            str[j] = toLowerAccent(str[j]);
                            strPalavra.push_back(str[j]);
                        } else if (str[j] == '-') {
                            if (str[j + 1] == '-' || (j != 0 && str[j - 1] == '-')) {
                                if (strPalavra != "") {
                                    Palavra p(strPalavra);
                                    hpt.inserir(p);
                                    strPalavra = "";
                                }

                            } else {
                                str[j] = toLowerAccent(str[j]);
                                strPalavra.push_back(str[j]);
                            }
                        } else {
                            if (strPalavra != "") {
                                Palavra p(strPalavra);
                                hpt.inserir(p);
                                strPalavra = "";
                            }
                        }
                    }
                    if (strPalavra != "") {
                        Palavra p(strPalavra);
                        hpt.inserir(p);
                        strPalavra = "";
                    }

                }

            }
            file.close();
        } else {
            std::cout << "\n\nFile não encontrado\n\n\n";
        }
        hpt.imprimeCont();
        std::cout << "\n\nHEAP:\n\n";
        hpt.mostraHeap();
        vector <Palavra> palavras;
        palavras = hpt.getPalavras();

        std::cout << "\n\n\n";
        for (int i = 0;i < (int)palavras.size();i++) {
            tre.meuInserir(palavras[i]);
            avlT.meuInserir(palavras[i]);
        }
        cout << "\n\n\nCENTRAL:\n";
        tre.central();
        cout << "\n\n\nCENTRAL AVL:\n";
        avlT.central();
        cout << "\n\nPosORDEM:\n";
        tre.posOrdem();
        cout << "\n\nAVL PosORDEM:\n";
        avlT.posOrdem();
        cout << "\n\nPreORDEM:\n";
        tre.preOrdem();
        cout << "\n\nAVL PreORDEM:\n";
        avlT.preOrdem();
    }
    /**/
    return 0;
}