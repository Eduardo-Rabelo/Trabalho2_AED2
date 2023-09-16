#ifndef RECORD_HPP
#define RECORD_HPP

#include <iostream>
using namespace std;
class record {
private:
	int value;
	string key;
public:
	record();
	record(string key);
	string getKey();
	void setKey(string key);
	int getValue();
	void setValue(int value);
	void imprime();
};
#endif