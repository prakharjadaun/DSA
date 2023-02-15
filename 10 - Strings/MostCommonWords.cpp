#include<sstream>
#include<vector>
#include<unordered_map>
#include<climits>
#include<iostream>
using namespace std;
class Solution {
public:
    string mostCommonWord(string p, vector<string>& banned) 
    {
        unordered_map<string,int> hashmap;
        for(int i=0;i<p.size();i++)
        {
            if(p[i] =='!' || p[i]=='?' || p[i]=='\'' || p[i]==',' || p[i]==';' || p[i]=='.' || p[i]=='\"')
                p[i] = ' ';
            else if(isupper(p[i]))
                p[i] = p[i] + 32;
        }

        stringstream ss(p);
        string word;
        while(ss>>word)
        {
            hashmap[word]++;
        }

        for(int i=0;i<banned.size();i++)
        {
            if(hashmap.find(banned[i])!=hashmap.end())
                hashmap.erase(banned[i]);
        }

        int max_fre = INT_MIN;
        string ans;

        for(auto temp : hashmap)
        {
            if(temp.second > max_fre)
            {
                max_fre = temp.second;
                ans = temp.first;
            }
        }

        return ans;
    }
};