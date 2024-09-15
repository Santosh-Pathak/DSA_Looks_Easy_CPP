#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program represents an undirected or directed graph using an **Adjacency List**.
    The graph is implemented as a class that supports adding edges, printing the adjacency list,
    and finding the Minimum Spanning Tree (MST) using Kruskal's Algorithm.

    Data Structures Used:
    ---------------------
    1. **map<int, list<pair<int, int>>> adj**:
        - `adj` is a map where each key is a node (vertex), and the value is a list of pairs representing
          neighboring nodes and the weight of the edge connecting them.
        - This represents the adjacency list of the graph.

    2. **vector<int> parent**:
        - `parent` is used to store the parent of each node in the Union-Find structure, which helps
          in detecting cycles during the MST formation.

    3. **vector<int> rank**:
        - `rank` is used in the Union-Find structure to keep the tree flat by attaching smaller trees under
          the root of the larger tree during the union operation.

    Algorithms:
    -----------
    1. **Kruskal's Algorithm**:
        - This algorithm is used to find the Minimum Spanning Tree (MST) of a graph.
        - It is a greedy algorithm that sorts all edges by weight and then processes them in ascending order.
        - Union-Find data structure is used to ensure that no cycles are formed during the MST construction.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds an edge between nodes `u` and `v` with weight `w`.
        - If `direction` is `0`, the graph is undirected, and an edge is also added from `v` to `u`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection along with the corresponding edge weights.

    3. **kruskalsAlgorithm(int n)**:
        - Implements Kruskal's Algorithm to find and print the Minimum Spanning Tree (MST) of the graph.
        - It also calculates and prints the total cost of the MST.
*/

class Graph {
public:
    // Adjacency list representation using a map
    map<int, list<pair<int, int>>> adj;

    // Function to add an edge between nodes `u` and `v` with weight `w`
    void addEdge(int u, int v, bool direction, int w) {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u -> v with weight w
        adj[u].push_back({v, w});
        if (direction == 0) {
            adj[v].push_back({u, w}); // If undirected, also create an edge from v -> u
        }
    }

    // Function to print the adjacency list representation of the graph
    void printList() {
        for (auto x : adj) {
            cout << x.first << " -> "; // Print the current node
            for (auto y : x.second) {
                cout << "(" << y.first << ", " << y.second << ") "; // Print each neighbor and the edge weight
            }
            cout << endl;
        }
    }

    // Find the parent of a node in the Union-Find structure with path compression
    int findParent(vector<int>& parent, int node) {
        if (parent[node] == node) {
            return node;
        }

        // Path compression
        return parent[node] = findParent(parent, parent[node]);
    }

    // Union two sets in the Union-Find structure by rank
    void unionSet(int u, int v, vector<int>& rank, vector<int>& parent) {
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
    }

    // Function to implement Kruskal's Algorithm to find the MST
    void kruskalsAlgorithm(int n) {
        vector<pair<int, pair<int, int>>> edges;

        // Collect all edges
        for (auto i : adj) {
            int u = i.first;
            for (auto j : i.second) {
                int v = j.first;
                int w = j.second;
                edges.push_back({w, {u, v}});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        // Initialize parent array for Union-Find
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        int cost = 0;
        vector<pair<int, int>> mst;

        // Process edges
        for (auto edge : edges) {
            int w = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;

            // Check if the current edge forms a cycle
            if (findParent(parent, u) != findParent(parent, v)) {
                cost += w;
                mst.push_back({u, v});
                unionSet(u, v, rank, parent);
            }
        }

        // Print the MST
        cout << "Minimum Spanning Tree Cost: " << cost << endl;
        cout << "Edges in the MST:" << endl;
        for (auto edge : mst) {
            cout << edge.first << " - " << edge.second << endl;
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

    // Find the Minimum Spanning Tree using Kruskal's Algorithm
    g.kruskalsAlgorithm(n);

    return 0;
}
