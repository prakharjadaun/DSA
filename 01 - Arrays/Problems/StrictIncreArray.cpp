#include<vector>
using namespace std;
class Solution {
public:
    
    bool canBeIncreasing(vector<int>& nums)
    {
        bool flag = true;
        int len = nums.size();
        int index;
        for(int i=0;i<len-1;i++)
        {
            if(nums[i]>= nums[i+1])
            {
                flag = false;
                index = i+1;
                break;
            }
        }    

        
        if(flag)
            return true;
        
        vector<int> temp1(nums.begin(),nums.end());
        vector<int> temp2(nums.begin(),nums.end());

        // cout<<nums[index]<<endl;
        temp1.erase(temp1.begin()+index);
        temp2.erase(temp2.begin()+index-1);

        bool flag1 = true,flag2 = true;
        len = temp1.size();
        for(int i=0;i<len-1;i++)
        {
            if(temp1[i]>= temp1[i+1])
            {
                flag1 = false;
                break;
            }
        }   

        len = temp2.size();
        for(int i=0;i<len-1;i++)
        {
            if(temp2[i]>= temp2[i+1])
            {
                flag2 = false;
                break;
            }
        }   
         
        return flag1 || flag2;
    }
};