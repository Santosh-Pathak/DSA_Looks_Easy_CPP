#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program represents a directed or undirected graph using an **Adjacency List**.
    The graph is implemented as a class that supports adding edges, printing the adjacency list,
    and performing topological sorting using both BFS (Kahn's Algorithm) and DFS.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<int>> adj**:
        - `adj` is an unordered map where each key is a node (vertex), and the value is a list of neighboring nodes.
        - This represents the adjacency list of the graph.

    2. **unordered_map<int, int> indegree**:
        - `indegree` stores the number of incoming edges for each node.
        - It is used in Kahn's Algorithm for BFS-based topological sorting.

    3. **unordered_map<int, bool> visited**:
        - `visited` is used to keep track of visited nodes during the DFS traversal for topological sorting.

    4. **stack<int> s**:
        - `s` is used to store the nodes in the correct topological order during the DFS-based topological sorting.

    Algorithms:
    -----------
    1. **Kahn's Algorithm (BFS-based Topological Sort)**:
        - This algorithm is used to generate a topological sort of a Directed Acyclic Graph (DAG) using a BFS approach.
        - It relies on calculating the indegree of each node and processing nodes with zero indegree first.

    2. **DFS-based Topological Sort**:
        - This algorithm generates a topological sort of a DAG using a DFS approach.
        - Nodes are recursively visited, and after visiting all neighbors, the node is added to a stack to ensure correct ordering.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction)**:
        - Adds an edge between nodes `u` and `v`.
        - If `direction` is `0`, the graph is undirected, and an edge is also added from `v` to `u`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection.

    3. **topologicalSortUsingBFS()**:
        - Implements Kahn's Algorithm to perform BFS-based topological sorting of the graph.

    4. **topologicalSortDFS(int node, unordered_map<int, bool> &visited, stack<int> &s)**:
        - Performs DFS-based topological sorting of the graph and stores the result in a stack.
*/

class Graph {
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<int>> adj;

    // Function to add an edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction) {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u -> v
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u); // If undirected, also create an edge from v -> u
        }
    }

    // Function to print the adjacency list representation of the graph
    void printList() {
        for (auto x : adj) {
            cout << x.first << " -> "; // Print the current node
            for (auto y : x.second) {
                cout << y << " , "; // Print each neighbor
            }
            cout << endl;
        }
    }

    // Kahn's algorithm for Topological Sort (BFS-based)
    void topologicalSortUsingBFS() {
        // Step 1: Calculate the indegree of each node
        unordered_map<int, int> indegree;
        for (auto x : adj) {
            for (auto y : x.second) {
                indegree[y]++; // Increment indegree of each neighbor
            }
        }

        // Step 2: Find all nodes with indegree 0 and add them to the queue
        queue<int> q;
        for (auto x : adj) {
            if (indegree[x.first] == 0) {
                q.push(x.first);
            }
        }

        // Step 3: Process the queue
        vector<int> ans;
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            // Decrease the indegree of neighbors and add them to the queue if indegree becomes 0
            for (auto nbr : adj[frontNode]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        // Print the topological sort order
        cout << "Topological Sort using BFS: " << endl;
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }

    // DFS-based Topological Sort
    void topologicalSortDFS(int node, unordered_map<int, bool> &visited, stack<int> &s) {
        visited[node] = true; // Mark the current node as visited

        // Visit all the neighbors recursively
        for (auto nbr : adj[node]) {
            if (!visited[nbr]) {
                topologicalSortDFS(nbr, visited, s);
            }
        }

        // After visiting all neighbors, push the current node to the stack
        s.push(node);
    }
};

int main() {
    Graph g;

    // Adding edges to the graph (directed)
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(4, 8, 1);
    g.addEdge(5, 9, 1);
    g.addEdge(6, 10, 1);
    g.addEdge(7, 11, 1);
    g.addEdge(8, 12, 1);
    g.addEdge(9, 10, 1);
    g.addEdge(10, 11, 1);
    g.addEdge(11, 12, 1);

    // Print the adjacency list of the graph
    cout << "Printing Adjacency List: " << endl;
    g.printList();

    // Topological Sort using BFS (Kahn's Algorithm)
    g.topologicalSortUsingBFS();

    // Topological Sort using DFS
    unordered_map<int, bool> visited;
    stack<int> s;

    // Perform DFS-based topological sort for each unvisited node
    for (int i = 1; i <= 12; i++) {
        if (!visited[i]) {
            g.topologicalSortDFS(i, visited, s);
        }
    }

    // Convert the stack into a sorted array for the topological order
    vector<int> sortedArray;
    while (!s.empty()) {
        sortedArray.push_back(s.top());
        s.pop();
    }

    // Print the topological sort order using DFS
    cout << "Topological Sort using DFS: " << endl;
    for (auto x : sortedArray) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
