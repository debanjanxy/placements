/*
A negative cycle is one in which the overall sum of the cycle
comes negative.
Below algorithm finds if there is a negative weight cycle reachable from given
source:
1. Initialize distances from source to all vertices as infinite and distance to
 source itself is 0. Create an array dist[] of size |V| with all values as
 infinite except dist[src] src is the source vertex.

2. This step calculates shortest distances. Do following |V|-1 times where |V|
is the number of vertices in given graph.
    a) Do following for each edge u-v
        If dist[v] > dist[u]+weight of edge uv, then update dist[v]
            dist[v] = dist[u]+weight of edge uv

3. This step reports if there is a negative weight cycle in graph. Do following
for each edge u-v.
    If dist[v] > dist[u]+weight of edge uv, then "Graph contains negative weight
    cycle".

The idea of step 3 is, step 2 gurantees shortest distances if graph doesn't
contain negative weight cycle. If we iterate all edges one more time and get a
shorter path for any vertex, then there is a negative weight cycle.
*/

#include <bits/stdc++.h>
#include <limits.h>
#define INFINITE INT_MAX
using namespace std;

class Graph
{
    int V, E; //No. of edges and vertices are fixed.
    list<int> *adj;
public:
    Graph(int V, int E);
    void addEdge(int u, int v);
    bool isNegativeCycle(int src);
};

Graph :: Graph(int V, int E)
{
    this->V = V;
    this->E = E;
    adj = new list<int>[V];
}

void Graph :: addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph :: isNegativeCycle(int src)
{
    vector<int> dist(V,INFINITE);
    dist[src] = 0;
    for(int u=0;i<V;i++)
    {
        for(int v=0;j<V;j++)
        {
            if(dist[v]>dist[u]+)
        }
    }

}
