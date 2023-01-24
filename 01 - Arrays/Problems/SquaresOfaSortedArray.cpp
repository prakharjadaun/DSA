#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        int l=0,r=nums.size()-1;
        for(int i=res.size()-1;i>=0;i--)
        {
            if(abs(nums[l])>abs(nums[r]))
            {
                res[i] = (nums[l]*nums[l]);
                l++;
            }
            else
            {
                res[i] = (nums[r]*nums[r]);
                r--;
            }
        }
        return res;
    }
};