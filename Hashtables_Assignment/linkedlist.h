#pragma once
#include"data.h"
#include<iostream>
class node {
public:
	node();
	datum dat;
	node* next;
	node* previous;

};

class LL {
public:
	node* head;
	long long int size;
	LL();
	void insert(node &a);
	void del(node* n);
	node* search(datum n);
	void print();
};