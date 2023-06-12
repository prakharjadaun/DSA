#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        if(s.size()==0)
            return true;

        int index = 0;
        //two pointers approach
        for(int i=0;i<t.size();i++)
        {
            if(s[index]==t[i])
            {
                index++;
                if(index==s.size())
                    return true;
            }
        }
        return false;
    }
};