#include<bits/stdc++.h>
using namespace std;
int NonOverlappingsum(vector<int> v1,vector<int> v2)
{
    int ans=0;

    unordered_set<int> s;
    for(int i=0;i<v1.size();i++)
    {
        s.insert(v1[i]);
    }

    for(int i=0;i<v2.size();i++)
    {
        if(s.find(v2[i])!=s.end())
        {
            s.erase(v2[i]);
        }
        else
        s.insert(v2[i]);
    }

    ans = accumulate(s.begin(),s.end(),0);

    return ans;
}
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

    cout<<NonOverlappingsum(v1,v2)<<endl;
}