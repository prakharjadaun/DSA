#include<map>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums)
    {
        map<int,int,greater<int>> hashmap;
        vector<int> ans;
        set<int> hashset;
        set<int>::iterator it;
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;
        }   

        for(auto temp : hashmap)
        {
            hashset.insert(temp.second);
        }

        for(it = hashset.begin();it!=hashset.end();it++)
        {
            for(auto temp : hashmap)
            {
                if(temp.second == *it)
                {
                    for(int i=0;i<*it;i++)
                    {
                        ans.push_back(temp.first);
                    }
                }
            }
        }
        return ans;

    }
};