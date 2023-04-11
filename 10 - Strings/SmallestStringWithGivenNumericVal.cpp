#include<iostream>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string res(n,'a');
        k = k - n;
        while(k>0)
        {
            res[--n] += min(25,k);
            k -= min(25,k);
        }    
        return res;
    }
};