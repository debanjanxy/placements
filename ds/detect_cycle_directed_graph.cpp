/*

Depth First Traversal or dfs can be used to detect a cycle in 
a directed graph. DFS for a connected graph produces a tree. 
There is a cycle in the graph only if there is back edge present in the 
graph. A back edge is an edge that is from a node to itself or 
one of it's ancestor in the tree produced by dfs.

For a disconnected graph, we get the dfs forrest as output. To 
detect cycle in individual trees by checking back edges.

To detect a back edge, we can keep track of vertices currently in 
recursion stack of function for DFS traversal. If we reach a 
vertex that is already in the recursion stack, then there is a 
cycle in the tree. The edge that connects current vertex to the 
vertex in the recursion stack is a back edge. 

*/

#include <bits/stdc++.h>
#include <iostream>
#include <limits.h>

using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs);
public:
	void addEdge(int u, int v);
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
}

bool Graph :: isCyclicUtil(int v, bool visited[], bool *recStack)
{
	if(!visited[v])
	{
		visited[v] = true;
		recStack[v] = true;

		list<int>::iterator i;
		for(i=adj[v].begin();i!=adj[v].end();++i)
		{
			if(!visited[*i] && isCyclicUtil(*i,visited,recStack)) return true;
			else if(recStack[*i]) return true;
		}
	}
	recStack[v] = false;
	return false;
}

bool Graph :: isCyclic()
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
		recStack[i] = false;
	}
	for(int i=0;i<V;i++){
		if(isCyclicUtil(i,visited,recStack)) return true;
	}
	return false;
}












































