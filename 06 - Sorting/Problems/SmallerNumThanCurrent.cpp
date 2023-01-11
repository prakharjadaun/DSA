#include<vector>
using namespace std;
class Solution {
public:
    //using count sort algorithm
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        //as the range of nums[i] is under 101, we created a bucket of size 102
        int bucket[102]={0};
        //counted the frequcency of each number and stored it in the bucket
        for(int i=0;i<nums.size();i++)
        {
            bucket[nums[i]+1]++;
        }  
        //if we get the sum of all the previous value before ith index, then it will be the number of elements smaller than it
        //we keep the sum of previous elements in the current index
        for(int i=1;i<102;i++)
        {
            bucket[i] += bucket[i-1];
        }
        //then we assign the bucket elements to the num vector
        for(int i=0;i<nums.size();i++)
        {
            nums[i] = bucket[nums[i]];
        }
        //returning the answer, YAY
        return nums;
    }
};