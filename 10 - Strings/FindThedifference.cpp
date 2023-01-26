#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        unordered_map<char,int> hashset;
        char ans=' ';
        if(s.size()==0)
        return t[0];
        for(int i=0;i<s.size();i++)
        {
            hashset[s[i]]++;
        }    
        
        for(int i=0;i<t.size();i++)
        {
            if(hashset.find(t[i])==hashset.end())
            {
                ans = t[i];
                break;
            }
            else
            {
                hashset[t[i]]--;
                if(hashset[t[i]]==0)
                hashset.erase(t[i]);
            }
        }
        return ans;
    }
};