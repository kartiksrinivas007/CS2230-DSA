#pragma once
#include"data.h"
#include"linkedlist.h"

class hashtable {
public:
	unsigned long long int size;
	LL* link;
	hashtable(unsigned long long int);
	hashtable();
	long long int hashfunction(datum &data);
	void insert(datum &data);
	node* search(std::string &key);
	void print();

};

