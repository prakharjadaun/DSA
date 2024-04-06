#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int open = 0;
        for(int i=0;i<s.size();i++)    
        {
            if(s[i]=='(')
                open++;
            else if(s[i]==')')
                open--;

            if(open<0)
                s[i]='*', open++;
        }

        int close = 0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='(')
                close--;
            else if(s[i]==')')
                close++;
            
            if(close<0)
                s[i]='*', close++;
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};