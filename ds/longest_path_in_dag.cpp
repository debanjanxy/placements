/*
We initialize distances to all vertices as minus infinity and 
distance to source is 0, then we find a topological sorting of the
graph. Topological sorting of a graph represeents a linear ordering
of the graph. Once we have topological order, we one by one process
all vertices in topological order. For every vertex being processed, 
we update distances of it's adjacent using distance of current 
vertex.

 1) Initialize dist[] = {NINF,..} and dist[s] = 0 where s is the 
 source.
 2) Create a topological order of all vertices.
 3) For every vertex u in topological order:
 		For every adjacent vertex v of u:
 			if(dist[v]<dist[u]+weight(u,v)) then:
 				dist[v] = dist[u]+weight(u,v)

 */

#include <iostream>
#include <list>
#include <stack>
#include <limits.h>
#define NINF INT_MIN
using namespace std;

class AdjListNode
{
	int v;
	int weight;
  public:
  	AdjListNode(int _v, int _w)
  	{
  		v = _v;
  		weight = _w;
  	}
  	int getV()
  	{
  		return v;
  	}
  	int getWeight()
  	{
  		return weight;
  	}

};

class Graph
{
	int V;
	list <AdjListNode> *adj;
	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
	Graph(int V);
	void addEdge(int u, int v, int weight);
	void longestPath(int s);
};

Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<AdjListNode>[V];
}

void Graph :: addEdge(int u, int v, int weight)
{
	AdjListNode node(v,weight);
	adj[u].push_back(node);
}

void Graph :: topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
	//Mark the current node as visited
	visited[v] = true;
	list<AdjListNode> :: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		AdjListNode node = *i;
		if(!visited[node.getV()])
		{
			topologicalSortUtil(node.getV(), visited, Stack);
		}
	}
	//Push the current vertex to stack which stores the topological sort
	Stack.push(v);
}

void Graph :: longestPath(int s)
{
	stack<int> Stack;
	int dist[V];
	//Mark all the vertices as not visited
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i] = false;
	}
	//Sort starting from all vertices one by one
	for(int i=0;i<V;i++)
	{
		if(visited[i] == false)
		{
			topologicalSortUtil(i,visited,Stack);
		}
	}
	for(int i=0;i<V;i++)
	{
		dist[i] = NINF;
	}
	dist[s] = 0;
	
	while(Stack.empty() == false)
	{
		//Get the next vertex in topological order
		int u = Stack.top();
		Stack.pop();

		list<AdjListNode> :: iterator i;
		if(dist[u] == NINF)
		{
			for(i=adj[u].begin();i!=adj[u].end();++i)
			{
				if(dist[i->getV()] < dist[u]+i->getWeight())
				{
					dist[i->getV()] = dist[u]+i->getWeight();
				}
			}
		}

	}	
}
}




























