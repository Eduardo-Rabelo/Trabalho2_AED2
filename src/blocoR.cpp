#include "blocoR.hpp"
#include <iostream>
using namespace std;

blocoR::blocoR() {
	this->dir = NULL;
	this->esq = NULL;
	this->pai = NULL;
	this->pesoDir = 0;
	this->pesoEsq = 0;
	this->pesoTotal = 0;
	//this->nivel = 0;
}

blocoR::blocoR(Palavra r) {
	this->r = r;
	this->dir = NULL;
	this->esq = NULL;
	this->pai = NULL;
	this->pesoDir = 0;
	this->pesoEsq = 0;
	this->pesoTotal = 0;
	//this->nivel = 0;
}

Palavra blocoR::getRecord() {
	return this->r;
}

blocoR *blocoR::getDir() {
	return this->dir;
}
void blocoR::setDir(blocoR *b) {
	this->dir = b;
}

blocoR *blocoR::getPai() {
	if (this->pai == NULL) {
		return NULL;
	}
	return this->pai;
}
void blocoR::setPai(blocoR *b) {
	this->pai = b;
}

blocoR *blocoR::getEsq() {
	return this->esq;
}
void blocoR::setEsq(blocoR *b) {
	this->esq = b;
}

bool blocoR::verDir() {
	if (this->dir == NULL) {
		return false;
	} else {
		return true;
	}
}

bool blocoR::verEsq() {
	if (this->esq == NULL) {
		return false;
	} else {
		return true;
	}
}

void blocoR::verFilhos() {
	if (verDir() == false) {
		cout << "Dir: NULL\n";
	} else {
		cout << "Dir: não nulo\n";
	}
	if (verEsq() == false) {
		cout << "Esq: NULL";
	} else {
		cout << "Esq: não nulo";
	}
}

void blocoR::setRecord(Palavra r) {
	this->r = r;
}
/*
int blocoR::getNivel() {
	return this->nivel;
}
void blocoR::setNivel(int n) {
	this->nivel = n;
}*/

int blocoR::getPesoDir() {
	return this->pesoDir;
}
void blocoR::setPesoDir(int p) {
	this->pesoDir = p;
	calculaPesoTotal();
}
void blocoR::addPesoDir() {
	this->pesoDir = this->pesoDir + 1;
	calculaPesoTotal();
}

int blocoR::getPesoEsq() {
	return this->pesoEsq;
}
void blocoR::setPesoEsq(int p) {
	this->pesoEsq = p;
	calculaPesoTotal();
}
void blocoR::addPesoEsq() {
	this->pesoEsq = this->pesoEsq + 1;
	calculaPesoTotal();
}

int blocoR::getPesoTotal() {
	calculaPesoTotal();
	return this->pesoTotal;
}

void blocoR::imprime() {

	this->r.imprime();
	//cout << "\nNível: " << this->nivel;
	cout << "\nPesoEsq: " << this->pesoEsq;
	cout << "\nPesoDir: " << this->pesoDir;
	cout << "\nPesoTotal: " << this->pesoTotal;


}

void blocoR::calculaPesoTotal() {
	this->pesoTotal = this->pesoDir - this->pesoEsq;
}