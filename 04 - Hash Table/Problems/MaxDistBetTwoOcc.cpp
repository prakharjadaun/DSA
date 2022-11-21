#include<bits/stdc++.h>
using namespace std;

int maxDist(int arr[],int n)
{
    unordered_map<int,int> m;
    int maxD = 0;
    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])==m.end())
        {
            m[arr[i]] = i;
        }
        else
        {
            maxD = max<int>(maxD,i - m[arr[i]]);
        }
    }
    return maxD;
}

int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxDist(arr,n)<<endl;
}