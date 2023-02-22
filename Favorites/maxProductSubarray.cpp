#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int r = nums[0];
        int imax, imin;
        for(int i = 1, imax = r, imin = r;i<nums.size();i++)
        {   
            if(nums[i]<0)
                swap(imax,imin);
            
            imax = max(nums[i],imax*nums[i]);
            imin = min(nums[i],imin*nums[i]);

            r = max(r,imax);
        }
        return r;
    }
};