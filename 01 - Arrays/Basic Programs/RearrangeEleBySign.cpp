#include<vector>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        vector<int> pos,neg;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] < 0)
            neg.push_back(nums[i]);
            else
            pos.push_back(nums[i]);
        }    

        int m = 0;
        int n = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                nums[i] = pos[m];
                m++;
            }
            else
            {
                nums[i] = neg[n];
                n++;
            }
        }
        return nums;
    }
};