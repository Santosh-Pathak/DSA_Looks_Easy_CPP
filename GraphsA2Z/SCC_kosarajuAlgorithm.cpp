#include <bits/stdc++.h>
using namespace std;

/*
    Graph Representation and Algorithms:
    -------------------------------------
    This program represents a directed weighted graph using an **Adjacency List**.
    The graph is implemented as a class that supports adding edges, printing the adjacency list,
    providing a graphical-like representation, and identifying Strongly Connected Components (SCCs)
    using **Kosaraju's Algorithm**.

    Data Structures Used:
    ---------------------
    1. **unordered_map<int, list<pair<int, int>>> adj**:
        - `adj` is an unordered map where each key is a node (vertex), and the value is a list of pairs representing
          neighboring nodes and the weights of the edges.
        - This represents the adjacency list of the graph.

    Algorithms:
    -----------
    1. **Topological Sort using DFS**:
        - This function orders nodes such that for every directed edge UV from node U to node V, U comes before V.

    2. **Transpose of Graph**:
        - This function reverses the direction of every edge in the graph.

    3. **Kosaraju's Algorithm**:
        - This algorithm finds all Strongly Connected Components (SCCs) in a directed graph.
        - It involves three main steps: Topological sorting, transposing the graph, and performing DFS on the transposed graph.

    Functionality:
    --------------
    1. **addEdge(int u, int v, bool direction, int w)**:
        - Adds a directed weighted edge from node `u` to node `v` with weight `w`.

    2. **printList()**:
        - Prints the adjacency list for each node, showing each connection along with its weight.

    3. **printGraphically()**:
        - Provides a graphical-like representation of the graph, showing each node and its connections.

    4. **topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)**:
        - Performs a Depth-First Search (DFS) to determine the topological order of nodes.

    5. **transPoseGraph(unordered_map<int, list<pair<int, int>>> &transAdj)**:
        - Creates the transpose (reverse) of the graph.

    6. **dfs(int src, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, list<pair<int, int>>> &transAdj)**:
        - Performs a Depth-First Search (DFS) on the transposed graph to identify nodes in the same SCC.

    7. **countStronglyConnectedComponents(int n)**:
        - Uses Kosaraju's Algorithm to find all Strongly Connected Components in the graph.
*/

class Graph
{
public:
    // Adjacency list representation using an unordered_map
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add a directed weighted edge between nodes `u` and `v`
    void addEdge(int u, int v, bool direction, int w)
    {
        // Create a directed edge from u to v with weight w
        adj[u].push_back({v, w});

        // If undirected (direction == 0), also create an edge from v to u with the same weight
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
                cout << "(" << y.first << ", " << y.second << ") "; // Print each neighbor and weight
            }
            cout << endl;
        }
    }

    // Function to print a graphical-like representation of the graph
    void printGraphically()
    {
        cout << "Graphical Representation of the Graph:" << endl;
        for (auto x : adj)
        {
            int u = x.first;
            cout << "Node " << u << ":\n"; // Print the current node
            for (auto y : x.second)
            {
                int v = y.first;
                int w = y.second;
                cout << "  |-> " << "Node " << v << " (weight: " << w << ")" << endl;
            }
            cout << endl;
        }
    }

    // Function to perform DFS for topological sorting
    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &s)
    {
        visited[src] = true; // Mark the current node as visited
        for (auto nbr : adj[src])
        {
            if (!visited[nbr.first])
            {
                topologicalSortDFS(nbr.first, visited, s); // Recursively visit neighbors
            }
        }
        s.push(src); // Push the current node onto the stack after visiting all neighbors
    }

    // Function to transpose (reverse) the graph
    void transPoseGraph(unordered_map<int, list<pair<int, int>>> &transAdj)
    {
        for (auto x : adj)
        {
            int u = x.first;
            for (auto s : x.second)
            {
                int v = s.first;
                int w = s.second;

                transAdj[v].push_back({u, w}); // Reverse the direction of the edge
            }
        }
    }

    // Function to perform DFS on the transposed graph to find SCCs
    void dfs(int src, vector<int> &ans, unordered_map<int, bool> &visited, unordered_map<int, list<pair<int, int>>> &transAdj)
    {
        visited[src] = true; // Mark the current node as visited
        ans.push_back(src);  // Add the node to the current SCC
        for (auto nbr : transAdj[src])
        {
            if (!visited[nbr.first])
            {
                dfs(nbr.first, ans, visited, transAdj); // Recursively visit neighbors
            }
        }
    }

    // Function to find all Strongly Connected Components (SCCs) in the graph using Kosaraju's Algorithm
    vector<vector<int>> countStronglyConnectedComponents(int n)
    {
        stack<int> st; // Stack to store the order of nodes for the second DFS
        unordered_map<int, bool> visited;

        // Step 1: Topological sort
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                topologicalSortDFS(i, visited, st);
            }
        }

        // Step 2: Transpose the graph
        unordered_map<int, list<pair<int, int>>> transAdj;
        transPoseGraph(transAdj);

        // Step 3: Perform DFS on the transposed graph in the order of the stack
        vector<vector<int>> result; // Store the SCCs
        visited.clear();            // Reset the visited map

        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            if (!visited[node])
            {
                vector<int> ans;
                dfs(node, ans, visited, transAdj); // Find the SCC containing the current node
                result.push_back(ans);             // Add the SCC to the result
            }
        }

        return result; // Return the list of SCCs
    }
};

int main()
{
    Graph g;
    int n = 12; // Number of nodes

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

    cout << "Adjacency List is " << endl;
    g.printList();
    cout << endl;

    // Find and print all strongly connected components
    vector<vector<int>> scc = g.countStronglyConnectedComponents(n);

    cout << "Strongly Connected Components:" << endl;
    for (const auto &component : scc)
    {
        for (int node : component)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
