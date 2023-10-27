#include<iostream>
#include<vector>
using namespace std;

int m = 1e9+7;


long long nCr(int n, int r)
{
    if(n<r)
        return 0;
    
    if(n==0 || n==1)
        return 1;
    
    long long ans = 1;
    for(int i=0;i<r;i++)
    {
        ans = ans*(n-i);
        ans = ans/(i+1);
    }

    return ans;
}

long NumberOfWays(int* a, int n)
{
    int l=-1;
    bool flag = false;

    long cnt = 1;

    if(a[n-1]==0)
        return -1;

    for(int i=0;i<n;i++)
    {
        // cout<<a[i]<<" ";
        if(a[i]!=0 && l!=i)
        {
            if(flag){
                int range = i-l-1;
                int N = (l==-1)?a[i]-1:a[i]-a[l]-1;
                cnt = (cnt * nCr(N, range))%m;

                flag = false;
            }
            l=i;
        }
		else
			flag = true;
    }

    return cnt;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout<<NumberOfWays(a, n)<<endl;
        
    }
    
    return 0;
}