#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], int parent);
public:
	Graph(int V);
	void addEdge(int u,int v);
	bool isCyclic();
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph :: isCyclicUtil(int v, bool visited[], int parent)
{
	visited[v] = true;
	list<int>::iterator i;
	for(auto i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			if(isCyclicUtil(*i,visited,parent)) return true;
		}
		else if(*i != parent) return true;
	}
	return false;	
}

bool Graph :: isCyclic()
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}
	for(int u=0;u<V;u++)
	{
		if(!visited[u])
		{
			if(isCyclicUtil(u,visited,-1)) return true;
		}
	}
	return false;
}


