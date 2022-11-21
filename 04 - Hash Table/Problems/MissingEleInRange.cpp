#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp,low, high;
    cin>>n;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        s.insert(temp);
    }

    cin>>low>>high;

    for(int i=low;i<=high;i++)
    {
        if(s.find(i)==s.end())
        {
            cout<<i<<endl;
        }
    }
    return 0;

}