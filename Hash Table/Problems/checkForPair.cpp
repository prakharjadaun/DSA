// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
bool checkForPair(vector<int> v,int x)
{
    unordered_set<int> s;

    for(int i=0;i<v.size();i++)
    {
        int temp = x - v[i];
        cout<<"hello"<<endl;
        if(s.find(temp)!=s.end())
        {
            return true;
        }
        s.insert(v[i]);
    }
    return false;
}
int main()
{
    int n,x;
    cin>>n>>x;

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    if(checkForPair(v,x)==true)
    {
        cout<<"Pair exists"<<endl;
    }
    else
    {
        cout<<"Pair do not exists"<<endl;
    }
}
