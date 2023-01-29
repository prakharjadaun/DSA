#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        //first sorting the array
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i=0;i<nums.size();)
        {
            if(i!=nums.size()-1)
            {
                //if a number is equal to next element
                if(nums[i]==nums[i+1])
                {
                    //performing xor with that number here first then again below so that number which is 3 times can be xor as 0 and the number with single frequency remains in the answer variable
                    ans = ans ^ nums[i];
                    i+=2;
                }
            }
            ans = ans ^ nums[i];
            i++;
        }    
        return ans;
    }
};

//https://leetcode.com/problems/single-number-ii/solutions/43295/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers/