#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n1,n2,temp;
    cin>>n1>>n2;
    vector<int> v1,v2;

    for(int i=0;i<n1;i++)
    {
        cin>>temp;
        v1.push_back(temp);
    }

    for(int i=0;i<n2;i++)
    {
        cin>>temp;
        v2.push_back(temp);
    }

    unordered_map<int,int> m;
    for(int i=0;i<n1;i++)
    {
        if(m.find(v1[i])==m.end())
        {
            m[v1[i]]++;
        }
    }

    for(int i=0;i<n2;i++)
    {
        m[v2[i]]++;
    }

    int counter=0;
    unordered_map<int,int>::iterator r;
    r = m.begin();
    while(r != m.end())
    {
        if(r->second>1)
        {
            counter++;
        }
        r++;
    }
    cout<<counter<<endl;
}