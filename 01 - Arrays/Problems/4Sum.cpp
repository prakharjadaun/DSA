#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        if(nums.size()<4)
        return ans;
        sort(nums.begin(),nums.end());
        if(target==0 && nums[0]>0)
        return ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }    

        for(int i=0;i<nums.size()-3;i++)
        {
            long long int req1 = target - nums[i];
            for(int j=i+1;j<nums.size()-2;j++)
            {
                long long int req2 = req1 - nums[j];
                for(int k=j+1;k<nums.size()-1;k++)
                {
                    long long int req = req2 - nums[k];

                    if(m.count(req) && m.find(req)->second > k )
                    {
                        ans.push_back({nums[i],nums[j],nums[k],(int)req});    
                    }
                    k = m.find(nums[k])->second;
                }
                j = m.find(nums[j])->second;
            }
            i = m.find(nums[i])->second;
        }
        return ans;
    }
};