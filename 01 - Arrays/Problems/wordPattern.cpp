#include<string>
#include<unordered_set>
#include<sstream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        stringstream ss(s);
        unordered_map<char,string> m;
        unordered_set<string> hashset;
        string word;
        int i=0;
        while(ss>>word)
        {
            if(m.find(pattern[i])!=m.end() && m[pattern[i]]==word)
            {
                i++;
                continue;
            }
            if(m.find(pattern[i])!=m.end() && m[pattern[i]]!=word)
                return false;
            if(m.find(pattern[i])==m.end() && hashset.find(word)==hashset.end())
            {
                m[pattern[i]] = word;
            }
            if(m.find(pattern[i])==m.end() && hashset.find(word)!=hashset.end())
            {
                return false;
            }
            hashset.insert(word);
            if(hashset.size()> m.size())
                return false;
            i++;
        }

        if(i<pattern.size())
        return false;

        return true;
    }
};