#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<char> s;
    string str;
    //using getline() function because cin can only take one word input at a time
    getline(cin,str);

    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
        {
            //pushing words into the stack
            s.push(str[i]);
        }
        else
        {
            //whenever a space is encountered we will empty the whole stack, basically print the previous word in reverse manner
            while(!s.empty())
            {
                cout<<s.top();
                s.pop();
            }
            cout<<" ";
        }
    }
    //printing the last word in reverse order.
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    return 0;
}