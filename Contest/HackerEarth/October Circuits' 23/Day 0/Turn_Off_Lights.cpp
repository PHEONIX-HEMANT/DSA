#include<iostream>
using namespace std;

int cntOps(string s, int n, int l)
{
    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]-'0'==1)
        {
            int ind = min(n-1, i+l-1);
            i = ind;
            res++;
        }
    }

    return res;
}
int calc(string s, int n, int k)
{
    int lo = 1, hi = n;
    int ans = -1;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        int cnt = cntOps(s, n, mid);

        if(cnt <= k)
        {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }

    return ans;
}

int main()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    cout<<calc(s, n, k)<<endl;
    return 0;
}