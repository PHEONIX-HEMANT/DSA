#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost, int ind)
{
    if(ind==0 || ind==1)
        return cost[0];
    
    int one_step = cost[ind] + minCostClimbingStairs(cost, ind-1);
    int two_step = cost[ind] + minCostClimbingStairs(cost, ind-2);

    return min(one_step, two_step);
}

int main()
{
    int c;
    vector<int> cost;
    while(cin>>c){
        cost.push_back(c);
    }
    
    cout<<minCostClimbingStairs(cost, cost.size()-1)<<endl;
    return 0;
}