#include<vector>
using namespace std;
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
        //x1,x2,x3...xn,y1,y2,y3....yn
        // convert ->
        //x1,y1,x2,y2,x3,y3......xn,yn
        if(nums.size()==2)
            return nums;
        vector<int> ans;
        int m = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(i%2==0)
            {
                ans.push_back(nums[m]);
                m++;
            }
            else
            {
                ans.push_back(nums[n]);
                n++;
            }
        }    
        return ans;
    }
};