#include<iostream>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        string res = "";
        int openBracket = 0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                openBracket++;
            else 
                openBracket--;
            
            if(s[i]=='(' && openBracket!=1)
                res+=s[i];
            else if(s[i]==')' && openBracket!=0)
                res+=s[i];
        }
        return res;
    }
};