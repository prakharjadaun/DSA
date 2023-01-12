#include<unordered_set>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    //function to reverse the passed integer
    int rev(int a)
    {
        int temp = 0;
        while(a!=0)
        {
            int rem = a%10;
            temp = temp*10 + rem;
            a = a/10;
        }
        return temp;
    }
    int countDistinctIntegers(vector<int>& nums) 
    {
        //defining a unordered set
        unordered_set<int> hashset;
        for(int i=0;i<nums.size();i++)
        {
            //storing the nums[i] in hashset and reverse of it
            hashset.insert(nums[i]);
            int temp = rev(nums[i]);
            hashset.insert(temp);
        }    
        //returning the number of unique elements 
        return hashset.size();
    }
};

int main()
{
    Solution sol;
    vector<int> num = {1,13,10,12,31};
    cout<<sol.countDistinctIntegers(num)<<endl;
}