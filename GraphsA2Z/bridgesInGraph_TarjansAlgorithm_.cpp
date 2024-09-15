#include <bits/stdc++.h>
using namespace std;

/*
 * This program represents a graph using an adjacency list and includes functionality 
 * to detect bridges in the graph using Depth-First Search (DFS). 
 * 
 * A bridge is an edge in a graph whose removal increases the number of connected components. 
 * Bridges are important in network analysis as they represent critical connections.
 *
 * Data Structures:
 * 1. unordered_map<int, list<pair<int, int>>> adj: This stores the adjacency list of the graph.
 *    Each key in the unordered_map represents a node, and its associated value is a list of 
 *    pairs where each pair consists of a neighboring node and the weight of the edge between 
 *    them.
 * 2. vector<int> disc: Stores the discovery time of each node during DFS.
 * 3. vector<int> low: Stores the lowest discovery time reachable from each node.
 * 4. unordered_map<int, bool> visited: Tracks whether a node has been visited during DFS.
 * 5. vector<vector<int>> result: Stores the bridges found in the graph, where each bridge is 
 *    represented as a pair of nodes.
 */

class Graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;  // Adjacency list representation of the graph

    // Function to add an edge to the graph
    void addEdge(int u, int v, bool direction, int w) {
        adj[u].push_back({v, w});  // Add edge from u to v with weight w

        // If the graph is undirected, add an edge from v to u as well
        if (direction == 0) {
            adj[v].push_back({u, w});
        }
    }

    // Function to print the adjacency list
    void printList() {
        for (auto x : adj) {
            cout << x.first << " -> ";
            for (auto y : x.second) {
                cout << "(" << y.first << ", " << y.second << ") ";
            }
            cout << endl;
        }
    }

    // Function to print a graphical representation of the graph
    void printGraphically() {
        cout << "Graphical Representation of the Graph:" << endl;
        for (auto x : adj) {
            int u = x.first;
            cout << "Node " << u << ":\n";
            for (auto y : x.second) {
                int v = y.first;
                int w = y.second;
                cout << "  |-> " << "Node " << v << " (weight: " << w << ")" << endl;
            }
            cout << endl;
        }
    }

    // DFS function to find bridges in the graph
    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &visited, vector<vector<int>> &result) {
        visited[node] = true;  // Mark the current node as visited
        disc[node] = timer;    // Set the discovery time of the current node
        low[node] = timer;     // Initially, the lowest discovery time reachable from the node is its own discovery time
        timer++;               // Increment the timer

        // Explore all adjacent nodes
        for (auto nbr : adj[node]) {
            if (nbr.first == parent)  // Skip the edge leading back to the parent node
                continue;
            if (!visited[nbr.first]) {  // If the neighbor has not been visited, perform DFS on it
                dfs(nbr.first, node, timer, disc, low, visited, result);

                // Update the lowest discovery time reachable from the current node
                low[node] = min(low[node], low[nbr.first]);

                // If the lowest discovery time of the neighbor is greater than the discovery time of the current node, it is a bridge
                if (low[nbr.first] > disc[node]) {
                    result.push_back({node, nbr.first});
                }
            } else {
                // Update the lowest discovery time reachable if the neighbor is already visited
                low[node] = min(low[node], disc[nbr.first]);
            }
        }
    }

    // Function to find all bridges in the graph
    vector<vector<int>> bridgesInGraph(int n) {
        vector<int> disc(n, -1);  // Initialize discovery time array
        vector<int> low(n, -1);   // Initialize lowest discovery time array
        unordered_map<int, bool> visited;  // Initialize visited map
        int timer = 0;  // Initialize timer

        vector<vector<int>> result;  // To store the bridges

        // Run DFS from every unvisited node to ensure all components are covered
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, -1, timer, disc, low, visited, result);
            }
        }
        return result;
    }
};

int main() {
    Graph g;
    int n = 7; // Number of nodes

    // Add edges (u, v) with direction (0 for undirected, 1 for directed) and weight w
    g.addEdge(1, 2, false, 1);
    g.addEdge(2, 3, false, 1);
    g.addEdge(3, 4, false, 1);
    g.addEdge(3, 5, false, 2);
    g.addEdge(4, 5, false, 1);
    g.addEdge(5, 6, false, 1);
    g.addEdge(6, 7, false, 1);

    // Print the adjacency list of the graph
    cout << "Adjacency List is " << endl;
    g.printList();

    cout << endl;

    // Find and print all bridges in the graph
    vector<vector<int>> ans = g.bridgesInGraph(n);
    cout << "Total Number of Bridges in Graph are : " << ans.size() << endl;
    cout << "Bridges Edges in Graph are as : " << endl;

    for (auto x : ans) {
        cout << x[0] << " -> " << x[1] << endl;
    }

    return 0;
}
