#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation and Shortest Path in Undirected Graph:
    ----------------------------------------------------------
    This program represents an undirected graph using an **Adjacency List** and provides functionality
    for computing the shortest path between two nodes using Breadth-First Search (BFS).

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<int>> adj**:
        - `adj` is an unordered map where each key represents a node (vertex), and the value is a list of integers.
          Each integer in the list represents a neighboring node.
        - This structure represents the adjacency list of the graph.

    Algorithms:
    -----------
    1. **Shortest Path using BFS**:
        - This algorithm finds the shortest path in an unweighted undirected graph from a source node to a destination node.
        - It uses BFS to explore nodes level by level and tracks the shortest path using a parent map.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction)**:
        - Adds an edge between nodes `u` and `v`.
        - The `direction` parameter specifies whether the edge is directed (`1`) or undirected (`0`).

    2. **printList()**:
        - Prints the adjacency list of the graph, showing each node and its neighbors.

    3. **shortestPathInUndirectedGraph(int src, int dest)**:
        - Computes the shortest path from `src` to `dest` in an undirected graph using BFS.
        - It maintains a `visited` map to keep track of visited nodes and a `parent` map to reconstruct the path.

*/

class Graph {
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<int>> adj;

    // Function to add an edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction) {
        // Add edge from u to v
        adj[u].push_back(v);
        // If undirected (direction == 0), also add edge from v to u
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list representation of the graph
    void printList() {
        for (auto x : adj) {
            cout << x.first << "->"; // Print the current node
            auto list = x.second;
            for (auto y : list) {
                cout << y << " , "; // Print each neighbor
            }
            cout << endl;
        }
    }

    // Function to compute the shortest path in an undirected graph from src to dest
    vector<int> shortestPathInUndirectedGraph(int src, int dest) {
        unordered_map<int, bool> visited; // Map to track visited nodes
        unordered_map<int, int> parent;   // Map to store the parent of each node in the BFS tree
        queue<int> q; // Queue for BFS

        // Initialize BFS
        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        // Perform BFS
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            for (auto nbr : adj[frontNode]) {
                if (!visited[nbr]) {
                    parent[nbr] = frontNode; // Set parent of neighbor
                    visited[nbr] = true;
                    q.push(nbr); // Enqueue neighbor
                }
            }
        }

        // Reconstruct the shortest path from dest to src
        vector<int> shortestPath;
        while (dest != src) {
            shortestPath.push_back(dest);
            dest = parent[dest]; // Move to the parent node
            if (dest == 0) { // If no path exists
                shortestPath.clear();
                break;
            }
        }
        shortestPath.push_back(src);
        reverse(shortestPath.begin(), shortestPath.end()); // Reverse the path to get the correct order

        return shortestPath;
    }
};

int main() {
    Graph g;

    // Adding undirected edges between nodes
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
    cout << "Adjacency List is " << endl;
    g.printList();

    // Input source and destination nodes for shortest path query
    int src, dest;
    cout << "Enter Source Node : ";
    cin >> src;
    cout << "Enter Destination Node : ";
    cin >> dest;
    cout << endl;

    // Compute the shortest path from source to destination
    auto shortestPath = g.shortestPathInUndirectedGraph(src, dest);

    // Print the shortest path or indicate that no path exists
    cout << "Shortest Path between " << src << " and " << dest << " is " << endl;
    if (shortestPath.size() == 0) {
        cout << "NO POSSIBLE PATH EXISTS ";
        return 0;
    }
    for (auto x : shortestPath) {
        cout << x << " -> ";
    }
    cout << "END" << endl;

    return 0;
}
