#include<bits/stdc++.h>
using namespace std;

string solve(string s)
{
    stack<char> st;
    int prevA = -1, prevB = -1, prevC = -1;
    for(int i=0;i<s.length();i++)
    {
        char ch = s[i];
        if(ch != 'C' || st.empty() || st.size()==1)
            st.push(ch);
        else
        {
            if(st.top()=='B')
            {
                st.pop();
                if(st.top()=='A')
                    st.pop();
                else{
                    st.push('B');
                    st.push('C');
                }
            }
            else
                st.push('C');
        }
    }

    string str;
    while(!st.empty())
    {
        char ch = st.top();
        st.pop();
        str.push_back(ch);
    }

    if(str.empty())   return str;

    reverse(str.begin(), str.end());
    return str;
}

int main()
{
    string s;
    cin>>s;

    cout<<solve(s)<<endl;
}