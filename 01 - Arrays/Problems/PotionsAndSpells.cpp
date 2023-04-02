#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> res;
        sort(potions.begin(),potions.end());
        
        for(int i=0;i<spells.size();i++)
        {
            long long need = (spells[i] + success - 1)/ spells[i];
            auto it = lower_bound(potions.begin(),potions.end(), need);
            res.push_back(potions.end() - it);
        }      
        return res;
    }
};