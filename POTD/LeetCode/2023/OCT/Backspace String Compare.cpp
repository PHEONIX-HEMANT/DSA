#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool approach1(string s, string t)
    {
        stack<char> s1, s2;
        for(auto& ch:s)
        {
            if(ch=='#')
            {
                if(!s1.empty())
                    s1.pop();
            }
            else
                s1.push(ch);
        }

        for(auto& ch:t)
        {
            if(ch=='#')
            {
                if(!s2.empty())
                    s2.pop();
            }
            else
                s2.push(ch);
        }

        if(s1.size() != s2.size())
            return false;
        
        while(!s1.empty() && !s2.empty())
        {
            char ch1 = s1.top();
            char ch2 = s2.top();
            s1.pop();
            s2.pop();

            if(ch1 != ch2)
                return false;
        }

        return true;
    }

    bool approach2(string s, string t)
    {
        int ind = 0;
        while(ind < s.size())
        {
            if(s[ind]=='#')
            {
                if(ind>0)
                {
                    ind--;
                    s.erase(s.begin()+ind, s.begin()+ind+2);
                }
                else
                    s.erase(s.begin()+ind);
            }
            else
                ind++;
        }

        ind = 0;
        while(ind < t.size())
        {
            if(t[ind]=='#')
            {
                if(ind>0)
                {
                    ind--;
                    t.erase(t.begin()+ind, t.begin()+ind+2);
                }
                else
                    t.erase(t.begin()+ind);
            }
            else
                ind++;
        }

        return s==t?true:false;
    }
    bool backspaceCompare(string s, string t) {
        //return approach1(s,t);
        return approach2(s,t);
    }
};

int main()
{
    string s, t;
    cin >> s >> t;
    Solution obj;
    bool ans = obj.backspaceCompare(s,t);
    if(ans) cout<<"true"<<endl;
    else    cout<<"false"<<endl;
    return 0;
}