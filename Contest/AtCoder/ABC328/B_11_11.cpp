#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int dates = 0;

    for(int i=0;i<n;i++)
    {
        int month = i+1;
        if(month>9 && month%11!=0) continue;

        int days = arr[i];

        if(month%11!=0 && days<month)   continue;
        
        if(month<=9)
        {
            if(days >= month*11)
                dates += 2;
            else
                dates += 1;
        }
        else
        {
            int d = month/11;
            if(days >= d*11)
                dates += 2;
            else if(days >= d)
                dates += 1;
        }
    }
    cout<<dates<<endl;
    return 0;
}