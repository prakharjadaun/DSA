/*
//spproach = using map
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        
        for(auto temp : m)
        {
            if(temp.second==1)
            {
                ans = temp.first;
                break;
            }
        }
        return ans;
    }
};

time complexity : O(n)
space complexity : O(n)
*/

//time complexity : O(n)
//space complexity : O(1)
//Approach : bitwise 
/*

A^A = 0
A^B^A = B

if we perform bitwise xor on each element then the element that remains in our answer variable will be element with frequency 1. Because other elements have frequency 2 and their xor becomes 0.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ans=0 ;
        for(auto temp : nums)
        {
            //performing xor operation
            ans = ans ^ temp;
        }
        return ans;
    }
};