#include<iostream>
using namespace std;

//time complexity: O(2^sum)
// Auxiliary Space: O(target)
int count(int arr[], int n, int sum)
{
    // if the sum is equal to zero, then we include that set
    if(sum==0)  
        return 1;

    // if the sum becomes less than 0, we do not include that set
    if(sum<0)
        return 0;

    // if the count of elements becomes 0 or less than that, we do not include that set
    if(n<=0)
        return 0;

    // we return the addition of two counts
    //1. count when the element is n-1 
    //2. count when the sum becomes (sum - arr[n-1])
    return count(arr,n-1,sum) + count(arr,n,sum - arr[n-1]);
}

int main()
{
    //definning the array
    int arr[] = {1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 4;

    cout<<count(arr,n,sum)<<endl;
}