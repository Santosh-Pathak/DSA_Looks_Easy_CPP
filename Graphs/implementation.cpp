// 1-> implementation of Graph using Adjacency matrix
// int main()
// {
//     int n;
//     cout<<"Enter the Number of Nodes : "
//     cin >> n;
//     int e;
//     cout << "Enter the Number of  edges : " << endl;
//     cin >> e;
//     vector<vector<int>> adj(n, vector<int>(n, 0));
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u][v] = 1;
//     }
//     cout << " Printing the Matrix " << endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//             cout << adj[i][j] << " ";
//         cout << endl;
//     }
// }

// 2-> implementation of Graph using Adjacency List
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, vector<T>> adjList;
    void addEdge(T u, T v, bool direction)
    {
        // direction == 0 -> undirected graph
        // direction == 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // create an edge from v to u for an undirected graph
            adjList[v].push_back(u);
        }
    }
    void printAdjacency()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto x : node.second)
                cout << x << " , ";
            cout << endl;
        }
    }
};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'c', 0);
    g.printAdjacency();
    cout << endl; 

    // Undirected Input
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // g.printAdjacency();
    // cout << endl; 
    // Directed Input
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(0, 2, 1);
    // g.printAdjacency();
    // return 0;

}
