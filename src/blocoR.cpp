#include "blocoR.hpp"
#include <iostream>
using namespace std;

blocoR::blocoR(record r) {
	this->r = r;
	this->dir = NULL;
	this->esq = NULL;
}

record blocoR::getRecord() {
	return this->r;
}

blocoR *blocoR::getDir() {
	return this->dir;
}
void blocoR::setDir(blocoR *b) {
	this->dir = b;
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

void blocoR::setRecord(record r) {
	this->r = r;
}