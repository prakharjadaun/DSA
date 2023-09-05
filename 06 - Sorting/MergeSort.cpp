#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while(left<=mid)
        temp.push_back(arr[left++]);
    
    while(right<=high)
        temp.push_back(arr[right++]);

    for(int i=low;i<=high;i++)
    {
        arr[i] = temp[i-low];
    }

}

void msort(vector<int> &arr,int low,int high)
{
    if(low==high)
        return;
    int mid = (low + high)/2;
    msort(arr,low,mid);
    msort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(vector < int > & arr, int n) 
{
    // Write your code here.
    msort(arr,0,n-1);
}