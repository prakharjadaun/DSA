#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        //created a set (it stores in increasing order )
        set<int> hashset;
        //inserted all the elements into set 
        for(int i=0;i<nums.size();i++)
        {
            hashset.insert(nums[i]);
        }    
        int i=0;
        //then modified the nums with the unique elements 
        for(auto temp: hashset)
        {
            nums[i] = temp;
            i++;
        }
        //lastly returned the number of unique elements 
        return hashset.size();
    }
};