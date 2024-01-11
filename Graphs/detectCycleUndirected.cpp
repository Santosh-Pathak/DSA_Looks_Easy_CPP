#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T>
class Graph {
public:
    unordered_map<T, vector<T>> adjList;

    void addEdge(T u, T v, bool direction) {
        adjList[u].push_back(v);
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjacency() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto x : node.second)
                cout << x << " , ";
            cout << endl;
        }
    }

    void bfs(T src) {
        queue<T> q;
        unordered_map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " , ";

            for (auto x : adjList[frontNode]) {
                if (visited.find(x) == visited.end()) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited) {
        cout << src << " , ";
        visited[src] = true;
        for (auto neighbour : adjList[src]) {
            if (!visited[neighbour]) {
                dfs(neighbour, visited);
            }
        }
    }

    bool checkCycleUsingBfs(T src, unordered_map<T, bool> &visited) {
        queue<T> q;
        unordered_map<T, T> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = src;

        while (!q.empty()) {
            T frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                } else {
                    if (nbr != parent[frontNode]) {
                        return true; // cycle present
                    }
                }
            }
        }
        return false;
    }

    bool checkCycleUsingDFS(T src, unordered_map<T, bool> &visited, T parent) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                bool checkAgeKaAnswer = checkCycleUsingDFS(nbr, visited, src);
                if (checkAgeKaAnswer)
                    return true;
            }
            else if (visited[nbr] && nbr != parent)
                return true; // Cycle Present
        }
        return false;
    }
};

int main() {
    Graph<int> g;

    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(3, 5, 0);
    g.addEdge(3, 7, 0);
    g.addEdge(7, 6, 0);
    g.addEdge(7, 4, 0);

    g.printAdjacency();
    cout << endl;
    
    cout << "Breadth First Traversal: " << endl;
    g.bfs(0);
    cout << endl;

    int n = 8; // Number of nodes in the graph
    unordered_map<int, bool> visitedBFS;

    bool ansBFS = false;
    for (int i = 0; i < n; i++) {
        if (!visitedBFS[i]) {
            ansBFS = g.checkCycleUsingBfs(i, visitedBFS);
            if (ansBFS)
                break;
        }
    }
    if (ansBFS)
        cout << "Cycle is Present Using BFS" << endl;
    else
        cout << "Cycle Absent Using BFS" << endl;

    unordered_map<int, bool> visitedDFS;

    bool ansDFS = false;
    for (int i = 0; i < n; i++) {
        if (!visitedDFS[i]) {
            ansDFS = g.checkCycleUsingDFS(i, visitedDFS, -1);
            if (ansDFS)
                break;
        }
    }
    if (ansDFS)
        cout << "Cycle is Present Using DFS" << endl;
    else
        cout << "Cycle Absent Using DFS" << endl;

    return 0;
}
 