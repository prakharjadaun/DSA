#include<bits/stdc++.h>
using namespace std;
void smallSubArray(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    int maxFre=0, ele;
    for(auto temp : m)
    {
        if(temp.second > maxFre)
        {
            maxFre = temp.second;
            ele = temp.first;
        }
    } 

    int first=-1,last;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele && first==-1)
        {
            first = i;
        }
        else if(arr[i]==ele)
        {
            last = i;
        }
    }

    for(int i=first;i<=last;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[] = {4, 1, 1, 2, 2, 1, 3, 3} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    smallSubArray(arr,n);
    return 0;
}