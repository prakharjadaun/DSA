#include<iostream>
#include<algorithm>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{
    // sorting the array 
    sort(arr, arr + r + 1);
    //returning the kth smallest element of the array 
    return arr[k - 1];
}

int main()
{
    //initializing the array
    int arr[] = {3,2,1,4,6,5,7};
    //getting the size of the array
    int n = sizeof(arr)/sizeof(arr[0]);
    //kth smallest number 
    int k = 3;

    //printing the array 
    cout<<"Printing the array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //printing the kth smallest element of teh array 
    cout<<k<<"th smallest element of the array : "<<kthSmallest(arr,0,n-1,k)<<endl;
    return 0;
}