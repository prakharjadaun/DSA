#include<unordered_map>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char,char> hashmap1,hashmap2;
        for(int i=0;i<s.size();i++)
        {
            if(hashmap1.find(s[i])==hashmap1.end())
            {
                hashmap1[s[i]] = t[i];
            }
            else
            {
                if(hashmap1[s[i]] != t[i])
                    return false;
            }

            if(hashmap2.find(t[i])==hashmap2.end())
            {
                hashmap2[t[i]] = s[i];
            }
            else
            {
                if(hashmap2[t[i]] != s[i])
                    return false;
            }
            
        }
        return true;
    }
};