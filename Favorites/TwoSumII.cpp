#include<vector>
using namespace std;
class Solution {
public:

    //simple approach of binary search
    //start iterating through the first and last element
    //1. if their sum is equal to target, return the indices
    //2. if their sum is greater than target, we decrease the r (which starts from last index)
    //3. if their sum is lesser than the target, we increase the l (which starts from the first index)  
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int l = 0;
        int r = numbers.size() - 1;

        while(l<r)
        {
            if(numbers[l] + numbers[r] == target)
                return {l+1,r+1};
            else if(numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        return {};
    }
};