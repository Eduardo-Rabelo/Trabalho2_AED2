#include "hash.hpp"
using namespace std;

tabelaHash::tabelaHash() {
    std::locale::global(std::locale(""));

}

void tabelaHash::inserir(Palavra p) {

    std::locale::global(std::locale(""));
    string str = p.getNome();
    wstring palavra = this->converter.from_bytes(str);
    for (int i = 0;i < (int)this->portugues.size();i++) {
        wstring aux = this->converter.from_bytes(portugues[i]);
        size_t pos = palavra.find(aux);
        while (pos != string::npos && palavra.find(aux, pos) != string::npos) {
            palavra.replace(pos, 1, this->converter.from_bytes(substitui[i]));
            pos = palavra.find(aux, pos);
        }
    }
    string new_str = this->converter.to_bytes(palavra);
    str.assign(new_str);
    int position = calculoHash(str);
    bloco *b = new bloco(p);
    bloco *aux;
    aux = &hashBlocos[position];

    if (hashBlocos[position].getPalavra().getNome() == "") {
        hashBlocos[position] = *b;
        hashBlocos[position].add();
        this->cont++;
    } else if (hashBlocos[position].getPalavra().getNome() == p.getNome()) {
        hashBlocos[position].add();
    } else {
        position = calculo2Hash(str);
        if (hashBlocos[position].getPalavra().getNome() == "") {
            hashBlocos[position] = *b;
            hashBlocos[position].add();
            this->cont++;
        } else if (hashBlocos[position].getPalavra().getNome() == p.getNome()) {
            hashBlocos[position].add();
        }


        else if (hashBlocos[position].getProx() == NULL) {
            hashBlocos[position].setProx(b);
            hashBlocos[position].getProx()->add();
            this->cont++;

        } else {
            while (aux->getProx() != NULL) {
                aux = aux->getProx();
                if (aux->getPalavra().getNome() == p.getNome()) {
                    aux->add();
                    return;
                }
            }
            b->add();
            aux->setProx(b);
            this->cont++;
        }
    }

}

int tabelaHash::calculoHash(string p) {
    int soma = 0;
    for (int i = 0;i < (int)p.size();i++) {
        soma += (int)p[i];
    }

    return(soma % tam);
}
int tabelaHash::calculo2Hash(string p) {
    int soma = 0;
    for (int i = 0;i < (int)p.size();i++) {
        soma += i * (int)p[i];
    }

    return(soma % tam);
}

void tabelaHash::imprimeHash() {
    bloco *aux;
    int cont = 0;
    for (int i = 0;i < tam;i++) {
        cont++;
        aux = &hashBlocos[i];
        hashBlocos[i].getPalavra().imprime();
        if (hashBlocos[i].getProx() != NULL) {
            while (aux->getProx() != NULL) {

                aux = aux->getProx();
                aux->getPalavra().imprime();
                cont++;
            }

        }

    }
    cout << "\n\ncont: " << cont;
}

Palavra *tabelaHash::vetor(int tamanho) {

    Palavra *vetorPalavras = new Palavra[tamanho];
    int cont = 0;
    bloco *aux;
    for (int i = 0; i < this->t; i++) {
        if (hashBlocos[i].getPalavra().getNome() != "") {
            aux = &hashBlocos[i];
            vetorPalavras[cont] = hashBlocos[i].getPalavra();
            while (aux->getProx() != NULL) {
                cont++;
                if (cont >= tamanho) {
                    delete aux;
                    return vetorPalavras;
                }
                vetorPalavras[cont] = aux->getProx()->getPalavra();
                aux = aux->getProx();
            }
            cont++;
            if (cont >= tamanho) {
                return vetorPalavras;
            }
        }
    }
    return vetorPalavras;
}

void tabelaHash::mostraHeap() {
    Palavra p;
    heap hi(tamHeap, vetor(tamHeap));
    bloco *aux;
    int cont = 0;
    for (int i = tamHeap;i < tam;i++) {
        cont++;
        aux = &hashBlocos[i];
        hi.addPalavra(hashBlocos[i].getPalavra());
        if (hashBlocos[i].getProx() != NULL) {
            while (aux->getProx() != NULL) {

                aux = aux->getProx();
                hi.addPalavra(aux->getPalavra());
                cont++;
            }

        }

    }
    hi.imprime();

}

void tabelaHash::imprimeCont() {
    cout << "Palavras na hash: " << this->cont;
}