
# 1. Cloudy Days

## Problem Statement
    Alice is navigating the country of Cloudland on a cloudy day, making it challenging to see her way. She has a car with k units of fuel remaining, where each unit of fuel allows her to travel a distance of 1 unit.

    Given the country's layout, consisting of several interconnected cities, and her current location, your task is to determine and print the total possible number of cities she can visit reach if she exhausts all her fuel.


## Input format
    The input starts with three integers:
    v : The number of cities in Cloudland.
    e : The number of roads connecting differenct cities in Cloudland
    k : The remaining fuel units in Alice's car.
    src: Alice's current city

    The following M lines describe the road connections between cities as pairs of integers (u,v), indicating a bidirectional road between cities u and v.


## Output format
    Output a single integer representing the total possible number of cities Alice can reach if she uses up all K units of her fuel.


```cpp
#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second

int solver(vector<int> adj[], int v, int e, int k, int src)
{
    vector<int> vis(v+1,0);
    queue<pair<int,int>> q;
    q.push({src,k});
    vis[src]=1;

    int res = 1;

    while(!q.empty())
    {
        int node = q.front().f;
        int fuel = q.front().s;
        q.pop();

        if(fuel==0)
            continue;
        
        for(auto& adjNode : adj[node])
        {
            if(vis[adjNode]==0)
            {
                q.push({adjNode, fuel-1});
                vis[adjNode]=1;
                res++;
            }
        }
    }

    return res;
}

int main()
{
    int v, e, k, src;
    cin>>v>>e>>k>>src;

    vector<int> adj[v+1];
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<solver(adj, v, e, k, src)<<endl;
}
```