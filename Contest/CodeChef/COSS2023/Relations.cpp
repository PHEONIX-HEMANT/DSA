#include<bits/stdc++.h>
using namespace std;

int prop1(vector<vector<int>> vec, int n)
{
    unordered_set<int> s;
    int cnt = 0; //cnt of diff elements
    for(int i=0;i<n;i++)
    {
        int x = vec[i][0];
        int y = vec[i][0];

        if(x==y)
            s.insert(x);
        else
        {
            cnt++;
            s.insert(x);
            s.insert(y);
        }
    }

    if(s.size()-cnt==n)
        return 1;
    else
        return 0;
}

int prop2(vector<vector<int>> vec, int n)
{
    // unordered_set<vector<int>> s;
    // int cnt = 0; // cnt of x==y
    // int pairs = 0;
    // for(auto& v:vec)
    // {
    //     int x = p[0], y = p[1];

    //     if(x!=y){
    //         vector<int> v{y,x};
    //         if(s.find(v) == s.end())
    //             s.insert(p);
    //         else
    //             pairs++;
    //     }
    // }

    // return 2*pairs;

    return 0;

}

int prop3(vector<vector<int>> vec, int n)
{
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        vector<vector<int>> vec;
        for(int i=0;i<n;i++)
        {
            int a;  cin>>a;
            int b;  cin>>b;

            vec.push_back({a,b});
        }

        if(prop1(vec, n))
            cout<<"YES"<<" ";
        else
            cout<<"NO"<<" ";

        cout<<prop2(vec, n)<< " ";
        cout<<prop3(vec, n)<< " ";

        cout<<endl;
    }
}