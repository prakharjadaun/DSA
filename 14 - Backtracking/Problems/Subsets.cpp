#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &nums,vector<int> &temp,int index)
    {
        ans.push_back(temp);
        for(int i = index;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(ans,nums,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        // ans.push_back({});
        vector<int> temp;
        solve(ans,nums,temp,0);
        return ans;
    }
};