#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program uses an **Adjacency List** to represent a weighted graph.
    The graph can be either directed or undirected.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is a map where each key represents a node (or vertex),
          and the value is a list of pairs. Each pair contains a neighboring node
          and the weight of the edge connecting the current node to that neighbor.

    Algorithms:
    -----------
    1. **Bellman-Ford Algorithm**:
        - The Bellman-Ford algorithm is used to find the shortest path from a single source node to all other nodes in a graph.
        - It can handle graphs with negative edge weights and can detect negative weight cycles.
        - The algorithm involves "relaxing" all edges multiple times (n-1 times for n nodes) to ensure the shortest path is found.
        - If after n-1 iterations, a shorter path is found, then the graph contains a negative weight cycle.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - This function adds a weighted edge between nodes `u` and `v` with a weight of `w`.
        - If the `direction` is `0`, it means the graph is undirected,
          so an edge is added in both directions: from `u` to `v` and from `v` to `u`.
        - If the `direction` is `1`, the graph is directed, so only a single edge is added from `u` to `v`.

    2. **printList()**:
        - This function prints the adjacency list for each node in the graph.
        - For each node, it lists all the nodes it is connected to along with the corresponding edge weights.

    3. **printGraphically()**:
        - This function provides a more visual representation of the graph, showing each node and the nodes it connects to, along with the weights of the edges.

    4. **bellmanFordAlgorithm(int src, int n)**:
        - This function implements the Bellman-Ford algorithm.
        - It calculates the shortest path from the source node `src` to all other nodes in the graph.
        - If a negative cycle is detected, it returns an empty vector. Otherwise, it returns the shortest distance from `src` to each node.
*/

class Graph
{
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add a weighted edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction, int w)
    {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u to v with weight w
        adj[u].push_back({v, w});

        // If the graph is undirected, also add an edge from v to u
        if (direction == 0)
        {
            adj[v].push_back({u, w});
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
                cout << "(" << y.first << ", " << y.second << ") "; // Print each neighbor and the weight of the edge
            }
            cout << endl;
        }
    }

    // Function to print a graphical representation of the graph
    void printGraphically()
    {
        cout << "Graphical Representation of the Graph:" << endl;
        for (auto x : adj)
        {
            int u = x.first;
            cout << "Node " << u << ":\n";
            for (auto y : x.second)
            {
                int v = y.first;
                int w = y.second;
                cout << "  |-> Node " << v << " (weight: " << w << ")" << endl; // Print each neighbor and the weight of the edge
            }
            cout << endl;
        }
    }

    // Function to implement the Bellman-Ford Algorithm
    vector<int> bellmanFordAlgorithm(int src, int n)
    {
        vector<int> dist(n + 1, INT_MAX); // Distance array initialized to infinity
        dist[src] = 0; // Distance to the source node is 0

        // Relax all edges n-1 times
        for (int i = 1; i <= n - 1; i++)
        {
            // Traverse each node and its adjacent nodes
            for (auto x : adj)
            {
                int u = x.first;
                for (auto edge : x.second)
                {
                    int v = edge.first;
                    int w = edge.second;

                    // Relax the edge (u, v)
                    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                    {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        // Check for negative weight cycles
        bool flag = false;
        for (auto x : adj)
        {
            int u = x.first;
            for (auto edge : x.second)
            {
                int v = edge.first;
                int w = edge.second;

                // If a shorter path is found after n-1 iterations, a negative cycle exists
                if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                {
                    flag = true;
                }
            }
        }

        // If a negative cycle is detected, return an empty vector
        if (flag)
        {
            cout << "Negative Cycle is Present in the Graph" << endl;
            return {};
        }
        else
        {
            // Print the distance array
            cout << "Distance array: ";
            for (int i = 1; i <= n; i++)
                cout << dist[i] << " ";
            cout << endl;

            return dist;
        }
    }
};

int main()
{
    Graph g;
    int n = 12;

    // Adding directed edges to the graph with weights
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

    cout << "Adjacency List is:" << endl;
    g.printList();
    cout << endl;

    int src, dest;
    cout << "Enter Source Node: ";
    cin >> src;
    cout << "Enter Destination Node: ";
    cin >> dest;

    // Perform Bellman-Ford algorithm to find the shortest path
    vector<int> shortestPath = g.bellmanFordAlgorithm(src, n);

    // If the shortestPath is not empty, print the shortest path distance
    if (!shortestPath.empty())
    {
        cout << "Shortest Path between " << src << " and " << dest << " is: " << shortestPath[dest] << endl;
    }

    return 0;
}
