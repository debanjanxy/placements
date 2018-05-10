#include <bits/stdc++.h>
using namespace std;

class graph
{
    int V;
    list<int> *adj;
    vector<int> in_degree;
    void allTopologicalSortUtil(vector<int> &res, bool visited[]);
public:
    Graph(int V);
    void addEdge(int u, int v);
    void allTopologicalSort();
};

Graph :: Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    for(int i=0;i<V;i++)
    {
        in_degree.push_back(0);
    }
}

void Graph :: addEdge(int u, int v)
{
    adj[u].push_back(v);
    in_degree[v]++;
}

void Graph :: allTopologicalSortUtil(vector<int> &res, bool visited[])
{
    //To indicate whether all topological are found or not
    bool flag = false;
    for(int i=0;i<V;i++)
    {
        if(!visited[i] && in_degree[i]==0)
        {
            //reduce the in degree of the adjacent vertices
            list<int> :: iterator itr;
            for(itr=adj[i].begin();itr!=adj[i].end();++itr)
            {
                in_degree[*itr]--;
            }
            //including in result
            res.push_back(i);
            visited[i] = true;
            allTopologicalSortUtil(res,visited);
            //resetting visited, res and indegree for backtracking
            visited[i] = false;
            res.erase(res.end()-1);
            for(itr=adj[i].begin();itr!=adj[i].end();++itr)
            {
                in_degree[*itr]++;
            }
            flag = true;
        }
    }
    //All vertices are visited so print the solution
    if(flag)
    {
        for(int i=0;i<res.size();i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
void Graph :: allTopologicalSort()
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i] = false;
    }
    vector<int> res;
    allTopologicalSortUtil(res,visited);
}
