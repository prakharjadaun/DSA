#include<vector>
using namespace std;
#include<unordered_map>
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            if(hashmap.find(nums[i])==hashmap.end())
            {
                hashmap[nums[i]]=i;
            }
            else
            {
                if(abs(hashmap[nums[i]]-i) <=k)
                    return true;
                else
                    hashmap[nums[i]] = i;
            }
        }    
        return false;
    }
};