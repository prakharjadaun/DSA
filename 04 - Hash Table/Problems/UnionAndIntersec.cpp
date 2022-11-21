// #include<bits/stdc++.h>
#include<iostream>
#include<list>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void Union(list<int> l1,list<int> l2)
{
    unordered_set<int> s;
    list<int>::iterator it = l1.begin();
    while(it!=l1.end())
    {
        s.insert(*it);
        it++;
    }

    it = l2.begin();
    while(it!=l2.end())
    {
        s.insert(*it);
        it++;
    }

    unordered_set<int>::iterator n = s.begin();
    cout<<"Union of two linked list : ";
    while(n!=s.end())
    {
        cout<<*n<<" ";
        n++;
    }
    cout<<endl;
}



void Intersection(list<int> l1,list<int> l2)
{
    unordered_map<int,int> m;

    list<int>::iterator i = l1.begin();
    while(i!=l1.end())
    {
        if(m.find(*i)==m.end())
        {
            m[*i]++;
        }
        i++;
    }

    i = l2.begin();
    while(i!=l2.end())
    {
        m[*i]++;
        i++;
    }

    cout<<"Intersection of two linked list : ";
    unordered_map<int,int>::iterator iter = m.begin();
    while(iter!=m.end())
    {
        if(iter->second>=2)
        {
            cout<<iter->first<<" ";
        }
        iter++;
    }
}

int main()
{
    int n,m,temp;
    cin>>n>>m;
    //getting two linked list
    list<int> l1,l2;

    for(int i=0;i<n;i++)
    {
        cin>>temp;
        l1.push_back(temp);
    }

    for(int i=0;i<m;i++)
    {
        cin>>temp;
        l2.push_back(temp);
    }

    Union(l1,l2);
    Intersection(l1,l2);
    return 0;
}