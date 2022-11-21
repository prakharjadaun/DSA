#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k,temp;
    cin>>n>>m>>k;
    int *arr = (int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    unordered_set<int> s;
    for(int i=0;i<m;i++)
    {
        cin>>temp;
        s.insert(temp);
    }

    int counter=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i])==s.end())
        {
            counter++;
        }
        if(counter==k)
        {
            cout<<arr[i]<<endl;
            break;
        }
    }
    return 0;
}