#include <iostream>
#include <list>
using namespace std;

class Graph
{
	int V;
	bool **tc;
	list <int> *adj;
	void DFSUtil(int u, int v);
public:
	Graph(int v);
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	void transitiveClosure();
};



