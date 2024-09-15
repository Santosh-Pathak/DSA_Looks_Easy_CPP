#include <bits/stdc++.h>
using namespace std;

/*
    A* Algorithm for Pathfinding
    ----------------------------
    The A* algorithm is a popular and efficient pathfinding algorithm used to find the shortest path 
    from a start node to a goal node in a weighted graph. It combines features of Dijkstra's Algorithm 
    and Greedy Best-First Search.

    Data Structures:
    -----------------
    1. **Node**:
        - Represents a node in the graph during the A* search.
        - Contains the following properties:
          - `id`: The identifier of the node.
          - `parent`: The parent node in the path (for path reconstruction).
          - `g`: The cost from the start node to this node.
          - `h`: The heuristic estimate of the cost from this node to the goal.
          - `f`: The total estimated cost (g + h).

    2. **Priority Queue**:
        - Stores nodes based on their total estimated cost (`f`).
        - Nodes with the lowest `f` value are processed first.

    3. **Unordered Map**:
        - `gScores`: Maps each node to its cost from the start node.
        - `cameFrom`: Maps each node to its parent node in the path.

    Algorithm Steps:
    ----------------
    1. Initialize the priority queue with the start node.
    2. While the priority queue is not empty:
       a. Extract the node with the lowest `f` value.
       b. If this node is the goal, reconstruct and return the path.
       c. For each neighbor of this node, calculate the tentative `g` cost.
       d. If this tentative `g` cost is better than the previously known cost, update the node and add it to the priority queue.
    3. If the priority queue is empty and the goal has not been reached, return an empty path (no path found).
*/

// Structure to represent a node in the graph
struct Node {
    int id;            // Node identifier
    int parent;        // Parent node ID in the path
    int g;             // Cost from start node to this node
    int h;             // Heuristic cost estimate to goal
    int f;             // Total cost (g + h)

    Node(int id, int g, int h, int parent) : id(id), g(g), h(h), parent(parent) {
        f = g + h; // Total cost is the sum of g and h
    }
};

// Comparison function for the priority queue
struct Compare {
    bool operator()(const Node &n1, const Node &n2) {
        return n1.f > n2.f; // Priority queue gives priority to nodes with lower f values
    }
};

class Graph {
    unordered_map<int, vector<pair<int, int>>> adj; // Adjacency list: node -> (neighbor, cost)

public:
    // Add an edge to the graph
    void addEdge(int u, int v, int cost) {
        adj[u].push_back({v, cost});
    }

    // Heuristic function: here we use a simple Manhattan distance for demonstration
    int heuristic(int u, int goal) {
        return abs(u - goal); // Example heuristic
    }

    // A* Algorithm implementation
    vector<int> aStar(int start, int goal) {
        priority_queue<Node, vector<Node>, Compare> openSet; // Min-heap based on f value
        unordered_map<int, int> gScores; // gScores[node] = cost from start to node
        unordered_map<int, int> cameFrom; // cameFrom[node] = previous node in the optimal path

        // Initialize the priority queue with the start node
        openSet.push(Node(start, 0, heuristic(start, goal), -1));
        gScores[start] = 0;
        cameFrom[start] = -1;

        while (!openSet.empty()) {
            Node current = openSet.top();
            openSet.pop();

            if (current.id == goal) {
                // Reconstruct the path from goal to start
                vector<int> path;
                for (int node = goal; node != -1; node = cameFrom[node]) {
                    path.push_back(node);
                }
                reverse(path.begin(), path.end()); // Reverse the path to get the correct order
                return path;
            }

            // Explore neighbors
            for (auto &neighbor : adj[current.id]) {
                int next = neighbor.first; // Neighbor node
                int cost = neighbor.second; // Cost to reach this neighbor
                int tentative_g = current.g + cost; // Tentative cost from start to neighbor

                // If this path is better, update the cost and add the neighbor to the priority queue
                if (gScores.find(next) == gScores.end() || tentative_g < gScores[next]) {
                    gScores[next] = tentative_g;
                    int h = heuristic(next, goal);
                    openSet.push(Node(next, tentative_g, h, current.id));
                    cameFrom[next] = current.id;
                }
            }
        }

        // Return empty vector if no path is found
        return {};
    }
};

int main() {
    Graph g;

    // Add edges (node, neighbor, cost)
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 5);
    g.addEdge(3, 4, 1);

    int start = 1;
    int goal = 4;

    vector<int> path = g.aStar(start, goal);

    if (!path.empty()) {
        cout << "Path from " << start << " to " << goal << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}
