#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    
    string getHint(string secret, string guess) 
    {
        int bulls = 0;
        int cows = 0;
        int i=0;
        unordered_map<char,int> s,g;
        while(i<secret.size())    
        {
            s[secret[i]]++;
            g[guess[i]]++;
            if(secret[i]==guess[i])
                bulls++;
            i++;
        }

        for(auto temp: s)
        {
            if(g.find(temp.first)==g.end())
                continue;
            else
                cows += min(temp.second,g[temp.first]);
        }
        return to_string(bulls) + "A" + to_string(cows-bulls) + "B";
    }
};