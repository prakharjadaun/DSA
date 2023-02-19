#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        unordered_map<string,int> hashmap;
        for(string ch : words)
        {
            hashmap[ch]++;
        }

        int ans = 0;
        int i = 0, j = 0;
        while(j<=s.size())
        {
            string temp = s.substr(i,j);
            if(hashmap.find(temp)!=hashmap.end())
                ans+= hashmap[temp];
            j++;
        }    
        return ans;
    }
};