#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<=x)
            res+=arr[i];
    }
    
    cout<<res<<endl;
    return 0;
}