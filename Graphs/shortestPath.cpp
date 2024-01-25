#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList; //here pairis used to store data and node simultaneously


    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction 1 => undirected
        // direction 0 => directed
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << " ( " << j.first << " , " << j.second << " ) , ";
            }
            cout << endl;
        }
    }

    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        // Initial step for src
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int fNode = q.front(); // front node
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;

                    // If the destination is reached, break the loop
                    if (nbr.first == dest)
                        goto done;
                }
            }
        }
    done:

        // Reconstruct the path ) => counting the sortest  path ) 
        vector<int> path;
        int node = dest;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        // Print the Shortest Path
        cout << "Shortest Path from " << src << " to " << dest << " : ";
        for (int i = path.size() - 1; i >= 0; i--)
        {
            cout << path[i];
            if (i != 0)
                cout << " -> ";
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1, 1);
    g.addEdge(1, 2, 1, 1);
    g.addEdge(2, 3, 1, 1);

    g.addEdge(3, 4, 1, 1);
    g.addEdge(0, 5, 1, 1);
    g.addEdge(5, 4, 1, 1);

    g.addEdge(0, 6, 1, 1);
    g.addEdge(6, 7, 1, 1);
    g.addEdge(7, 8, 1, 1);
    g.addEdge(8, 4, 1, 1);

    g.printAdjList();
    g.shortestPathBFS(0, 4); // source , destination

    return 0;
}
