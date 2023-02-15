#include<vector>
using namespace std;
#include<math.h>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[abs(nums[i])-1] > 0)
            {
                nums[abs(nums[i])-1] = -1 *nums[abs(nums[i])-1];
            }
        }    

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
            {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};