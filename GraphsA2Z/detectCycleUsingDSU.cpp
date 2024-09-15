//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    vector<int>rank;
    vector<int>parent;

    // Find function with path compression
    int findParent(int x)
    {
        if(parent[x] == x) return x;
        // Path compression step
        return parent[x] = findParent(parent[x]);
    }

    // Union by rank
    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if(rank[u] < rank[v])
            parent[u] = v;
        else if(rank[v] < rank[u])
            parent[v] = u;
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }

    int detectCycle(int V, vector<int> adj[])
    {
        // Resize parent and rank vectors to accommodate V nodes
        parent.resize(V);
        rank.resize(V);

        // Initialize parent and rank
        for(int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        // Iterate over all edges
        for(int u = 0; u < V; u++)
        {
            for(int v : adj[u])
            {
                // To avoid checking the same edge twice (for undirected graph)
                if(u < v)
                {
                    int parentU = findParent(u);
                    int parentV = findParent(v);
                    // If parents are the same, a cycle is found
                    if(parentU == parentV) return 1;
                    unionSet(u, v);
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends