#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        /*
        //using bit manipulation (not successful)
        int ans = 0,temp=0;
        if(nums.size()==2)
        return nums[0];

        for(int i=1;i<nums.size();i++)
        {
            temp = temp ^ i;
        }
        cout<<temp<<endl;
        for(int i=0;i<nums.size();i++)
        {
            ans = ans ^ nums[i];
        }    
        cout<<ans<<endl;
        return abs(ans - temp);
        */
        //--------------------------------
        /* -> with hashing 
        unordered_set<int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                ans = nums[i];
                break;
            }
            m.insert(nums[i]);
        }
        
        return ans;
        */
        //-----------------------------------
        //using the fast and slow pointer approach (noted in notebook)
        int s = 0,f=0;
        do 
        {
            s = nums[s];
            f = nums[nums[f]];
        }while(s!=f);

        s = 0;
        while(s!=f)
        {
            s = nums[s];
            f = nums[f];
        }
        return s;
    }
};

int main()
{
    vector<int> nums = {1,4,2,4,4};
    Solution sol;
    cout<<sol.findDuplicate(nums)<<endl;
}