#include<unordered_map>
using namespace std;
#include<vector>
#include<climits>
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> hashmap;
        vector<int> ans;
        int max_Fre = INT_MIN;
        int ele;
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;
        }

        for(int i=0;i<k;i++)
        {
            max_Fre = INT_MIN;
            for(auto temp : hashmap)
            {
                if(temp.second > max_Fre)
                {
                    ele = temp.first;
                    max_Fre = temp.second;
                }
            }

            ans.push_back(ele);
            hashmap.erase(ele);
        }

        return ans;
    }
};