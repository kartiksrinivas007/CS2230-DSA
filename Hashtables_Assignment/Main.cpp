#include<iostream>
#include<fstream>
#include<string>
#include"Hash_Table.h"
#include"data.h"
#include"linkedlist.h"
using namespace std;


int main()
{/*
	cout << "lalalal" << endl;
	string s1 = "kartikrox";
	string s2 = "kartikdabest";
	string s3 = "1235lala";
	string s4 = "1235lel";
	datum d1(s1, s3);
	datum d2(s2, s4);*/

	/*LL k;
	node m;
	node m2;
	m.dat = d1;
	m2.dat = d2;*/
	//k.insert(m);
	//k.insert(m2);
	//cout << "size is = "<< k.size << "password = "<<(k.head->dat).password << endl;
	//k.print();

	/*node* pos;
	hashtable h(65);
	h.insert(d1);
    h.insert(d2);
	h.print();
	pos = h.search(s2);
	cout << "password = " << (pos->dat).password;*/


	ifstream f;
	f.open("userInfo.csv");
	hashtable h(1000);
	int iterations = 0;
	string username;
	string password,real_password;
	while (f.good())
	{
		iterations++;
		string s1;
		string s2;
		getline(f, s1, ',');
		getline(f, s2, '\n');
		//cout << s1 << s2 << endl;
		datum d1(s1, s2);
		h.insert(d1);

	}

	//h.print();
	int t; 
	cout << "-------------ENTER NUMBER OF TEST CASES --------------"<<endl;
	cin >> t;
	while (t--)
	{
		cout << "-------------ENTER A USERNAME-------------" << endl;
		cin >> username;
		node* pos = h.search(username);
		if (pos == NULL)
		{
			cout << "-------------INVALID USERNAME----------" << endl;
		}
		else {
			real_password = pos->dat.password;
			cout << "----------------ENTER PASSWORD-----------" << endl;
			cin >> password;
			if (password == real_password)
			{
				cout << "-------------LOGIN SUCCESSFUL------------"<<endl;

			}
			else {
				cout << "-------------INCORRECT PASSWORD-----------"<<endl;
			}

		}
	}

	



	return 0;
}
