#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        //if the size is exactly two then both the elements would definitely be equal to the target
        //thus returning their indices
        if(nums.size()==2)
        {
            ans.push_back(0);
            ans.push_back(1);
            return ans;
        }
         
        unordered_map<int,int> m;
        //storing the last indices of the unique elements in a map 
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]] = i;
        }     
        //O(n) complexity
        for(int i=0;i<nums.size();i++)
        {
            int req = target - nums[i];
            //if their exists an element equals to req variable and its index is not equal to i the both the number's indices are our answer
            if(m.find(req)!=m.end())
            {
                if(m.find(req)->second != i)
                {
                    ans.push_back(m.find(req)->second);
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
};