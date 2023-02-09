#include<vector>
using namespace std;
#include<unordered_set>
#include<algorithm>
class Solution {
public:
    int findMaxK(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        unordered_set<int> hashset;
        int i=0;
        while(i<nums.size() && nums[i]<0)
        {
            hashset.insert(nums[i]);
            i++;
        }    

        i = nums.size()-1;
        while(i>=0 && nums[i]>0)
        {
            if(hashset.find(-1*nums[i])!=hashset.end())
                return nums[i];
            i--;
            
        }
        return -1;
    }
};