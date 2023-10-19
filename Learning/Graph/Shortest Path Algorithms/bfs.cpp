/*
    BFS can be applied to get shortest path between two vertices if all edge weights are equal.
    If edge weights are different, bfs doesnt work.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findShortestPath(vector<int>& adj[], int src, int v, int wt)
{
    vector<vector<int>> dist(v, vector<int>(v, INT_MAX));
    queue<int> q;
    q.push(src);

}

int main()
{
    int v;
    cin>>v;
    vector<int> adj[v];

    int e;  cin>>e;
    for(int i=0;i<e;i++)
    {
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b,wt);
        adj[b].push_back(a);
    }
    int wt;
    cin>>wt;

    vector<vector<int>> ans = findShortestPath(adj, 0, v, wt);
    return 0;
}