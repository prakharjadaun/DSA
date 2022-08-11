#include<bits/stdc++.h>
using namespace std;

void EleInFirst(int arr1[],int arr2[], int n1,int n2)
{
    unordered_map<int,int> m;
    for(int i=0;i<n1;i++)
    {
        if(m.find(arr1[i])==m.end())
        {
            m[arr1[i]]++;
        }
    }

    for(int i=0;i<n2;i++)
    {
        if(m.find(arr2[i])!=m.end())
        {
            m[arr2[i]]++;
        }
    }

    for(auto temp : m)
    {
        if(temp.second<2)
        {
            cout<<temp.first<<endl;
        }
    }
}
int main()
{
    int arr1[] = {1,2,3,1,4,5};
    int arr2[] = {4,5,6,7,8};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);


}