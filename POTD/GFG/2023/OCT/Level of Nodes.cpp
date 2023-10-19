/*
    Given an integer X and an undirected acyclic graph with V nodes, labeled from 0 to V-1, and E edges, find the level of node labeled as X.

    Level is the minimum number of edges you must travel from the node 0 to some target.

    If there doesn't exists such a node that is labeled as X, return -1.
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    queue<pair<int, int>>q;
	    vector<int> vis(V,0);
	    q.push({0,0});
	    vis[0]=0;
	    
	    while(!q.empty())
	    {
	        auto p = q.front();
	        q.pop();
	        
	        int node = p.first;
	        int dist = p.second;
	        
	        if(node == X)
	            return dist;
	        
	        for(auto& adjNode : adj[node])
	        {
	            if(vis[adjNode]==0){
	                q.push({adjNode, dist+1});
	                vis[adjNode]=1;
	            }
	        }
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends