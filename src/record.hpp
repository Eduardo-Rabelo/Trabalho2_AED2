#ifndef RECORD_HPP
#define RECORD_HPP

#include <iostream>
class record {
private:
	int key, value;
public:
	record();
	record(int key);
	int getKey();
	void setKey(int key);
	int getValue();
	void setValue(int value);
	void imprime();
};
#endif