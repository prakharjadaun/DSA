#include<iostream>
using namespace std;
#include<climits>
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int max_depth = INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
            {
                if(i-1 >=0 && s[i-1]=='(')
                {
                    if(count > max_depth)
                    {
                        max_depth = count;
                    }
                }
                count--;

            }
            else 
            {
                if(count > max_depth)
                {
                    max_depth = count;
                }
            }
        }
        if(max_depth == INT_MIN)
            return 1;
        return max_depth;
    }
};