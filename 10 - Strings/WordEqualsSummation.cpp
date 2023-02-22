#include<iostream>
using namespace std;
class Solution {
public:
    int convert(string s)
    {
        int ans = 0;
        for(int i=0;i<s.size();i++)
        {
            ans = ans*10 + s[i] - 'a';
        }
        return ans;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) 
    {
        if(convert(firstWord) + convert(secondWord) == convert(targetWord))
            return true;
        return false;    
    }
};