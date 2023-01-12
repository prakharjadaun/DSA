#include<vector>
using namespace std;
class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        if(nums.size()==1)
        return nums[0];

        int len = nums.size()-1;
        while(len!=0)
        {
            for(int i=0;i<len;i++)
            {
                nums[i] = (nums[i]+nums[i+1])%10;
            }
            len--;
        }
        return nums[0];
    }
};