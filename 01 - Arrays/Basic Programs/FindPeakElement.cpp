#include<vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        
        if(nums[0]>nums[1])
            return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;

        int beg = 0;
        int end = nums.size();
        while(beg<end)
        {
            int mid = (beg + end)/2;
            if(nums[mid]>nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] < nums[mid-1])
                end = mid;
            else
                beg = mid;
        }
        return -1;
    }
};