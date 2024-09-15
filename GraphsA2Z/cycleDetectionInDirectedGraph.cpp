#include <bits/stdc++.h>
using namespace std;

/*
 * This program represents a graph using an adjacency list and detects cycles in an 
 * undirected graph using Depth-First Search (DFS). 
 *
 * A cycle in an undirected graph is a path that starts and ends at the same vertex 
 * with no repeating edges or vertices.
 *
 * Data Structures:
 * 1. unordered_map<int, list<int>> adj: This stores the adjacency list of the graph.
 *    Each key in the unordered_map represents a node, and its associated value is a 
 *    list of neighboring nodes connected by edges.
 * 2. unordered_map<int, bool> visited: Tracks whether a node has been visited during DFS.
 * 3. unordered_map<int, bool> bfsVisited: Tracks whether a node is part of the current 
 *    path during the DFS. This helps in detecting back edges that form cycles.
 */

class Graph {
public:
    unordered_map<int, list<int>> adj;  // Adjacency list representation of the graph

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool direction) {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        // If the graph is undirected, add an edge from v to u as well
        if (direction == 0) {
            adj[v].push_back(u);  // Create an edge from v to u
        }
    }

    // Function to print the adjacency list
    void printList() {
        for (auto x : adj) {
            cout << x.first << "->";
            auto list = x.second;
            for (auto y : list) {
                cout << y << " , ";
            }
            cout << endl;
        }
    }

    /*
     * Function to detect a cycle in an undirected graph using DFS
     * src: The source node to start the DFS
     * visited: Map to track visited nodes
     * bfsVisited: Map to track nodes currently in the DFS recursion stack (to detect back edges)
     */
    bool detectCycleInUndirectedGraphDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &bfsVisited) {
        visited[src] = true;  // Mark the current node as visited
        bfsVisited[src] = true;  // Mark the node as part of the current DFS path

        // Explore all adjacent nodes
        for (auto nbr : adj[src]) {
            // If the neighbor is visited and still part of the current DFS path, a cycle is detected
            if (visited[nbr] && bfsVisited[nbr]) {
                return true;
            }
            // If the neighbor has not been visited, continue the DFS
            else if (!visited[nbr]) {
                bool checkCycle = detectCycleInUndirectedGraphDFS(nbr, visited, bfsVisited);
                if (checkCycle)
                    return true;
            }
        }

        bfsVisited[src] = false;  // Remove the node from the current DFS path as we backtrack
        return false;
    }
};

int main() {
    Graph g;
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // Adding edges to the graph
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0);  // For undirected graph, direction is 0
    }

    // Print the adjacency list of the graph
    cout << "Printing Adjacency List : " << endl;
    g.printList();

    // Using DFS to detect cycle in the undirected graph
    unordered_map<int, bool> visited;    // Map to track visited nodes
    unordered_map<int, bool> bfsVisited; // Map to track nodes in the current DFS path

    bool cycleDetected = false;

    // Run DFS from every unvisited node to ensure all components are covered
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (g.detectCycleInUndirectedGraphDFS(i, visited, bfsVisited)) {
                cycleDetected = true;
                break;
            }
        }
    }

    // Print the result based on whether a cycle was detected
    if (cycleDetected) {
        cout << "Cycle Present" << endl;
    } else {
        cout << "Cycle NOT Present" << endl;
    }

    return 0;
}
