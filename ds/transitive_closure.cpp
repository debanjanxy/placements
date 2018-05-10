/*

Reachable means that there is a path from vertex u to v.
The reachability matrix is called transitive closure of a graph.
This can be done using Floyd Warshall Algorithm. But the problem
can also be solved in O(V^2).

1) Create a matrix tc[V][V] that would finally have transitive closure of given 
graph. Initialize all entries to tc[][] as 0.

2) Call DFS for every node of graph to mark reachable vertices in tc[][]. In recursive 
calls to dfs, we dont call dfs for an adjacent vertex if it is already marked as reachable in tc[][].

*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	bool **tc;
	void DFSUtil(int u, int v);
public:
	Graph(int V);
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	void transitiveClosure();
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	tc = new bool* [V];
	for(int i=0;i<V;i++)
	{
		tc[i] = new bool[V];
		memset(tc[i], false, V*sizeof(bool));
	}
}

void Graph :: DFSUtil(int s, int v)
{
	tc[s][v] = true;
	list<int>:: iterator i;
	for(i=adj[v].begin();i!=adj.end();++i)
	{
		if(tc[s][*i]==false)
		{
			DFSUtil(s,*i);
		}
	}
}

void Graph :: transitiveClosure()
{
	for(int i=0;i<V;i++)
	{
		DFSUtil(i,i); //every vertex is reachable from self
	}
	for(int i=0; i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}
}

















