shortest path algorithms are used in finding the shortest possible path btw two vertices of a given graph having edge weights.

if graph is unweighted or has edges with equal weights, then a "slight modification of BFS" can give us the ans.

But, if graph has edges with different weights, then there are 3 algorithms to find SPA,
    (i)     Bellman Ford's Algorithm
    (ii)    Floyd Warshall's Algorithm
    (iii)   Djikstra's Algorithm


We will see all the algorithms here,

1.BFS



2.Bellman Ford's Algorithm :

    Use Case : It is used to find the shortest distance of all vertices from source vertex.

    Intution : Shortest Path can contain atmost n-1 edges, because the shortest path cant have a cycle.

    Algorithm:
        (i) Outer loop traverse from 0 to n-1
        (ii) Loop over all edges, check if the "next node distance > current node distance + edge weight", 
            in this case update the next node distance to "current node distance + edge weight". 

    This algorithm depends on the relaxation principle where the shortest distance for all vertices is gradually replaced by more accurate values until eventually reaching the optimum solution. In the beginning all vertices have a distance of "Infinity", but only the distance of the source vertex = 0, then update all the connected vertices with the new distances (source vertex distance + edge weights), then apply the same concept for the new vertices with new distances and so on. 

    
    A very important application of Bellman Ford is to check if there is a negative cycle in the graph.

    Analysis:
        TC : O(V.E) // very high
        SC : O(V)


3.Floyd Warshall's Algorithm :

