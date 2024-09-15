#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program represents a weighted graph using an **Adjacency List**.
    The graph is implemented as a class that supports adding edges, printing
    the adjacency list, graphically representing the graph, and finding the
    Minimum Spanning Tree (MST) using Prim's Algorithm.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is an unordered map where each key is a node (vertex), and the value
          is a list of pairs representing neighboring nodes and the weights of the edges.
        - This represents the adjacency list of the graph.

    Algorithms:
    -----------
    1. **Prim's Algorithm**:
        - This algorithm finds the Minimum Spanning Tree (MST) of a graph.
        - It starts from a source node and iteratively expands the MST by adding the
          smallest edge that connects a node in the MST to a node outside of the MST.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds a weighted edge between nodes `u` and `v` with weight `w`.
        - If `direction` is `0`, the graph is undirected, and an edge is also added from `v` to `u`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection along with its weight.

    3. **printGraphically()**:
        - Provides a graphical-like representation of the graph, showing each node and its connections.

    4. **primsAlgorithm(int src, int n)**:
        - Implements Prim's Algorithm to find the Minimum Spanning Tree (MST) starting from the source node `src`.
*/

class Graph {
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add a weighted edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction, int w) {
        // Create an edge from u to v with weight w
        adj[u].push_back({v, w});

        // If undirected, also create an edge from v to u with the same weight
        if (direction == 0) {
            adj[v].push_back({u, w});
        }
    }

    // Function to print the adjacency list representation of the graph
    void printList() {
        for (auto x : adj) {
            cout << x.first << " -> "; // Print the current node
            for (auto y : x.second) {
                cout << "(" << y.first << ", " << y.second << ") "; // Print each neighbor and weight
            }
            cout << endl;
        }
    }

    // Function to print a graphical-like representation of the graph
    void printGraphically() {
        cout << "Graphical Representation of the Graph:" << endl;
        for (auto x : adj) {
            int u = x.first;
            cout << "Node " << u << ":\n"; // Print the current node
            for (auto y : x.second) {
                int v = y.first;
                int w = y.second;
                cout << "  |-> " << "Node " << v << " (weight: " << w << ")" << endl;
            }
            cout << endl;
        }
    }

    // Function to implement Prim's Algorithm to find the Minimum Spanning Tree (MST)
    void primsAlgorithm(int src, int n) {
        // Initialize key values, MST inclusion, and parent tracking
        vector<int> key(n + 1, INT_MAX);
        vector<bool> mst(n + 1, false);
        vector<int> parent(n + 1, -1);

        // Set the key value of the source node to 0
        key[src] = 0;

        // Prim's Algorithm to find MST
        for (int i = 1; i < n; i++) {
            int mini = INT_MAX;
            int u;

            // Find the node with the minimum key value not yet included in the MST
            for (int v = 1; v <= n; v++) {
                if (!mst[v] && key[v] < mini) {
                    u = v;
                    mini = key[v];
                }
            }

            // Include the selected node in the MST
            mst[u] = true;

            // Update the key and parent values for adjacent nodes
            for (auto nbr : adj[u]) {
                int v = nbr.first;
                int w = nbr.second;
                if (!mst[v] && w < key[v]) {
                    parent[v] = u;
                    key[v] = w;
                }
            }
        }

        // Print the MST edges and their weights
        cout << "Minimum Spanning Tree using Prim's Algorithm:" << endl;
        for (int i = 1; i <= n; i++) {
            if (parent[i] != -1) {
                cout << "Edge: " << parent[i] << " - " << i << " with weight: " << key[i] << endl;
            }
        }
    }
};

int main() {
    Graph g;

    int n = 12; // Number of nodes

    // Adding edges with varying weights
    g.addEdge(1, 2, false, 4);   // Node 1 to Node 2 with weight 4
    g.addEdge(1, 3, false, 2);   // Node 1 to Node 3 with weight 2
    g.addEdge(2, 3, false, 1);   // Node 2 to Node 3 with weight 1
    g.addEdge(2, 4, false, 3);   // Node 2 to Node 4 with weight 3
    g.addEdge(2, 5, false, 7);   // Node 2 to Node 5 with weight 7
    g.addEdge(3, 5, false, 4);   // Node 3 to Node 5 with weight 4
    g.addEdge(3, 6, false, 1);   // Node 3 to Node 6 with weight 1
    g.addEdge(4, 5, false, 2);   // Node 4 to Node 5 with weight 2
    g.addEdge(4, 7, false, 5);   // Node 4 to Node 7 with weight 5
    g.addEdge(5, 7, false, 6);   // Node 5 to Node 7 with weight 6
    g.addEdge(5, 6, false, 2);   // Node 5 to Node 6 with weight 2
    g.addEdge(6, 8, false, 4);   // Node 6 to Node 8 with weight 4
    g.addEdge(7, 8, false, 3);   // Node 7 to Node 8 with weight 3
    g.addEdge(7, 9, false, 7);   // Node 7 to Node 9 with weight 7
    g.addEdge(8, 9, false, 4);   // Node 8 to Node 9 with weight 4
    g.addEdge(9, 10, false, 5);  // Node 9 to Node 10 with weight 5
    g.addEdge(10, 11, false, 6); // Node 10 to Node 11 with weight 6
    g.addEdge(11, 12, false, 4); // Node 11 to Node 12 with weight 4
    g.addEdge(8, 12, false, 8);  // Node 8 to Node 12 with weight 8

    // Print the adjacency list of the graph
    cout << "Adjacency List is " << endl;
    g.printList();

    // Prompt the user for the source node for Prim's Algorithm
    int src;
    cout << "Enter Source Node: ";
    cin >> src;
    cout << endl;

    // Find the Minimum Spanning Tree using Prim's Algorithm
    g.primsAlgorithm(src, n);

    return 0;
}
