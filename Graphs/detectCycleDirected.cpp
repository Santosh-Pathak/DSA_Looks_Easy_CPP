#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, vector<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        adjList[u].push_back(v);
        if (direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void printAdjacency()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto x : node.second)
                cout << x << " , ";
            cout << endl;
        }
    }

    void bfs(T src)
    {
        queue<T> q;
        unordered_map<T, bool> visited;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << " , ";

            for (auto x : adjList[frontNode])
            {
                if (visited.find(x) == visited.end())
                {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << " , ";
        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }

    bool checkCyclicDirectedGraphUsingDfs(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> dfsVisited)
    {

        visited[src] = true;
        dfsVisited[src] = true;

        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
            {
                bool aageKaAnswer = checkCyclicDirectedGraphUsingDfs(nbr, visited, dfsVisited);
                if (aageKaAnswer == true)
                    return true;
            }
            if (visited[nbr] == true && dfsVisited[nbr] == true)
            {
                return true;
            }
        }
        // yaha hi galti hoti h
        dfsVisited[src] = false;
        return false;
    }
    //TOPOLOGIVAL SORT VIA DFS ALGORITHM
    void topologicalSort(T src, unordered_map<T, bool> &visited, stack<int> &ans)
    {
        // cout << src << " , ";
        visited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                topologicalSort(neighbour, visited, ans);
            }
        }
        // whilw returning store the node
        ans.push(src);
    }

    void topologicalSortBFS(int n, vector<int> &ans) //Kahn's ALgorithm
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        // sabki indregree calculate kro
        for (auto i : adjList)
        {
            // int src = i.first;
            for (auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all nodes inside queue ehich has indegree ==0
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        // bfs concept
        while (!q.empty())
        {
            int fNode = q.front();
            q.pop();
            // cout>>fNode<<" ";
            ans.push_back(fNode);
            for (auto nbr : adjList[fNode])
            {
                indegree[nbr]--;
                // check for zero indree again
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;

    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(3, 5, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(6, 7, 1);
    // g.addEdge(4, 0, 1);

    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);
    g.printAdjacency();
    cout << endl;

    cout << "Breadth First Traversal: " << endl;
    g.bfs(2);
    cout << endl;

    int n = 8; // Number of nodes in the graph

    // unordered_map<int, bool> visited;
    // unordered_map<int, bool> dfsvisited;
    // bool ansDFS = false;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ansDFS = g.checkCyclicDirectedGraphUsingDfs(i, visited, dfsvisited);
    //         if (ansDFS)
    //             break;
    //     }
    // }
    // if (ansDFS)
    //     cout << "Cycle is Present Using DFS" << endl;
    // else
    //     cout << "Cycle Absent Using DFS" << endl;
    cout << endl;
    //      << " Topological Sort " << endl;
    // unordered_map<int, bool> visited;
    // stack<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         g.topologicalSort(i, visited, ans);
    //     }
    // }
    // while (!ans.empty())
    // {
    //     cout << ans.top() << " , ";
    //     ans.pop();
    // }

    vector<int> ans;
    // connected or disconnected
    g.topologicalSortBFS(n, ans);

    cout << "TOPOLOGICAL SORT BY BFS " << endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
