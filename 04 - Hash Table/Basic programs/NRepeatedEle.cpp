#include<unordered_map>
using namespace std;
#include<vector>
class Solution 
{
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        unordered_map<int,int> hashmap;
        int ans;
        for(int n : nums)
        {
            hashmap[n]++;
            if(hashmap[n] > 1)
            {
                ans = n;
                break;
            }
        }
        return ans;
    }
};