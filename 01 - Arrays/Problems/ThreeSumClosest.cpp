#include<climits>
#include<vector>
#include<math.h>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    // task -> to find the closest sum to the target from three numbers
    int threeSumClosest(vector<int>& nums, int target) 
    {
        //if the size is less than three, returned 0
        if(nums.size()<3)
        return 0;
        //initially our ans is equal to sum of first three numbers
        int temp=0,ans=nums[0]+nums[1]+nums[2];
        //sorting the array
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            //second index 
            int second = i+1;
            //third index
            int third = nums.size()-1;
            while(second < third)
            {
                //adding the three numbers
                temp = nums[i]+ nums[second] + nums[third];
                //if the sum is equal to the target, return target
                if(temp == target)
                {
                    return target;
                }
                //check if the sum (temp) is closes to the target or the previous value stored in ans
                if(abs(target - temp) < abs(target - ans))
                {
                    //update ans accordingly
                    ans = temp;
                }
                //if sum (temp) is greater than target, then decrementing the third variable (initally it was set to the last index of the array)
                if(temp > target)
                third--;
                else
                second++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution sol;
    cout<<sol.threeSumClosest(nums,target)<<endl;
}