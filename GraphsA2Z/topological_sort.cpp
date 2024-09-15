#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation and Topological Sort in Directed Graph:
    ------------------------------------------------------------
    This program represents a directed graph using an **Adjacency List** and provides functionality
    for computing the topological sort of the graph using Depth-First Search (DFS).

    Data Structures Used:
    ----------------------
    1. **unordered_map<int, list<int>> adj**:
        - `adj` is an unordered map where each key represents a node (vertex), and the value is a list of integers.
          Each integer in the list represents a neighboring node.
        - This structure represents the adjacency list of the graph.

    Algorithms:
    -----------
    1. Topological Sort in Directed Graphs
    
    Definition:
    ------------
    Topological sorting (or topological order) of a Directed Acyclic Graph (DAG) is a linear ordering of its vertices
    such that for every directed edge \( uv \) from vertex \( u \) to vertex \( v \), \( u \) comes before \( v \) in the ordering.
    In simpler terms, it orders the vertices so that every directed edge goes from an earlier vertex to a later vertex in the sequence.

    Characteristics:
    -----------------
    - **Only for DAGs**: Topological sorting is only possible for Directed Acyclic Graphs. If the graph contains cycles, no topological ordering exists.
    - **Not Unique**: There can be multiple valid topological sorts for a given DAG.

    Applications:
    --------------
    - **Task Scheduling**: Determining the order of tasks given their dependencies.
    - **Course Prerequisites**: Finding an order to take courses where some courses are prerequisites for others.
    - **Build Systems**: In software build systems to resolve dependencies between various modules.

    Implementation Using DFS:
    ---------------------------
    Here’s a step-by-step explanation of how topological sort can be implemented using Depth-First Search (DFS) in C++:

    1. **DFS Traversal**: Perform DFS on the graph starting from each unvisited node.
    2. **Stack for Result**: Use a stack to store the nodes in the order of their finishing times. Nodes that are finished last are pushed to the stack first, which ensures that they appear first in the topological order.
    3. **Visit Each Node**: Mark nodes as visited to avoid processing the same node multiple times.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction)**:
        - Adds an edge between nodes `u` and `v`.
        - The `direction` parameter specifies whether the edge is directed (`1`) or undirected (`0`).

    2. **printList()**:
        - Prints the adjacency list of the graph, showing each node and its neighbors.

    3. **topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)**:
        - Computes the topological sort starting from node `src` using DFS.
        - Marks nodes as visited and pushes them onto a stack in reverse finish order.
*/

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    // Method to add an edge to the graph
    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 => undirected graph
        // direction = 1 => directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        // If the graph is undirected, add an edge from v to u as well
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    // Method to print the adjacency list of the graph
    void printList()
    {
        for (auto x : adj)
        {
            cout << x.first << "->";
            auto list = x.second;
            for (auto y : list)
            {
                cout << y << " , ";
            }
            cout << endl;
        }
    }

    // Method to perform topological sort using DFS
    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)
    {
        // Mark the current node as visited
        visited[src] = true;

        // Recur for all adjacent nodes of the current node
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
            {
                topologicalSortDFS(nbr, visited, s);
            }
        }

        // Push the current node to stack which stores the result
        s.push(src);
    }
};

int main()
{
    Graph g;

    // Adding directed edges to the graph
    g.addEdge(1, 2, 1);   // Edge from 1 to 2
    g.addEdge(1, 3, 1);   // Edge from 1 to 3
    g.addEdge(2, 4, 1);   // Edge from 2 to 4
    g.addEdge(2, 5, 1);   // Edge from 2 to 5
    g.addEdge(3, 6, 1);   // Edge from 3 to 6
    g.addEdge(3, 7, 1);   // Edge from 3 to 7
    g.addEdge(4, 8, 1);   // Edge from 4 to 8
    g.addEdge(5, 9, 1);   // Edge from 5 to 9
    g.addEdge(6, 10, 1);  // Edge from 6 to 10
    g.addEdge(7, 11, 1);  // Edge from 7 to 11
    g.addEdge(8, 12, 1);  // Edge from 8 to 12
    g.addEdge(9, 10, 1);  // Edge from 9 to 10
    g.addEdge(10, 11, 1); // Edge from 10 to 11
    g.addEdge(11, 12, 1); // Edge from 11 to 12

    // Print the adjacency list representation of the graph
    cout << "Printing Adjacency List : " << endl;
    g.printList();

    // Perform topological sort using DFS
    unordered_map<int, bool> visited; // To keep track of visited nodes
    stack<int> s; // Stack to store the result of topological sort

    // Iterate through all nodes and perform DFS if the node is not visited
    for (int i = 1; i <= 12; i++)
    {
        if (!visited[i])
        {
            g.topologicalSortDFS(i, visited, s);
        }
    }

    // Extract nodes from the stack to get the topologically sorted order
    vector<int> sortedArray;
    while (!s.empty())
    {
        sortedArray.push_back(s.top());
        s.pop();
    }

    // Print the topologically sorted nodes
    cout << "Topological Sort is " << endl;
    for (auto x : sortedArray)
    {
        cout << x << " "; // Print each node in topologically sorted order
    }
}
