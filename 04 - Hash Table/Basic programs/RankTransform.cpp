#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> nums(arr.begin(),arr.end()), ans;
        unordered_map<int,int> hashmap;
        sort(nums.begin(),nums.end());
        int rank = 1;
        for(int n : nums)
        {
            if(hashmap.find(n)==hashmap.end())
            {
                hashmap[n]=rank++;
            }
        }    

        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(hashmap[arr[i]]);
        }
        return ans;
    }
};