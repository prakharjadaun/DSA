#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int red=0,blue=0,white=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                red++;
            else if(nums[i]==1)
                blue++;
            else
                white++;
        }

        int i=0;
        while(i<nums.size() - (white+blue))
        {
            nums[i] = 0;
            i++;
        }

        while(i<nums.size() - (white))
        {
            nums[i] = 1;
            i++;
        }
        while(i<nums.size())
        {
            nums[i]=2;
            i++;
        }
    }
};