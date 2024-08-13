#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool direction)
    {
        // directiom = 0 => undirected graph
        // directiom = 1 => directed graph

        // create a edge from u->v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        } // create a edge from v->u
    }
    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "->";
            auto list = x.second;
            for (auto y : list)
            {
                cout << y << " , ";
            }
            cout << endl;
        }
    }
    void bfs(int src)
    {
        queue<int> q;
        unordered_map<int, bool> visited; // int ->data  ,bool - > visited or NOt
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            cout << frontNode<<" ";
            for (auto x : adj[frontNode])
            {
                if (visited[x] == false)
                {
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
    }
};

int main()
{
    Graph g;
g.addEdge(1, 2, 0);
g.addEdge(1, 3, 0);
g.addEdge(2, 4, 0);
g.addEdge(2, 5, 0);
g.addEdge(3, 6, 0);
g.addEdge(3, 7, 0);
g.addEdge(4, 8, 0);
g.addEdge(5, 9, 0);
g.addEdge(6, 10, 0);
g.addEdge(7, 11, 0);
g.addEdge(8, 12, 0);
g.addEdge(9, 10, 0);
g.addEdge(10, 11, 0);
g.addEdge(11, 12, 0);
g.addEdge(5, 12, 0);
g.addEdge(6, 9, 0);

    cout<<"Adjacency List is "<<endl;
    g.printList();
    cout<<"Breadth First Search "<<endl;
    g.bfs(5);

}