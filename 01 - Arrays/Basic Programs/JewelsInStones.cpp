#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        unordered_set<char> hashset;
        for(int i=0;i<jewels.size();i++)
        {
            hashset.insert(jewels[i]);
        }    

        int ans=0;
        for(int i=0;i<stones.size();i++)
        {
            if(hashset.find(stones[i])!=hashset.end())
            ans++;
        }
        return ans;
    }
};