#include<bits/stdc++.h>
using namespace std;

int check(string s, int n)
{
    if(n==1)
        return 0;
    
    int c1 = -1, c2 = -1, c3 = -1, cnt=0;
    // for(auto& ch : s)
    //     if(ch == '1')
    //         c1++;

    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            cnt++;
            if(c1==-1)
                c1 = n-1-i;
            else if(c2 == -1)
                c2 = n-1-i;
            else if(c3 == -1)
                c3 = n-1-i;
        }
    }

    
    if(c>3)
        return 0;

    if(c == 3)
        return 1;

}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        if(check(s, n)==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

// 4
// 1
// 1
// 4
// 1001
// 6
// 110001
// 8
// 11011011


// NO
// YES
// YES
// NO