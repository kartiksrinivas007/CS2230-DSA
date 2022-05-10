// Graphs_assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
#include"Graphs.h"
#include"linkedlist.h"
using namespace std;

int main()
{
    ifstream f,g1;
    unsigned long long int  nodes= 0;
    string filename;
    cout << "-----------ENTER FILE NAME -------------- \n";
    cin >> filename;
    f.open(filename);
    string temp = "0";
    string tempx;
    string temp_prev = "0";
    unsigned long long int start,end;
    //this is now going to count the number of nodes present in the csv file
    while (f.good())
    {
        //looks for changes in the first entry of every line and using that, we increment "nodes"
        getline(f, temp, ',');
        getline(f, tempx, '\n');
        
        if (temp != temp_prev)
        {
            nodes++;           
            temp_prev = temp;
        }
        
    }
    //cout << nodes << endl;
    f.close();
    //create graph!
    graph g(nodes);
    //open again, this time to add edges
   g1.open(filename);
   while (g1.good())
   {
       string temp1;
       string temp2;
       getline(g1, temp1, ',');
       getline(g1, temp2, '\n');
       if (temp1 != "" && temp2 != "") {
           int t1 = stoi(temp1);
           int t2 = stoi(temp2);
           g.add_edge(t1, t2);
           //cout << t1 << "," << t2 << endl;
       }
      
   }
   g1.close();
   //g.print();

   cout << " \n-------------ENTER 2 NODES FOR FINDING DISTANCES AND PATH---------------- \n";
   cin >> start >> end;
   g.bfs(start); //perform a  bfs
   std::cout << "path = ";
   g.print_path(start, end);
   std::cout << std::endl;
   std::cout << "distance = " << g.distance[end];
   
    return 0;
}


