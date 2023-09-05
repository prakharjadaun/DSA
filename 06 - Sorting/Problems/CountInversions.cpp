#include <bits/stdc++.h> 
using namespace std;
void merge(long long *arr,int n,int low,int mid,int high,int &cnt)
{
    vector<long long> temp;
    int left = low;
    int right = mid+1;

    while(left<=mid && right<=high)
    {
        if(arr[left]<arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            //condition to count inversions
            cnt += (mid-left+1);
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

void mergeSort(long long *arr,int n, int low,int high,int &cnt)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        mergeSort(arr,n,low,mid,cnt);
        mergeSort(arr,n,mid+1,high,cnt);
        merge(arr,n,low,mid,high,cnt);
    }
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    int cnt = 0;
    mergeSort(arr,n,0,n-1,cnt);
    return cnt;
}