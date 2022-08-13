#include<bits/stdc++.h>
using namespace std;

stack<int> s1,s2;

void insert(int val)
{
    while(!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(val);

    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}

void pop()
{
    if(s1.empty())
    {
        cout<<"Queue is empty..!"<<endl;
        return;
    }

    cout<<"Front deleted : "<<s1.top()<<endl;
    s1.pop();
}

void top()
{
    if(s1.empty())
    {
        cout<<"Queue is empty...!"<<endl;
        return;
    }
    cout<<"Front : "<<s1.top()<<endl;
}

int main()
{
    queue<int> q;
    int n,temp,k;
    cin>>n;
    while(n--)
    {
        cin>>k;
        if(k==1)
        {
            cin>>temp;
            insert(temp);
        }
        else if(k==2)
        {
            pop();
        }
        else 
        {
            top();
        }
    }
}