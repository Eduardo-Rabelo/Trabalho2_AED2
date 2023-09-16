#include "record.hpp"
#include <iostream>

using namespace std;

record::record() {
	this->value = 0;
	this->key = "";
}
record::record(string key) {
	this->value = 0;
	this->key = key;
}
void record::setKey(string key) {
	this->key = key;
}
void record::setValue(int value) {
	this->value = value;
}
string record::getKey() {
	return this->key;
}
int record::getValue() {
	return this->value;
}
void record::imprime() {
	cout << "\nValue: " << this->value;
	cout << "\nKey: " << this->key;
	cout << "\n";
}