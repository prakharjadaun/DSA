#include<vector>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-all-duplicates-in-an-array/solutions/775798/c-four-solution-o-n-n-to-o-n-explain-all/