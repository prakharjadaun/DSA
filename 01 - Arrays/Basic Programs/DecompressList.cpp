#include<vector>
using namespace std;
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        vector<int> ans;
        int len = nums.size();
        for(int i=0;i<len/2;i++)
        {
            int freq = nums[2*i];
            int val = nums[(2*i) + 1];
            for(int j=0;j<freq;j++)
            {
                ans.push_back(val);
            }
        }    
        return ans;
    }
};