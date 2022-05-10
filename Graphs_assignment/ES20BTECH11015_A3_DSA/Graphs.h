#pragma once
#include<iostream>
#include"linkedlist.h"
#include <queue>

typedef unsigned long long int ull;

class graph {
public:
	ull size;
	LL* adj;
	ull* predecessor;
	ull* distance;
	graph(ull size_max);
	graph();
	void add_edge(ull i, ull j);
	void print();
	void bfs(ull start);
	void print_path(ull start,ull end);

};
