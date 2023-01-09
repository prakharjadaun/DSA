#include<vector>
using namespace std;
class Solution {
public:
    //task : complete in O(log n) time complexity
    // we have to use binary search here
    int search(vector<int>& nums, int target) 
    {
        int beg = 0;
        int end = nums.size();
        int mid;
        //starting with simple binary search algorithm
        while(beg<end)
        {
            //find the middle index
            mid = (beg+end)/2;
            
            //if the target element if smaller than starting element && the starting element is smaller than middle element
            //we have to skip the elements from num[0] to nums[mid] 
            //-INFINITY
            if(target < nums[0] && nums[0] < nums[mid])
                beg = mid +1;
            //if the target is greater than nums[0] and nums[0] is greater than middle element
            //we want to have the starting part of the vector
            else if(target >= nums[0] && nums[0] > nums[mid])
                end = mid;
            else if(nums[mid] < target)
                beg = mid+1;
            else if(nums[mid] > target)
                end = mid;
            else 
                return mid;  
        }
        //if element not found, return -1
        return -1;
    }
};