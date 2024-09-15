#include <bits/stdc++.h>
using namespace std;

/*
 * This program represents a graph using an adjacency list and detects cycles in an 
 * undirected graph using both BFS (Breadth-First Search) and DFS (Depth-First Search). 
 * It can detect whether a cycle exists in the graph.
 *
 * Data Structures:
 * 1. unordered_map<int, list<int>> adj: Stores the adjacency list of the graph.
 *    Each key represents a node, and its value is a list of neighboring nodes connected by edges.
 * 2. unordered_map<int, bool> visited: Tracks whether a node has been visited during traversal.
 * 3. unordered_map<int, int> parent (for BFS): Keeps track of each node's parent in the BFS tree to detect cycles.
 * 4. queue<int> q (for BFS): Queue to facilitate the level-order traversal in BFS.
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
            for (auto y : x.second) {
                cout << y << " , ";
            }
            cout << endl;
        }
    }

    /*
     * Function to detect a cycle in an undirected graph using BFS
     * src: The source node to start the BFS
     * visited: Map to track visited nodes
     */
    bool detectCycleInUndirectedGraphBFS(int src, unordered_map<int, bool> &visited) {
        unordered_map<int, int> parent; // To track the parent of each node
        queue<int> q;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;  // Root node has no parent

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            // Explore all adjacent nodes
            for (auto neighbor : adj[frontNode]) {
                // If the neighbor is visited and is not the parent of the current node, a cycle is detected
                if (visited[neighbor] && parent[frontNode] != neighbor) {
                    return true;
                }
                // If the neighbor has not been visited, continue the BFS
                else if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = frontNode;  // Set the current node as the parent
                }
            }
        }
        return false;  // No cycle detected
    }

    /*
     * Function to detect a cycle in an undirected graph using DFS
     * src: The source node to start the DFS
     * visited: Map to track visited nodes
     * parent: The parent of the current node in the DFS tree
     */
    bool detectCycleInUndirectedGraphDFS(int src, unordered_map<int, bool> &visited, int parent) {
        visited[src] = true;  // Mark the current node as visited

        // Explore all adjacent nodes
        for (auto nbr : adj[src]) {
            // If the neighbor has not been visited, continue the DFS
            if (!visited[nbr]) {
                bool ans = detectCycleInUndirectedGraphDFS(nbr, visited, src);
                if (ans)
                    return true;  // Cycle detected in the DFS subtree
            }
            // If the neighbor is visited and is not the parent, a cycle is detected
            else if (parent != nbr) {
                return true;
            }
        }
        return false;  // No cycle detected
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

    // Detecting cycle using DFS
    unordered_map<int, bool> visited;  // Map to track visited nodes
    bool cycleDetected = false;

    // Run DFS from every unvisited node to ensure all components are covered
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (g.detectCycleInUndirectedGraphDFS(i, visited, -1)) {  // -1 as the initial parent
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
