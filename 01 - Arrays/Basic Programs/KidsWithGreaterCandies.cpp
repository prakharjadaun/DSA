#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        //getting the max element of the array
        int max_ele = *max_element(candies.begin(),candies.end());
        vector<bool> ans;
        //getting the answer variable
        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies >= max_ele)
            ans.push_back(true);
            else
            ans.push_back(false);
        }    
        return ans;
    }
};