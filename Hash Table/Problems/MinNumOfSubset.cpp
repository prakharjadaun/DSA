#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,temp;
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        m[temp]++;
    }

    int maxFre = -1;
    for(auto t : m)
    {
        maxFre = max<int>(maxFre,t.second);
    }

    cout<<maxFre<<endl;
}