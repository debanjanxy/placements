#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addEdge(int u,int v);
	void DFS(int s);
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

void Graph :: DFS(int s)
{
	//Mark all vertices as not visited
	vector<bool> visited(V,false); 

	//Create a stack for dfs
	stack<int> stack;

	//Push current source node
	stack.push(s);

	while(!stack.empty())
	{
		//Pop a vertex from stack and print it
		s = stack.top();
		stack.pop();

		if(!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}
		//Get all adjacent vertices of the popped vertex s
		//If an adjacent vertex has not been visited yet then push it to the stack

		//Automatic variable is a local variable which is allocated and deallocated 
		//automatically when program flow enters and leaves the variable's scope. The
		//scope is the lexical context, particularly the function or block in which
		//the variable is defined.
		for(auto i=adj[s].begin();i!=adj[s].end();++i)
		{
			if(!visited[*i])
			{
				stack.push(*i);
			}
		}

	}
}



















