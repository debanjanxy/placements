#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list <int> *adj;
public:
	Graph(int V);
	void addEdge(int u,int v);
	bool DFSUtil(int, vector<bool> &, vector<int> &, int k);
	void printKCores(int k);
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

void Graph :: DFSUtil(int v, vector<bool>&visited, vector<int>&vDegree, int k)
{
	visited[v] = true;
	list<int> :: iterator i;
	for(i=adj[v].begin();i!=adj[v].end();++i)
	{
		if(vDegree[v]<k)
		{
			vDegree[*i]--;
		}
		if(!visited[*i])
		{
			if(DFSUtil(*i,visited,vDegree,k))
			{
				vDegree[v]--;
			}
		}
	}
	return (vDegree[v]<k);
}

void Graph :: printKCores(int k)
{
	//Mark all vertices as not visited and not processed
	vector<bool> visited(V, false);
	vector<bool> processed(V, false);

	int mindeg = INT_MAX;
	int startvertex;

	//Store degrees of all vertices
	vector<int> vDegree(V);
	for(int i=0;i<V;i++)
	{
		vDegree[i] = adj[i].size();
		if(vDegree[i]<mindeg)
		{
			mindeg = vDegree[i];
			startvertex = i;
		}
	}

	DFSUtil(startvertex,visited,vDegree,k);
	//DFS traversal to update degrees of all vertices

	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			DFSUtil(i,visited,vDegree,k);
		}
	}
	//Print k cores

	for(int v=0;v<V;v++)
	{
		//Only considering those vertices which have degree >=K after dfs
		if(vDegree[v]>=k)
		{
			cout << "\n" << v << "]";
			//Traverse adj. list of v and print only those adjacent which have vdegree >= k after dfs
			list<int>:: iterator i;
			for(i=adj[v].begin();i!=adj[v].end();++i)
			{
				if(vDegree[*i]>=k)
				{
					cout << " -> " << *i;
 				}
			}
		}
	}
}
















