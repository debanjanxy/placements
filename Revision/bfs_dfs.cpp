#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    //void BFSUtil(int s, list<int> )
    void DFSUtil(int s, vector<bool> &visited);
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int s, vector<bool> &visited, queue<int> &que);
    void DFS();
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

void Graph :: DFSUtil(int s, vector<bool> &visited)
{
    visited[s] = true;
    cout << s << " ";
    list<int> :: iterator i;
    for(i=adj[s].begin();i!=adj[s].end();++i)
    {
        if(!visited[*i])
        {
            DFSUtil(*i, visited);
        }
    }
}

void Graph :: DFS()
{
    vector<bool> visited(V, false);
    for(int i1=0;i1<V;i1++)
    {
        if(!visited[i1])
        {
            DFSUtil(i1,visited);
        }
    }
    cout << endl;
}

void Graph :: BFS(int s, vector<bool> &visited, queue<int> &que)
{
    visited[s] = true;
    que.push(s);
    //cout << s << " ";
    while(!que.empty())
    {
        int k = que.front();
        que.pop();
        cout << k << " ";
        list<int> :: iterator i;
        for(i=adj[k].begin();i!=adj[k].end();++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                que.push(*i);
            }
        }
    }
    cout << endl;
}

int main()
{
    int V = 5;
    Graph g(V);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    vector<bool> visited(V,false);
    queue<int> *que = new queue<int>[V];

    g.BFS(0,visited,*que);
    g.DFS();
    return 0;
}
