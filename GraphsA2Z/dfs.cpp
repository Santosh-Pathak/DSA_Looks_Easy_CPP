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

    2. **unordered_map<int, bool> visited**:
        - `visited` is a map where each key represents a node, and the value
          is a boolean indicating whether the node has been visited during the DFS traversal.

    Algorithms:
    -----------
    1. **Depth First Search (DFS)**:
        - DFS is a graph traversal algorithm that explores as far as possible
          along each branch before backtracking.
        - In this implementation, DFS is used to visit all reachable nodes from a given source node.

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

    3. **dfs(int src)**:
        - This function performs a Depth First Search starting from the `src` node.
        - It recursively visits all the nodes connected to the current node that haven't been visited yet.
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

    // Map to track visited nodes during DFS
    unordered_map<int, bool> visited;

    // Function to perform Depth First Search (DFS) starting from the `src` node
    void dfs(int src)
    {
        cout << src << " ";       // Print the current node
        visited[src] = true;      // Mark the current node as visited

        // Recursively visit all adjacent nodes that haven't been visited
        for (auto x : adj[src])
        {
            if (!visited[x])
            {
                dfs(x); // Recursive DFS call
            }
        }
    }
};

int main()
{
    Graph g;

    // Adding edges to the graph (undirected in this case)
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

    // Print the adjacency list of the graph
    cout << "Adjacency List is:" << endl;
    g.printList();
    cout << endl;

    // Perform Depth First Search starting from node 1
    cout << "Depth First Search (DFS) starting from node 1:" << endl;
    g.dfs(1);

    return 0;
}
