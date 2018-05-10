#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool DLS(int v, int target, int limit);
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool IDDFS(int v, int target, int max_depth);
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool Graph :: DLS(int v, int target, int limit)
{
	if(v==target) return true;
	if(limit<=0) return false;

	for(auto i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(DLS(*i,target,limit-1)) return true;
	}
	return false;
}

bool Graph :: IDDFS(int v, int target, int max_depth)
{
	for(int i=0; i<=max_depth; i++)
	{
		if(DLS(v,target,i)) return true;
	}
	return false;
}