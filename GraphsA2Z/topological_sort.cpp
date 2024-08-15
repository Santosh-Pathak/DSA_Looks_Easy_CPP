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

    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[src] = true;
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                topologicalSortDFS(nbr, visited, s);
            }
        }
        s.push(src);
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(4, 8, 1);
    g.addEdge(5, 9, 1);
    g.addEdge(6, 10, 1);
    g.addEdge(7, 11, 1);
    g.addEdge(8, 12, 1);
    g.addEdge(9, 10, 1);
    g.addEdge(10, 11, 1);
    g.addEdge(11, 12, 1);
    cout << "Printing Adjacency List : " << endl;
    g.printList();

    // Using DFS
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 1; i <= 12; i++)
    {
        if (!visited[i])
        {
            g.topologicalSortDFS(i, visited, s);
        }
    }
    vector<int> sortedArray;
    while (!s.empty())
    {
        sortedArray.push_back(s.top());
        s.pop();
    }

    cout << "Topological Sort is " << endl;
    for (auto x : sortedArray)
    {
        cout << x << " ";
    }
}