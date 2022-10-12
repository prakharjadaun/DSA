#include<iostream>
#include<utility>
#include<climits>
using namespace std;

//function to find the minimum and the maximum element of the array
pair<int,int> minAndMax(int arr[], int n)
{
    pair<int,int> p;
    if(n==1)
    {
        p.first = arr[0];
        p.second = arr[0];
        return p;
    }
    
    p.first = INT_MIN;
    p.second = INT_MAX;

    //finding the minimum and maximum element of the array
    for(int i=0;i<n;i++)
    {
        if(p.first < arr[i])
        {
            p.first = arr[i];
        }
        if(p.second > arr[i])
        {
            p.second = arr[i];
        }
    }
    
    return p;
} 


int main()
{
    //initializing the array
    int arr[] = {100,490,214,678,89,2};
    //getting the size of the array
    int n = sizeof(arr)/sizeof(arr[0]);

    //printing the original array
    cout<<"Original array : ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //receiving the minimum and maximum element the array
    pair<int,int> ans = minAndMax(arr,n);

    //printing the maximum and minimum element of the array
    cout<<"Max element : "<<ans.first<<endl;
    cout<<"Min element : "<<ans.second<<endl;
    return 0;
}