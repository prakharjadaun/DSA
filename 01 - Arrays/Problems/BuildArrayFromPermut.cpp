#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) 
    {
        if(nums.size()==0)
        return nums;
        vector<int> ans;
        // ans[i] = nums[nums[i]]
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[nums[i]]);
        }    
        return ans;
    }
};