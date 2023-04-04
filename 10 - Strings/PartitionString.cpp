#include<unordered_set>
using namespace std;

class Solution {
public:
    int partitionString(string s) 
    {
        unordered_set<char> hashset;    
        int subset = 0;
        for(int i=0;i<s.size();i++)
        {
            if(hashset.find(s[i])==hashset.end())
            {
                hashset.insert(s[i]);
                continue;
            }
            subset++;
            hashset.clear();
            hashset.insert(s[i]);
        }
        if(!hashset.empty())
            subset++;
        return subset;
    }
};