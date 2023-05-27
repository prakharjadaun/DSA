#include<unordered_set>
using namespace std;
#include<vector>
class Solution {
public:
    int similarPairs(vector<string>& words) 
    {
        int res = 0;
        unordered_set<char> hashset;
        for(int i=0;i<words.size();i++)
        {
            for(char ch : words[i])
                hashset.insert(ch);
            for(int j=i+1;j<words.size();j++)
            {
                if(i==j)
                    continue;
                
                unordered_set<char> temp(words[j].begin(),words[j].end());

                if(hashset == temp)
                    res++;
                temp.clear();
            }
            hashset.clear();
        }    
        return res;
    }
};