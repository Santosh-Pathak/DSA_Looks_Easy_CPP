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

    bool detectCycleInUndirectedGraphDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &bfsVisited)
    {

        visited[src] = true;
        bfsVisited[src] = true;
        for (auto nbr : adj[src])
        {
            if (visited[nbr] && bfsVisited[nbr])
            {
                return true;
            }
            else if (!visited[nbr])
            {

                bool checkCycle = detectCycleInUndirectedGraphDFS(nbr, visited, bfsVisited);
                if (checkCycle)
                    return true;
            }
        }
        bfsVisited[src] = false;
        return false;
    }
};

int main()
{
    Graph g;
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // For undirected graph
    }
    cout << "Printing Adjacency List : " << endl;
    g.printList();
    // Using DFS
    unordered_map<int, bool> visited;
    unordered_map<int, bool> bfsVisited;

    int parent = -1;
    bool cycleDetected = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (g.detectCycleInUndirectedGraphDFS(i, visited, bfsVisited))
            {
                cycleDetected = true;
                break;
            }
        }
    }

    if (cycleDetected)
    {
        cout << "Cycle Present" << endl;
    }
    else
    {
        cout << "Cycle NOT Present" << endl;
    }

    return 0;
}