#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEgde(int u, int v, bool direction)
    {
        // directiom = 0 => undirected graph
        // directiom = 1 => directed graph

        // create a edge from u->v
        adj[u].push_back(v);
        if (direction==0)
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
};

int main()
{
    Graph g;
    g.addEgde(1, 2, 0);
    g.addEgde(2, 3, 0);
    g.addEgde(1, 3, 0);
    g.addEgde(3, 4, 0);
    g.addEgde(2, 4, 0);

    g.printList();
}