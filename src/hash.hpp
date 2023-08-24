#ifndef HASH_HPP
#define HASH_HPP
#include <iostream>
#include "bloco.hpp"
#include "heap.hpp"
#include <vector>
#include <locale>
#include <codecvt>
#define tam 13
#define tamHeap 10
using namespace std;
class tabelaHash {
private:
    //int tam_heap = tamHeap;
    bloco hashBlocos[tam];
    int t = tam;
    //heap h(tamHeap,);
    int calculoHash(string p);
    int calculo2Hash(string p);
    vector<string> portugues = { "á","ã","â","à","ã","é","è","ê","í","ï", "ì","ó","ô","õ","ù","ú","û","ü","ç","ò","⠝","⠴","⠙","⠼","⠑", "°","º","ª","§","⠳" };
    vector <string> substitui = { "a","a","a","a","a","e","e","e","i","i","i","o","o","o","u","u","u", "u","c","o","","","","","","","","" ,"","" };
    wstring_convert<codecvt_utf8<wchar_t>, wchar_t> converter;

public:
    tabelaHash();
    void teste();
    void inserir(Palavra p);
    void imprimeHash();
    void mostrarHeap();
    Palavra *vetor(int tamanho);
    void mostraHeap();

};
#endif