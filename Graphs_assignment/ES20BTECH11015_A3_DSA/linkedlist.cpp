#include"linkedlist.h"


node::node()
{
	data = 0;
	distance = 0;
	predecessor = 0;
	next = NULL;
	previous = NULL;
}
LL::LL()
{
	size = 0;
	head = NULL;
}
void LL::insert(node& a)
{
	size = size + 1;

	if (head != NULL)
	{
		node* a2 = new node();
		*(a2) = a;

		a2->next = head;
		head = a2;
		a2->previous = NULL;
	}
	else if (head == NULL)
	{
		head = new node();
		*(head) = a;
		head->next = NULL;
		head->previous = NULL;
	}

}
void LL::del(node* a)
{

	size = size - 1;

	if (a->previous != NULL)
	{
		a->previous->next = a->next;

	}
	else
	{
		head = a->next;
	}
	if (a->next != NULL)
	{
		a->next->previous = a->previous;
	}

	delete(a);
}
node* LL::search(ull n)
{
	node* x = new node();
	x = head;
	while (x != NULL && x->data != n)
	{
		x = x->next;
	}
	return x;
}
void LL::print(void)
{
	node* x = new node();
	x = head;
	while (x != NULL)
	{
		std::cout << x->data<<" ";
		x = x->next;
		
	}
	std::cout << std::endl;
}