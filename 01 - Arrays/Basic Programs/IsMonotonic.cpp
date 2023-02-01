#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        bool inc = true, dec = true;
        //iterate through the all elements 
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
                inc = false;
            if(nums[i]<nums[i+1])
                dec = false;

        }   
        //if any of the bool variables are true then array is monotonic otherwise false
        if(inc || dec)
            return true;
        return false; 
    }
};