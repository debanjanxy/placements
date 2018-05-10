#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
public:
	int V;
	list<int> *adj;
	Graph(int V);
	void addEdge(int u,int v);
	void printGraph();
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph :: addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph :: printGraph()
{
	for(int i=0; i<V; i++)
	{
		list<int> :: iterator k = adj[i].begin();
		cout << i << "->";
		while(k!=adj[i].end())
		{
			cout << *k << "->";
			++k;
		}
		cout << "NULL" << endl;
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.printGraph();
	return 0;
}
