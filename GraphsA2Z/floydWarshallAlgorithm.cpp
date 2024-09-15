#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program represents a weighted directed graph using an **Adjacency List**.
    The graph is implemented as a class that supports adding edges, printing the adjacency list,
    and computing the shortest paths between all pairs of nodes using the Floyd-Warshall algorithm.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is an unordered map where each key is a node (vertex), and the value is a list of pairs.
          Each pair contains a neighboring node and the weight of the edge connecting the two nodes.

    2. **vector<vector<int>> dist**:
        - `dist` is a 2D vector (matrix) used to store the shortest distance between any two nodes.
        - It is initialized with a large value (`1e9`) to represent initially infinite distances.

    Algorithms:
    -----------
    1. **Floyd-Warshall Algorithm**:
        - This algorithm computes the shortest paths between all pairs of nodes in a weighted graph.
        - It is particularly useful for dense graphs and can handle negative weights (but no negative cycles).

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds a directed edge from node `u` to node `v` with weight `w`.
        - If `direction` is `0`, the graph is undirected, and an edge is also added from `v` to `u`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection and its weight.

    3. **floydWarshal(int n)**:
        - Implements the Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes.
        - `n` is the total number of nodes in the graph.
        - Outputs the distance matrix where each entry `(i, j)` represents the shortest distance from node `i` to node `j`.
*/

class Graph
{
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add an edge between nodes `u` and `v` with weight `w`
    void addEdge(int u, int v, bool direction, int w)
    {
        // Create a directed edge from u to v
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
        for (auto x : adj)
        {
            cout << x.first << " -> "; // Print the current node
            for (auto y : x.second)
            {
                cout << "(" << y.first << ", " << y.second << ") "; // Print each neighbor and the weight
            }
            cout << endl;
        }
    }

    // Function to implement the Floyd-Warshall algorithm
    void floydWarshal(int n)
    {
        // Distance matrix initialized to a large value (infinity)
        vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));

        // Distance of each node to itself is zero
        for (int i = 1; i <= n; i++)
        {
            dist[i][i] = 0;
        }

        // Filling the initial distances from the adjacency list
        for (auto t : adj)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        // Applying the Floyd-Warshall algorithm
        for (int helper = 1; helper <= n; helper++)
        {
            for (int src = 1; src <= n; src++)
            {
                for (int dest = 1; dest <= n; dest++)
                {
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }

        // Printing the distance matrix
        cout << "Printing distance matrix: " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] == 1e9)
                {
                    cout << "INF, "; // If distance is still infinity, print "INF"
                }
                else
                {
                    cout << dist[i][j] << ", "; // Otherwise, print the distance
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    int n = 7; // Number of nodes in the graph

    // Adding edges to the graph with specified weights
    g.addEdge(1, 2, true, 4);  // Node 1 to Node 2 with weight 4
    g.addEdge(1, 3, true, -2); // Node 1 to Node 3 with weight -2
    g.addEdge(2, 4, true, 3);  // Node 2 to Node 4 with weight 3
    g.addEdge(2, 5, true, 7);  // Node 2 to Node 5 with weight 7
    g.addEdge(3, 6, true, 1);  // Node 3 to Node 6 with weight 1

    // Print the adjacency list of the graph
    cout << "Adjacency List is " << endl;
    g.printList();
    cout << endl;

    // Applying the Floyd-Warshall algorithm to find shortest paths between all pairs of nodes
    g.floydWarshal(n);

    return 0;
}
