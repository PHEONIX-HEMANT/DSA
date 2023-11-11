#include<bits/stdc++.h>
using namespace std;

vector<int> fillVector(int n)
{
    vector<int> ans;

    while(n)
    {
        int digit = n%10;
        n /= 10;
        ans.push_back(digit);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int func(vector<int>& num, int i, bool flag, long prod, int p)
{
    if(i == num.size())
        return prod%p==0;
    
    int ans = 0;
    if(flag)
    {
        for(int digit=0;digit<=9;digit++)
            ans += func(num, i+1, true, prod*digit, p);
    }
    else{
        for(int digit=0;digit<=num[i];digit++)
        {
            if(digit<num[i])
            {
                ans += func(num, i+1, true, prod*digit, p);
            }
            else{
                ans += func(num, i+1, false, prod*digit, p);
            }
        }
    }

    return ans;
}

int f(int x, int p)
{
    vector<int> num;
    num = fillVector(x);
    int res = func(num, 0, false, 1, p);
    return res;
}
int solve(int l, int r, int p)
{
    int res1 = f(r,p);
    int res2 = f(l-1, p);

    return res1 - res2;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        int p;
        cin>>l>>r>>p;
        cout<<solve(l,r,p)<<endl;
    }
}