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

void tiraCaracterEspecial(string *s) {

    std::locale::global(std::locale(""));
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;

    vector<string> portugues = { "⠝","⠴","⠙","⠼","⠑", "°","º","ª","§","⠳" };
    vector<string> substitui = { "","","","","","","","" ,"","" };

    string str = *s;
    wstring palavra = converter.from_bytes(str);
    for (int i = 0;i < (int)portugues.size();i++) {
        wstring aux = converter.from_bytes(portugues[i]);
        size_t pos = palavra.find(aux);
        while (pos != string::npos && palavra.find(aux, pos) != string::npos) {
            palavra.replace(pos, 1, converter.from_bytes(substitui[i]));
            pos = palavra.find(aux, pos);
        }
    }
    string new_str = converter.to_bytes(palavra);
    cout << "\nNew_str:" << new_str << "\n";
    //return;
    str.assign(new_str);
    std::cout << "STR: " << str;
    std::cout << "\nnew_STR: " << new_str;
    *s = str;
    std::cout << "\n*s: " << *s;
}


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
    std::setlocale(LC_ALL, "pt_BR.utf8");
    //std::locale::global(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale());

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
        std::cout << "\n\nfileame:" << fileName << "\n\n";
        ifstream file(fileName);
        if (file.is_open()) {
            string strPalavra;
            for (int i = 0; i < 27000; i++) {
                getline(file, str);
                //tiraCaracterEspecial(&str);
                //std::cout << "\nMain STR: " << str << "\n\n";
                //  std::cout << "\n\n";
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
            std::cout << "\n\nFile não encontrado\n\n\n";
        }
        hpt.imprimeHash();
        cout << "\n\nHEAP:\n\n";
        hpt.mostraHeap();
        std::cout << "\n\n\n";
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