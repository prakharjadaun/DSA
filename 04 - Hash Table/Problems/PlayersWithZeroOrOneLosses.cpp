#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        unordered_map<int,int> hashmap;
        set<int> hashset;
        for(int i=0;i<matches.size();i++)
        {
            hashset.insert(matches[i][0]);
            hashset.insert(matches[i][1]);
            hashmap[matches[i][1]]++;
        }    
        set<int>::iterator it;
        vector<vector<int>> res(2);
        for(it = hashset.begin();it!=hashset.end();it++)
        {
            if(hashmap.find(*it)==hashmap.end())
                res[0].push_back(*it);
            else
            {
                if(hashmap[*it]==1)
                    res[1].push_back(*it);
            }
        }
        return res;
    }
};