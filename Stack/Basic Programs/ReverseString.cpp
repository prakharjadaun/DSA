#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;

    stack<char>  s;
    for(int i=0;i<str.length();i++)
    {
        s.push(str[i]);
    }

    cout<<"Reverse of the string is : ";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }

    return 0;
}