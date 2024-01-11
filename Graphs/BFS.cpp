// 2-> implementation of Graph using Adjacency List
#include <iostream>
#include <vector>
#include <unordered_map>
#include<queue>
using namespace std;
template <typename T>

class Graph
{
public:
    unordered_map<T, vector<T>> adjList;
    void addEdge(T u, T v, bool direction)
    {
        // direction == 0 -> undirected graph
        // direction == 1 -> directed graph
        // create an edge from u to v
        adjList[u].push_back(v);
        if (direction == 0)
        {
            // create an edge from v to u for an undirected graph
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
    queue<T>q;
    unordered_map<T,bool>visited;

    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
          int frontNode = q.front();
        q.pop();
        cout<<frontNode <<" , ";
        // insert all neighbour into queue
        for(auto x : adjList[frontNode])
        {
            if(visited.find(x)==visited.end())
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
unordered_map<int,bool>visited;
void dfs(int src ,unordered_map<int,bool>&visited)
{
    cout<<src<<" , ";
    visited[src] =true;
    for(auto neighbour : adjList[src])
    {
            if (!visited[neighbour])
            {
                dfs(neighbour,visited);
            }
    }
}


};

int main()
{
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
    cout<<"Breadth First Traversal : "<<endl;
    g.bfs(0);
    cout << endl; 
    cout<<"Depth First Traversal : "<<endl;
    unordered_map<int,bool>visited;
    g.dfs(0,visited);

    // Undirected Input
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // g.printAdjacency();
    // cout << endl; 
    // Directed Input
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(0, 2, 1);
    // g.printAdjacency();
    // return 0;

}
