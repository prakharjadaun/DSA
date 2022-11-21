// #include<bits/stdc++.h>
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

void isSubset(vector<int> a,vector<int> b)
{
    unordered_set<int> s;

    for(int i=0;i<a.size();i++)
    {
        s.insert(a[i]);
    }
    int p = s.size();

    //now inserting second array into the set 
    for(int i=0;i<b.size();i++)
    {
        s.insert(b[i]);
    }

    if(s.size()!=p)
    {
        cout<<"Array 2 is not a subset"<<endl;
    }
    else
    {
        cout<<"Array 2 is a subset"<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    //creating two vectors for the arrays
    vector<int> a(n),b(m);
    //getting the input
    for(int i=0;i<a.size();i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }

    isSubset(a,b);
    return 0;
}