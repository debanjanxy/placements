/*
A DAG has at least one vertex with indegree 0 and one vertex with out degree 0.

Kahn's Algorithm:

1. Compute in-degree(number of incoming edges) for each of the vertex present
in the DAG and initialize the count of visited nodes as 0.

2. Pick all the vertices with in-degree as 0 and add them into a queue.

3. Remove a vertex from the queue and then,
    a) Increment count of visited nodes by 1.
    b) Decrease in-degree by 1 for all its neighbouring nodes.
    c) If in-degree of a neighbouring nodes is reduced to zero, then add it to
    the queue.

4. Repeat step 3 until the queue is empty.

5. If count of visited nodes is not equal to the number of nodes in the Graph
then topological sort is not possible for the given graph.
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v);
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

void Graph :: topologicalSort()
{
    vector<int> in_degree(V,0);
    for(int u=0;u<V;u++)
    {
        list<int> :: iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();++itr)
        {
            in_degree[*itr]++;
        }
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
        {
            q.push(i);
        }
    }
    int count = 0;
    vector<int> topological_order;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topological_order.push_back(u);
        list<int> :: iterator itr;
        for(itr=adj[u].begin();itr!=adj[u].end();++itr)
        {
            if(--in_degree[*itr]==0)
            {
                q.push(*itr);
            }
        }
        count++;
    }
    if(count != V)
    {
        cout << "There exists a cycle in the graph.\n";
        return;
    }
    for(int i=0;i<topological_order.size();i++)
    {
        cout << topological_order[i] << " ";
    }
    cout << endl;
}
