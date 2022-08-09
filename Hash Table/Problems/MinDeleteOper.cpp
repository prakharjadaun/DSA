// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void MinDeleteOp(vector<int> v)
{
    unordered_map<int,int> m;
    for(int i=0;i<v.size();i++)
    {
        //storing the frequency of the elements
        m[v[i]]++;
    }

    int maxFre = 0;
    for(auto temp : m)
    {
        if(temp.second>maxFre)
        {
            maxFre = temp.second;
        }
    }

    cout<<"Minimum delete operations required to make all elements of the array same : "<<v.size() - maxFre<<endl;
}

int main()
{
    int n,temp;
    cin>>n;

    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }

    MinDeleteOp(v);
    return 0;
}