#include<vector>
#include<math.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        //first assign n+1 to all the negative or numbers equal to zero
        for (int i = 0; i < n; i++) 
            if (nums[i] <= 0) 
                nums[i] = n + 1;

        //make the nums[abs(nums[i])-1] to negative -> this will indicate that the i+1 number exists in the array
        //first check that nums[i]<=n or not and greater to zero
        for (int i = 0; i < n; i++) 
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) 
                nums[abs(nums[i]) - 1] *= -1;
        //then iterate through the updated array, if positive encountered then return i+1 that this index has not been assigned negative
        for (int i = 0; i < n; i++) 
            if (nums[i] > 0) 
                return i + 1;
        
        //lastly return n+1
        return n + 1;
    }
};