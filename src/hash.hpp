#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include "bloco.hpp"
#include <vector>
#include <locale>
#include <codecvt>
#define tam 130
using namespace std;
class tabelaHash {
private:
    bloco hashBlocos[tam];
    int t = tam;
    int calculoHash(string p);
    int calculo2Hash(string p);
    vector<string> portugues = { "á","ã","â","à","ã","é","è","ê","í","ï", "ì","ó","ô","õ","ù","ú","û","ü","ç","⠝","⠴","⠙","⠼","⠑", "°","º","ª","§","⠳","ò" };
    vector <string> substitui = { "a","a","a","a","a","e","e","e","i","i","i","o","o","o","u","u","u", "u","c" ,"","","","","","","","" ,"","", "o" };
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;
public:
    tabelaHash();
    void teste();
    void inserir(Palavra p);
    void imprimeHash();
    Palavra *vetor(int tamanho);

};
#endif