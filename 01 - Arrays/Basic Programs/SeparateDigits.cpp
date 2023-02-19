#include<vector>
using namespace std;
class Solution {
public:
    
    vector<int> separateDigits(vector<int>& nums) 
    {
        vector<int> ans;
        vector<int> temp;
        for(int n : nums)
        {
            while(n)
            {
                temp.insert(temp.begin(),n % 10);
                n = n / 10;
            }
            ans.insert(ans.end(),temp.begin(),temp.end());
            temp.clear();
        }    
        return ans;
    }
};