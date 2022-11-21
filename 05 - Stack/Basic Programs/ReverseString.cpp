#include<bits/stdc++.h>
using namespace std;
int main()
{
    //definning the string
    string str;
    //getting the input
    cin>>str;

    //initializing the stack
    stack<char>  s;
    //pushing all the characters into the stack
    for(int i=0;i<str.length();i++) 
    {
        s.push(str[i]);
    }

    //printing all the characters stored inside the stack
    cout<<"Reverse of the string is : ";
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }

    return 0;
}