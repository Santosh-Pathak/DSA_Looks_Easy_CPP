#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // create an edge from u->v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u); // create an edge from v->u
        }
    }

    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "->";
            for (auto y : x.second)
            {
                cout << y << " , ";
            }
            cout << endl;
        }
    }

    bool detectCycleInUndirectedGraphBFS(int src, unordered_map<int, bool> &visited)
    {
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbor : adj[frontNode])
            {
                if (visited[neighbor] && parent[frontNode] != neighbor)
                {
                    return true;
                }
                else if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = frontNode;
                }
            }
        }
        return false;
    }
    bool detectCycleInUndirectedGraphDFS(int src, unordered_map<int, bool> &visited, int parent)
    {
        visited[src] = true;

        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                bool ans = detectCycleInUndirectedGraphDFS(nbr, visited, src);
                if (ans)
                    return true;
            }
            else if (parent != nbr)
            {
                return true;
            }
        }
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
    // Using BFS
    //  unordered_map<int, bool> visited;
    //  bool cycleDetected = false;
    //  for (int i = 1; i <= n; i++)
    //  {
    //      if (!visited[i])
    //      {
    //          if (g.detectCycleInUndirectedGraphBFS(i, visited))
    //          {
    //              cycleDetected = true;
    //              break;
    //          }
    //      }
    //  }

    // Using DFS
    unordered_map<int, bool> visited;
    int parent = -1;
    bool cycleDetected = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (g.detectCycleInUndirectedGraphDFS(i, visited, parent))
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
