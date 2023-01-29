#include<vector>
using namespace std;
class Solution {
public:
    int xorBeauty(vector<int>& nums) 
    {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans = ans ^ nums[i];
        }    
        return ans;
    }
};