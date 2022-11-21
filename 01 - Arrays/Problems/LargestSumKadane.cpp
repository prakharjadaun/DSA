#include<iostream>
#include<climits>
using namespace std;

//function to find the largest subarray sum of the passed array
int LargestSubarraySum(int arr[], int n)
{

    int max_so_far = INT_MIN,max_ending_here = 0;
    //finding the maximum sub array sum
    for(int i=0;i<n;i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if(max_ending_here<0)
            max_ending_here = 0;
    }
    //returning the maximum subarray sum
    return max_so_far;
}

int main()
{
    //initializing the array
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    //storing the size of the array in n
    int n = sizeof(arr)/sizeof(arr[0]);

    //calling the largest subarray sum and printing it
    cout<<LargestSubarraySum(arr,n)<<endl;
    return 0;
}