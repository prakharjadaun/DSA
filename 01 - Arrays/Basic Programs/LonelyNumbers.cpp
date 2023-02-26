#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size();i++)
        {
            hashmap[nums[i]]++;
        }    

        vector<int> ans;
        for(auto temp : hashmap)
        {
            if(temp.second == 1 && hashmap.find(temp.first-1)==hashmap.end() && hashmap.find(temp.first+1)==hashmap.end())
                ans.push_back(temp.first);
        }
        return ans;
    }
};