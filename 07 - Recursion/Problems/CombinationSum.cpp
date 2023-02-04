#include<vector>
using namespace std;
//mainly we need to generate a state space tree and insert that vector which is equal to the target
class Solution {
    vector<vector<int>> ans;
    void combination(vector<int> candidates, int target,vector<int> comb, int combSum, int currIndex)
    {
        //if combination sum is greater than the target we backtrack
        if(combSum > target)
            return;
        //if the combination sum is equal to target, we insert into the ans vector
        if(combSum == target)
        {
            ans.push_back(comb);
            return;
        }
        //then we iterate to all the possible combinations of the elements of the candidates 
        for(int i=currIndex;i<candidates.size();i++)
        {
            // we add each element to the comb vector & add it to the combination sum
            comb.push_back(candidates[i]);
            combSum+= candidates[i];
            //we make recursive calls to get all the possible combinations
            combination(candidates,target,comb,combSum,i);
            //then we remove that element added to the vector and the combination sum
            comb.pop_back();
            combSum -= candidates[i];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> comb;
        combination(candidates,target,comb,0,0);
        return ans;   
    }
};