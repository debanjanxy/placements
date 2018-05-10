#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int u, bool visited[]);
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);
	void addEdge(int u, int v);
	void DFS();
	void topologicalSort();
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

void Graph :: DFSUtil(int u, bool visited[])
{
	visited[u] = true;
	cout << u << " ";
	list<int>::iterator i;
	for(i=adj[u].begin();i!=adj[u].end();++i)
	{
		if(!visited[*i])
		{
			DFSUtil(*i,visited);
		}
	}
}

void Graph :: DFS()
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			DFSUtil(i,visited);
		}
	}
}

void Graph :: topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	visited[v] = true;
	list<int> :: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			topologicalSortUtil(*i, visited, Stack);
		}
	}
	Stack.push(v);
}

void Graph :: topologicalSort()
{
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}
	for(int i=0;i<V;i++)
	{
		if(!visited[i])
		{
			topologicalSortUtil(i,visited,Stack);
		}
	}
	while(!Stack.empty())
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
}

int main()
{
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(2,1);
	g.addEdge(3,1);
	g.addEdge(4,1);
	//g.addEdge(0,1);
	g.DFS();
	return 0;
}