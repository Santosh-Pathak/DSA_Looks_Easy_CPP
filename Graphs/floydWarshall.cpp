
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <limits.h>
using namespace std;

class graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        // direction = 1 -> undirected graph
        // direction => 0 -> directed graph;
        adjList[u].push_back({v, wt});
        if (direction == 1)
        {
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }
            cout << endl;
        }
    }
    
    void floydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // diagonal elements ko 0 kr do
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (auto node : adjList)
        {
            for (auto nbr : node.second)
            {
                int u = node.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        for (int  helper = 0; helper < n; helper++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    dist[i][j] = min(dist[i][j] , dist[i][helper]+dist[helper][j]);
                }
       
            }
        
        }
        cout<<"Priting Dustance Arrays :"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
};

int main()
{
    graph g;

    g.addEdge(0 ,1, 3, 0);
    g.addEdge(0, 3, 5, 0);
    g.addEdge(1, 0, 2, 0);

    g.addEdge(1, 3, 4, 0);
    g.addEdge(2, 1, 1, 0);
    g.addEdge(3, 2, 2, 0);

    g.printAdjList();
    g.floydWarshall(4);
}
