#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        if(nums.size()==0)
            return {};
        vector<string> res;
        string str="",temp;
        temp = to_string(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(abs(nums[i]-1) == abs(nums[i-1]))
            {
                str = temp;
                str += "->";
                str += to_string(nums[i]);
            }
            else
            {
                if(str.size()==0)
                    res.push_back(temp);
                else
                    res.push_back(str);
                temp = to_string(nums[i]); 
                str="";
            }
        }  
        if(str.size()==0)
        res.push_back(temp);
        else
        res.push_back(str);
        return res;  
    }
};