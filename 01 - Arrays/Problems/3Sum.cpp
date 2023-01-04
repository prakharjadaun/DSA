#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<int> temp;
        unordered_map<int,int> m,n;
        if(nums.size()==0)
            return ans;
        
        sort(nums.begin(),nums.end());

        if(nums[0]>0)
            return ans; 
        
        for(int i=0;i<nums.size();i++)
        {
            n[nums[i]] = i;
        }

        for(int i=0;i<nums.size()-2;i++)
        {
            if(nums[i]>0)
                break;
            
            for(int j=i+1;j<nums.size()-1;j++)
            {
                int req = -1*(nums[i]+nums[j]);
                if(n.count(req) && n.find(req)->second > j)
                {
                    ans.push_back({nums[i],nums[j],req});
                }
                j = n.find(nums[j])->second; 
            }
            i = n.find(nums[i])->second;
        }
        return ans;           
    }
};