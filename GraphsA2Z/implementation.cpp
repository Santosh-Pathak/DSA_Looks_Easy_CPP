#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program uses an **Adjacency List** to represent a graph. 
    The graph can be either directed or undirected.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<int>> adj**: 
        - `adj` is a map where each key represents a node (or vertex), 
          and the value is a list of integers representing all the nodes 
          it is connected to (its neighbors).

    2. **list<int>**:
        - The list is used to store the neighbors of a particular node. 
          This helps efficiently manage and traverse adjacent nodes.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction)**:
        - This function adds an edge between nodes `u` and `v`.
        - If the `direction` is `0`, it means the graph is undirected, 
          so an edge is added in both directions: from `u` to `v` and from `v` to `u`.
        - If the `direction` is `1`, the graph is directed, so only a single edge is added from `u` to `v`.

    2. **printList()**:
        - This function prints the adjacency list for each node in the graph.
        - For each node, it lists all the nodes it is connected to.
*/

class Graph
{
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<int>> adj;

    // Function to add an edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        // If the graph is undirected, also add an edge from v to u
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list representation of the graph
    void printList()
    {
        // Iterate over all nodes in the adjacency list
        for (auto x : adj)
        {
            cout << x.first << " -> "; // Print the current node

            // Iterate over all neighbors of the current node
            for (auto y : x.second)
            {
                cout << y << " , "; // Print each neighbor
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    // Adding edges to the graph
    g.addEdge(1, 2, 0); // Add an undirected edge between nodes 1 and 2
    g.addEdge(2, 3, 0); // Add an undirected edge between nodes 2 and 3
    g.addEdge(1, 3, 0); // Add an undirected edge between nodes 1 and 3
    g.addEdge(3, 4, 0); // Add an undirected edge between nodes 3 and 4
    g.addEdge(2, 4, 0); // Add an undirected edge between nodes 2 and 4

    // Print the adjacency list of the graph
    g.printList();

    return 0;
}
