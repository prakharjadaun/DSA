#include<vector>
using namespace std;
class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int index = -1;
        int beg = 0,end = arr.size()-1;
        //using algo for binary search to find the peak index of the mountain array
        while(beg<=end)
        {
            int mid = (beg + end)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
            {
                index = mid;
                break;
            }
            else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1])
            {
                beg = mid + 1;
            }
            else
            {
                end = mid;
            }
        }    
        return index;
    }
};