#pragma once
#include<iostream>

typedef unsigned long long int ull;

class node {
public:
	node();
	ull data;
	ull distance;
	ull predecessor;
	node* next;
	node* previous;

};

class LL {
public:
	node* head;
	long long int size;
	LL();
	void insert(node& a);
	void del(node* n);
	node* search(ull n);
	void print();
};