#include<vector>
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) 
    {
        vector<int> fre1(26,0),fre2(26,0);
        for(char ch : word1)
            fre1[ch-'a']++;
        for(char ch : word2)
            fre2[ch -'a']++;
        
        int count = 0;

        for(int i=0;i<26;i++)
        {
            count = abs(fre1[i]-fre2[i]);
            if(count > 3)
                return false;
        }
        return true;

    }
};