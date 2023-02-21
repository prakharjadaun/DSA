#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) 
    {
        unordered_set<int> hashset;
        for(int n : nums)
        {
            hashset.insert(n);
        }    

        while(true)
        {
            if(hashset.find(original)!=hashset.end())
            {
                original = 2 * original;
            }
            else
            {
                break;
            }
        }
        return original;
    }
};