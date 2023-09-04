#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void solve(vector<int> &candidates,vector<vector<int>> &ans,int target,int combsum,vector<int> comb,int index)
    {
        if(combsum > target)
            return;
        
        if(combsum == target)
        {
            ans.push_back(comb);
            return;
        }

        for(int i=index;i<candidates.size();i++)
        {
            //main condition to handle the duplicates array ans
            if(i!=index && candidates[i]==candidates[i-1])
                continue;
            combsum += candidates[i];
            comb.push_back(candidates[i]);
            solve(candidates,ans,target,combsum,comb,i+1);
            combsum -= candidates[i];
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(candidates,ans,target,0,comb,0);
        return ans;
    }
};