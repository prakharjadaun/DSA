#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//time complexity: O(log n)
//space complexity: O(1)
//recursive approach
bool binarySearch(vector<int> arr, int val, int beg, int end)
{
    if(beg > end)
        return false;
    
    int mid = (beg + end) / 2;
    if(arr[mid]==val)
        return true;
    else if(arr[mid] > val)
        return binarySearch(arr,val,beg, mid - 1);
    else
        return binarySearch(arr,val,mid+1,end);
    return false;
}

//iterative approach
/*
bool binarySearch(vector<int> arr, int val)
{
    sort(arr.begin(),arr.end());
    int beg = 0, end = arr.size() - 1;
    while(beg <= end)
    {
        int mid = (beg + end)/2;

        if(arr[mid] == val)
            return true;
        else if(arr[mid] > val)
            end = mid - 1;
        else 
            beg = mid + 1;
    }
    return false;
}
*/


int main()
{
    vector<int> arr = {1,2,3,2};
    sort(arr.begin(),arr.end());
    int val = 4;
    cout<<binarySearch(arr,val,0,arr.size()-1)<<endl;
}