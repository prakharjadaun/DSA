#include<bits/stdc++.h>
using namespace std;

void duplicateEle(int arr[],int n)
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    for(auto temp : m)
    {
        if(temp.second>=2)
        {
            cout<<temp.first<<endl;
        }
    }
}

int main()
{
    int arr[] = {1,2,3,1,2,4,3,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    duplicateEle(arr,n);
    return 0;
}