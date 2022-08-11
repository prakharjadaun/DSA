#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    int *arr = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }

    int val = -1,val2,p1=0,p2=0;

    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=n-1;i>1 ;i--)
    {
        for(int j=0;j<i && arr[j]<=sqrt(arr[i]);j++)
        {
            if(arr[i]%arr[j]==0)
            {
                val2 = arr[i]/arr[j];

                if(s.find(val2)!=s.end())
                {
                    if(arr[i] > val)
                    {
                        val = arr[i];
                        p1 = arr[j];
                        p2 = val2;
                    }
                }
            }
        }
    }

    cout<<p1<<" and "<<p2<<" is the pair with the greatest product"<<endl;
    return 0;
}