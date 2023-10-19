//Brute force
/*
    Check all permutations of sequence of vertices.
        if in a sequence,
            - there does not exist a edge between a vertex and its adjacent, check for next sequence
            - If all vertices in the sequence have edges with their adjacent, its a hamiltonian path

    If all permuataions tried out, and still didnt find any hamiltonian path, that means the graph does not contain it.

    Analysis:
        TC - O(N! * N)
            N!  ->  generating all permutations
            N   ->  checking each permutation whether it can be a hamiltonian path or not.

        SC - O(N) 
            N   ->  Storing the sequence of vertices

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> HamiltonianPath(vector<vector<int>> adj, int v)
{
    vector<int> vec;    //to store the sequence of vertices
    for(int i=0;i<v;i++)
        vec.push_back(i);

    do{
        bool flag = false;
        for(int i=0;i<v-1;i++)
            if(adj[vec[i]][vec[i+1]]==0)
            {
                flag = true;
                break;
            }
        
        if(flag==false) //we found the hamiltonian path
            return vec;
        
    }while(next_permutation(vec.begin(), vec.end()));

    return {};
}

int main()
{
    int v;  //no. of vertices
    cin>>v;
    int e;  //no. of edges
    cin>>e;

    vector<vector<int>> adjMat(v, vector<int>(v,0));

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        adjMat[a][b]=1;
        adjMat[b][a]=1;
    }

    vector<int> path = HamiltonianPath(adjMat, v);
    if(path.empty())
        cout<<"Hamiltonian Path does not exist."<<endl;
    else
    {
        for(auto& vertex : path)
            cout<<vertex<<" ";
        cout<<endl;
    }
    return 0;
}