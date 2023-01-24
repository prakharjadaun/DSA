#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                m[nums[i][j]]++;
            }
        } 
        for(auto temp : m)
        {
            if(temp.second == nums.size())
            ans.push_back(temp.first);
        }
        return ans;
    }
};