
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
    void bellMenFordAlgorithm(int n, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // n-1 relaxation steps
        for (int i = 0;i < n - 1; i++)
        {
            //for all edges
            for (auto node : adjList)
            {
                for(auto nbr : node.second)
                {
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u]!=INT_MAX && dist[u] + wt  < dist[v])
                    {
                        dist[v] = dist[u] +wt;
                    }
                }

            }
            
        }
        cout<<"Printing Distance ARray : ";
        for(auto i : dist)
        {
            cout<<i<<" ";
        }
    }

    bool checkForNegCycle(int n, int src)
    {
         vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // n-1 relaxation steps
        for (int i = 0;i < n - 1; i++)
        {
            //for all edges
            for (auto node : adjList)
            {
                for(auto nbr : node.second)
                {
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u]!=INT_MAX && dist[u] + wt  < dist[v])
                    {
                        dist[v] = dist[u] +wt;
                    }
                }

            }
            
        }
        for (auto node : adjList)
            {
                for(auto nbr : node.second)
                {
                    int u = node.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u]!=INT_MAX && dist[u] + wt  < dist[v])
                        return true;
                }
            }
            return false;
    }
};

int main()
{
    graph g;

    g.addEdge(0, 1, -1, 0);
    g.addEdge(0, 2, 4, 0);
    g.addEdge(1, 2, 3, 0);

    g.addEdge(1, 3, 2, 0);
    g.addEdge(1, 4, 2, 0);
    g.addEdge(3, 1, 1, 0);

    g.addEdge(3, 2, 5, 0);
    g.addEdge(4, 3, -3, 0);


    g.printAdjList();
    g.bellMenFordAlgorithm(5,0);
    bool ans = g.checkForNegCycle(5,0);
    cout<<endl;
    ans==true?cout<<"Cycle Present":cout<<"cycle Absent";
    return 0;
}
