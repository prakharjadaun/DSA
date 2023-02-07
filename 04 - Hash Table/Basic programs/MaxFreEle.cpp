#include<vector>
using namespace std;
#include<unordered_map>
#include<climits>
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        unordered_map<int,int> hashmap;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key)
            hashmap[nums[i+1]]++;
        }     

        int max_Fre = INT_MIN,ele;
        for(auto temp : hashmap)
        {
            if(temp.second > max_Fre)
            {
                max_Fre = temp.second;
                ele = temp.first;
            }
        }
        return ele;
    }
};