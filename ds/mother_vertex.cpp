/*
A mother vertex in a graph G is a vertex v such that all other vertices in G can 
be reached by a path from v. There can be more than one mother vertices in a 
graph.

Case 1: Undirected Connected Graph - All vertices are mother vertex.
Case 2: Disconnected Graph - None of the vertices are mother vertices.
Case 3: Directed Connected Graph - Here one or more can be mother vertex.

Naive Approach : Perform dfs/bfs on each vertices and find whether we can 
reach all the vertices from that vertex. This approach will take O(V(V+E)) 
time.

Better Approach : If there exists mother vertex, then one of the mother 
vertices is the last finished vertex in DFS or a mother vertex has the 
maximum finish time in dfs traversal. A vertex is said to be finished in 
dfs if a recursive call for its dfs is over, i.e, all descendants of the vertex has been visited.

*/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
	void DFSUtil(int v, vector<bool> &visited);
public:
	Graph(int V);
	void addEdge(int v, int w);
	int findMother();
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph :: DFSUtil(int v, vector<bool> &visited)
{
	visited[v] = true;
	list<int> :: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(!visited[*i])
		{
			DFSUtil(*i,visited);
		}
	}
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w);
}

//Returns a mother vertex if exists else returns -1
int Graph :: findMother()
{
	vector<bool> visited(V,false);
	//To store last finished vertex
	int v=0;

	//Do a DFS traversal and find a last finished vertex
	for(int i=0; i<V; i++)
	{
		if(visited[i] == false)
		{
			DFSUtil(i,visited);
			v = i;
		}
	}

//Check if v is a mother vertex or not

	fill(visited.begin(), visited.end(), false);
	DFSUtil(v,visited);
	for(int i=0;i<V;i++)
	{
		if(visited[i] == false) return -1;
	}

	return v;
}


int main()
{
    // Create a graph given in the above diagram
    Graph g(5);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    //g.addEdge(5, 6);
    //g.addEdge(5, 2);
    //g.addEdge(6, 0);
 
    cout << "A mother vertex is " << g.findMother() << endl;
 
    return 0;
}









