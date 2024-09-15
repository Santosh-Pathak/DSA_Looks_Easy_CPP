#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation and Shortest Path in DAG:
    -----------------------------------------------
    This program represents a directed weighted graph using an **Adjacency List** and provides functionality
    for computing the shortest path in a Directed Acyclic Graph (DAG) using topological sorting.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is an unordered map where each key represents a node (vertex), and the value is a list of pairs.
          Each pair represents a neighboring node and the weight of the edge connecting the nodes.
        - This structure represents the adjacency list of the graph.

    Algorithms:
    -----------
    1. **Topological Sort**:
        - A method to order nodes in a DAG such that for every directed edge UV from node U to node V, U comes before V.

    2. **Shortest Path in DAG**:
        - This algorithm calculates the shortest path from a source node to a destination node in a DAG.
        - It uses topological sorting and dynamic programming to update shortest path distances.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds a directed (or undirected, based on `direction`) weighted edge between node `u` and node `v` with weight `w`.

    2. **printList()**:
        - Prints the adjacency list of the graph, showing each node and its edges with weights.

    3. **printGraphically()**:
        - Provides a graphical-like representation of the graph, displaying each node and its connections with weights.

    4. **topologicalSortDFS(int src, stack<int> &st, unordered_map<int, bool> &visited)**:
        - Performs Depth-First Search (DFS) to generate a topological order of nodes.
        - The order is stored in a stack to facilitate processing nodes in topological order.

    5. **shortestPathInDAG(int src, int dest)**:
        - Computes the shortest path from `src` to `dest` in a DAG.
        - Initializes distances from `src` as infinite, then updates distances based on topological order.
        - Reconstructs the shortest path from `dest` to `src` and returns the path.

*/

class Graph {
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add a directed weighted edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction, int w) {
        // Create a directed edge from u to v with weight w
        adj[u].push_back({v, w});

        // If undirected (direction == 0), also create an edge from v to u with the same weight
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

    // Function to provide a graphical-like representation of the graph
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

    // Function to perform DFS for topological sorting
    void topologicalSortDFS(int src, stack<int> &st, unordered_map<int, bool> &visited) {
        visited[src] = true; // Mark the current node as visited

        for (auto x : adj[src]) {
            int nbr = x.first;
            if (!visited[nbr]) {
                topologicalSortDFS(nbr, st, visited); // Recursively visit neighbors
            }
        }

        st.push(src); // Push the current node onto the stack after visiting all neighbors
    }

    // Function to compute the shortest path in a DAG from src to dest
    vector<int> shortestPathInDAG(int src, int dest) {
        stack<int> st; // Stack to store the topological order of nodes
        unordered_map<int, bool> visited; // Map to keep track of visited nodes
        unordered_map<int, int> dist; // Map to store shortest distances from the source

        // Initialize all distances as infinite except for the source node
        for (auto i : adj) {
            dist[i.first] = INT_MAX;
        }
        dist[src] = 0;

        // Perform topological sort
        for (auto i : adj) {
            if (!visited[i.first]) {
                topologicalSortDFS(i.first, st, visited);
            }
        }

        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            // Update distances of all adjacent vertices
            if (dist[node] != INT_MAX) {
                for (auto i : adj[node]) {
                    if (dist[node] + i.second < dist[i.first]) {
                        dist[i.first] = dist[node] + i.second;
                    }
                }
            }
        }

        // Reconstruct the shortest path from dest to src
        vector<int> path;
        int currentNode = dest;
        while (currentNode != src) {
            path.push_back(currentNode);
            bool found = false;
            for (auto &i : adj) {
                for (auto &edge : i.second) {
                    if (edge.first == currentNode && dist[i.first] + edge.second == dist[currentNode]) {
                        currentNode = i.first;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found) { // If there's no path
                path.clear();
                break;
            }
        }
        path.push_back(src);
        reverse(path.begin(), path.end()); // Reverse the path to get the correct order

        return path;
    }
};

int main() {
    Graph g;

    // Adding directed edges with varying weights
    g.addEdge(1, 2, true, 4);   // Node 1 to Node 2 with weight 4
    g.addEdge(1, 3, true, -2);  // Node 1 to Node 3 with weight -2
    g.addEdge(2, 4, true, 3);   // Node 2 to Node 4 with weight 3
    g.addEdge(2, 5, true, 7);   // Node 2 to Node 5 with weight 7
    g.addEdge(3, 6, true, 1);   // Node 3 to Node 6 with weight 1
    g.addEdge(3, 7, true, -3);  // Node 3 to Node 7 with weight -3
    g.addEdge(4, 8, true, 2);   // Node 4 to Node 8 with weight 2
    g.addEdge(5, 9, true, -4);  // Node 5 to Node 9 with weight -4
    g.addEdge(6, 10, true, 5);  // Node 6 to Node 10 with weight 5
    g.addEdge(7, 11, true, 6);  // Node 7 to Node 11 with weight 6
    g.addEdge(8, 12, true, 8);  // Node 8 to Node 12 with weight 8
    g.addEdge(9, 10, true, 7);  // Node 9 to Node 10 with weight 7
    g.addEdge(10, 11, true, 3); // Node 10 to Node 11 with weight 3
    g.addEdge(11, 12, true, 4); // Node 11 to Node 12 with weight 4
    g.addEdge(5, 12, true, -1); // Node 5 to Node 12 with weight -1
    g.addEdge(6, 9, true, 2);   // Node 6 to Node 9 with weight 2

    // Print the adjacency list of the graph
    cout << "Adjacency List is " << endl;
    g.printList();
    cout << "Adjacency List is " << endl;

    // Print the graphical representation of the graph
    g.printGraphically();

    // Input source and destination nodes for shortest path query
    int src, dest;
    cout << "Enter Source Node: ";
    cin >> src;
    cout << "Enter Destination Node: ";
    cin >> dest;
    cout << endl;

    // Compute the shortest path from source to destination
    auto shortestPath = g.shortestPathInDAG(src, dest);

    // Print the shortest path or indicate that no path exists
    cout << "Shortest Path between " << src << " and " << dest << " is: " << endl;
    if (shortestPath.empty()) {
        cout << "NO POSSIBLE PATH EXISTS" << endl;
    } else {
        for (auto x : shortestPath) {
            cout << x << " -> ";
        }
        cout << "END" << endl;
    }

    return 0;
}
