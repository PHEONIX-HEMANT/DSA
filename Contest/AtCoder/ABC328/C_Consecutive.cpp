#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;

    vector<int> dp(n, 0);
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            dp[i] = dp[i-1]+1;
        else
            dp[i] = dp[i-1];
    }

    while(q--)
    {
        int i,j;
        cin>>i>>j;
        cout<<dp[j-1]-dp[i-1]<<endl;
    }
}