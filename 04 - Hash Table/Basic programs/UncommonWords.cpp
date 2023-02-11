#include<unordered_map>
using namespace std;
#include<sstream>
#include<vector>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {
        unordered_map<string,int> hashset,hashset2;
        stringstream ss(s1);
        string word;
        while(ss>>word)
        {
            hashset[word]++;
        }    
        vector<string> ans;
        stringstream ss2(s2),ss3(s2);

        while(ss2>>word)
        {
            hashset2[word]++;
        }

        while(ss3>>word)
        {
            if(hashset.find(word)==hashset.end())
            {
                if(hashset2[word]==1)
                {
                    ans.push_back(word);
                }
            }
            else
            {
                hashset.erase(word);
            }
        }

        for(auto temp : hashset)
        {
            if(temp.second==1)
            ans.push_back(temp.first);
        }
        return ans;
    }
};