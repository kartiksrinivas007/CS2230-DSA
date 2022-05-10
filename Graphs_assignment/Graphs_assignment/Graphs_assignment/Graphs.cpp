#include"Graphs.h"
#include"linkedlist.h"
#include<iostream>

graph::graph()
{
	size = 0;
    adj = NULL;
	predecessor = NULL;
	distance = NULL;
}
graph::graph(ull n)
{
	size = n;
	adj = new LL[n];
	predecessor = new ull[n];
    distance = new ull[n];
}
void graph::add_edge(ull i, ull j)
{
	node *a = new node();
	a->data = j;
	adj[i].insert(*a);
	//i dont need to do it the other way around because its already given as input
}
void graph::print()
{
	for (int i =0 ; i<size ; i++)
	{
		std::cout << i << ":";
		adj[i].print();
		
	}
}
void graph::bfs(ull start)
{
	if (start > size) {
		fprintf(stderr, "START POINT NOT PRESENT IN GRAPH!");
		exit(1);
		
	}
	std::queue<ull> q;
	for (ull i = 0; i < size; i++) {
		distance[i] = INT_MAX;
		predecessor[i] = INT_MAX;
	}
	distance[start] = 0;
	predecessor[start] = INT_MAX;
	q.push(start);
	node* k;
	while (!q.empty())
	{
		ull pres = q.front();
		q.pop();
		ull count = adj[pres].size;
		k = adj[pres].head;

			while (k != NULL) 
			{
				if (distance[k->data] < INT_MAX) 
				{
					k = k->next;
					continue;
				}
				else
				{
					q.push(k->data);
					distance[k->data] = distance[pres] + 1;
					predecessor[k->data] = pres;
					k = k->next;
				}
			}

	}


}
void graph::print_path(ull start,ull end)
{
	if (end > size)
	{
		fprintf(stderr, "END POINT NOT IN GRAPH");
		exit(1);
	}
	if (start == end) {
		std::cout << start<< " ";
	}
	else if (predecessor[end] == INT_MAX) {
		std::cout << "NO PATH EXISTS!" << std::endl;
	}
	else {
		print_path(start, predecessor[end]);
			std::cout << end << " ";
	}
}
