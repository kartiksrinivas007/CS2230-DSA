#include "data.h"
#include"linkedlist.h"
#include"Hash_Table.h"
#include<iostream>

hashtable::hashtable()
{
    size = 0;
    link = NULL;
}
hashtable::hashtable(unsigned long long int size_max)
{
    size = size_max;
    link = new LL[size];
}
long long int hashtable::hashfunction(datum &data)
{
    //this is a primitive  and easier hashfunction which uses sum of ASCII values 
    /*long long int sum = 0;
    for (auto x : data.username)
    {
        long long int k = (int)x;
        sum = sum + k;
    }
    sum = sum % size;
    return sum;*/

    // this uses a much better hashfunction using primes at every level to increase randomness
    int hash = 7;
    for (auto x : data.username)
    {
        int k = (int)x;
        hash = hash * 31 + k;
    }
    hash = hash % size;
    return hash;
}
void hashtable::insert(datum& d)
{
    long long int hk = hashfunction(d);
    node n;
    n.dat = d;
    link[hk].insert(n);
}
node* hashtable::search(std::string &key)
{
    node* x = new node();
    std::string temp_password = "";
    datum temp(key, temp_password);
    long long int hk = hashfunction(temp);
    x = link[hk].search(temp);
    return x;
    
}
void hashtable::print(void)
{
    for (unsigned long long int i = 0; i < size; i++)
    {
        if (link[i].size == 0)
        {
            continue;
        }
        else
        {
            std::cout << "---------------HASHVALUE--------------:" << i << " "<<std::endl;
            link[i].print();
        }
    }
}