#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation:
    ---------------------
    This program represents a weighted graph using an **Adjacency List**,
    where each node can be connected to other nodes with an associated weight.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is a map where each key represents a node (or vertex),
          and the value is a list of pairs. Each pair consists of a neighboring node
          and the weight of the edge connecting the two nodes.

    2. **set<pair<int, int>> s** and **priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq**:
        - These are used in Dijkstra's algorithm to efficiently fetch the next node with the smallest
          known distance.

    3. **vector<int> dist**:
        - `dist` is a vector that stores the shortest distance from the source node to every other node.
        - It is initialized with `INT_MAX` to represent an initially infinite distance to all nodes.

    Algorithms:
    -----------
    1. **Dijkstra's Algorithm**:
        - This algorithm finds the shortest path from a single source node to all other nodes in a graph
          with non-negative edge weights.
        - Implemented using both a set and a priority queue for efficient minimum distance extraction.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds an edge between nodes `u` and `v` with weight `w`.
        - If `direction` is `0`, the graph is undirected, so an edge is also added from `v` to `u`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection and its weight.

    3. **printGraphically()**:
        - Provides a more graphical representation of the graph, showing the connections
          of each node along with the weights.

    4. **dijkstraAlgorithm(int src)**:
        - Implements Dijkstra's algorithm using a set for efficient minimum distance extraction.
        - Returns a vector of shortest distances from the source node to every other node.

    5. **dijkstraAlgorithmWithPriorityQueue(int src)**:
        - Another implementation of Dijkstra's algorithm using a priority queue.
        - Also returns a vector of shortest distances from the source node to every other node.
*/

class Graph
{
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add an edge between nodes `u` and `v` with weight `w`
    void addEdge(int u, int v, bool direction, int w)
    {
        // Create an edge from u to v
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
                cout << "  |-> Node " << v << " (weight: " << w << ")" << endl;
            }
            cout << endl;
        }
    }

    // Dijkstra's Algorithm using SET for efficient minimum distance extraction
    vector<int> dijkstraAlgorithm(int src)
    {
        set<pair<int, int>> s;
        vector<int> dist(13, INT_MAX); // Distance vector initialized to INT_MAX
        dist[src] = 0;                 // Distance to source is 0
        s.insert({0, src});

        while (!s.empty())
        {
            auto frontNode = *(s.begin());
            int nodeDistance = frontNode.first;
            int node = frontNode.second;
            s.erase(s.begin());

            // Traverse all adjacent nodes of the current node
            for (auto nbr : adj[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    auto record = s.find({dist[nbr.first], nbr.first});
                    if (record != s.end())
                    {
                        s.erase(record); // Remove the old distance if found
                    }
                    dist[nbr.first] = nodeDistance + nbr.second; // Update distance
                    s.insert({dist[nbr.first], nbr.first});
                }
            }
        }

        return dist; // Return the shortest path distances from the source
    }

    // Dijkstra's Algorithm using PRIORITY_QUEUE for efficient minimum distance extraction
    vector<int> dijkstraAlgorithmWithPriorityQueue(int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(13, INT_MAX); // Distance vector initialized to INT_MAX
        dist[src] = 0;                 // Distance to source is 0
        pq.push({0, src});

        while (!pq.empty())
        {
            auto frontNode = pq.top();
            int nodeDistance = frontNode.first;
            int node = frontNode.second;
            pq.pop();

            // Traverse all adjacent nodes of the current node
            for (auto nbr : adj[node])
            {
                if (nodeDistance + nbr.second < dist[nbr.first])
                {
                    dist[nbr.first] = nodeDistance + nbr.second; // Update distance
                    pq.push({dist[nbr.first], nbr.first});
                }
            }
        }

        return dist; // Return the shortest path distances from the source
    }
};

int main()
{
    Graph g;

    // Adding edges to the graph with specified weights
    g.addEdge(1, 2, false, 4);   // Node 1 to Node 2 with weight 4
    g.addEdge(1, 3, false, 2);   // Node 1 to Node 3 with weight 2
    g.addEdge(2, 4, false, 3);   // Node 2 to Node 4 with weight 3
    g.addEdge(2, 5, false, 7);   // Node 2 to Node 5 with weight 7
    g.addEdge(3, 6, false, 1);   // Node 3 to Node 6 with weight 1
    g.addEdge(3, 7, false, 3);   // Node 3 to Node 7 with weight 3
    g.addEdge(4, 8, false, 2);   // Node 4 to Node 8 with weight 2
    g.addEdge(5, 9, false, 4);   // Node 5 to Node 9 with weight 4
    g.addEdge(6, 10, false, 5);  // Node 6 to Node 10 with weight 5
    g.addEdge(7, 11, false, 6);  // Node 7 to Node 11 with weight 6
    g.addEdge(8, 12, false, 8);  // Node 8 to Node 12 with weight 8
    g.addEdge(9, 10, false, 7);  // Node 9 to Node 10 with weight 7
    g.addEdge(10, 11, false, 3); // Node 10 to Node 11 with weight 3
    g.addEdge(11, 12, false, 4); // Node 11 to Node 12 with weight 4
    g.addEdge(5, 12, false, 1);  // Node 5 to Node 12 with weight 1
    g.addEdge(6, 9, false, 2);   // Node 6 to Node 9 with weight 2

    // Print the adjacency list of the graph
    cout << "Adjacency List is " << endl;
    g.printList();
    cout << endl;

    // Get the source node from user input
    int src;
    cout << "Enter Source Node: ";
    cin >> src;
    cout << endl;

    // Compute shortest paths from the source node using Dijkstra's algorithm
    auto shortestPath = g.dijkstraAlgorithm(src);

    // Output the shortest path from the source node to all other nodes
    cout << "Shortest path from node " << src << ":" << endl;
    for (int i = 1; i <= 12; i++)
    {
        cout << "Node " << i << " : " << shortestPath[i] << endl;
    }

    return 0;
}
