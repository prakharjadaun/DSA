#include<unordered_set>
#include<vector>
using namespace std;
#include<iostream>
class Solution {
public:
    unordered_set<char> convert(string s)
    {
        unordered_set<char> hash;
        for(int i=0;i<s.size();i++)
        {
            hash.insert(s[i]);
        }
        return hash;
    }
    bool check(unordered_set<char> hash, string s)
    {
        bool flag = true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] >=65 && s[i]<=90)
                s[i] = s[i]+32;
            if(hash.find(s[i])==hash.end())
            {
                return false;
            }
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) 
    {
        string row1 = "qwertyuiop",row2 = "asdfghjkl", row3 = "zxcvbnm";
        unordered_set<char> hash1,hash2,hash3;
        hash1 = convert(row1);
        hash2 = convert(row2);
        hash3 = convert(row3);
        vector<string> ans;
        for(int i=0;i<words.size();i++)
        {
            if(check(hash1,words[i]) || check(hash2,words[i]) || check(hash3,words[i]))
            {
                ans.push_back(words[i]);
                cout<<words[i]<<" ";
            }
        }
        return ans;
    }
};