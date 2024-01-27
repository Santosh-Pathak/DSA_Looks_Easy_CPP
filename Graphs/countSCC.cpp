#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

class graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 1)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto &nbr : i.second)
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
    void dfs1(int src, stack<int> &s, unordered_map<int, bool> &vis)
    {
        vis[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!vis[nbr])
            {
                dfs1(nbr, s, vis);
            }
        }
        s.push(src);
    }

    void dfs2(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjNew)
    {
        visited[src] = true;
        cout << src << ", ";

        for (auto nbr : adjNew[src])
        {
            if (!visited[nbr])
            {
                dfs2(nbr, visited, adjNew);
            }
        }
    }

    void countStronglyConnectedComponents(int n)
    {
        stack<int> s;
        unordered_map<int, bool> visited;

        // find topo ordering
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs1(i, s, visited);
            }
        }

        // reverse all edges
        unordered_map<int, list<int>> adjNew;

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                // v-> u insert
                adjNew[v].push_back(u);
            }
        }

        // traversse using DFS
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!visited2[node])
            {
                cout << "Printing " << count + 1 << "th SCC: ";
                dfs2(node, visited2, adjNew);
                cout << endl;
                count++;
            }
        }
        cout << endl
             << count;
    }
};

int main()
{
    graph g;

    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 0, 0);
    // g.addEdge(2, 4, 0);
    // g.addEdge(4, 5, 0);
    // g.addEdge(5, 6, 0);
    // g.addEdge(6, 4, 0);
    // g.addEdge(6, 7, 0);

    g.addEdge(5, 5, 0);
    g.addEdge(1, 0, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 1, 0);
    g.addEdge(0, 3, 0);
    g.addEdge(3, 4, 0);

    g.printAdjList();
    g.countStronglyConnectedComponents(8);

    return 0;
}
