#include<iostream>

using namespace std;

int32_t main()
{
    int n, p ,k;
    cin>>n>>p>>k;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x = (a[i]+a[j])%p;
            int y = (a[i]*a[i])%p + (a[j]*a[j])%p;

            if((x*y)%p == k%p)
                cnt++;
        }
    }

    cout<<cnt<<endl;
    
    return 0;
}