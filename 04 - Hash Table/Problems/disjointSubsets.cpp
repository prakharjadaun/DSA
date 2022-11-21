#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s1,s2;
    int n1,n2,temp;
    cin>>n1>>n2;
    for(int i=0;i<n1;i++)
    {
        cin>>temp;
        s1.insert(temp);
    }

    for(int i=0;i<n2;i++)
    {
        cin>>temp;
        s2.insert(temp);
    }
    bool flag = false;
    unordered_set<int>::iterator p = s1.begin();
    while(p!=s1.end())
    {
        if(s2.find(*p)!=s2.end())
        {
            flag = true;
            break;
        }
        p++;
    }

    if(flag)
    {
        cout<<"Sets are not disjoint"<<endl;
    }
    else
    {
        cout<<"Sets are disjoint"<<endl;
    }
}