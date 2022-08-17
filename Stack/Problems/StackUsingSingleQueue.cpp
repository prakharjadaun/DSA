#include<bits/stdc++.h>
using namespace std;
queue<int> q;
//to push into the stack
void PUSH(int val)
{
    int s = q.size();
    q.push(val);

    for(int i=0;i<s;i++)
    {
        q.push(q.front());
        q.pop();
    }
}

//to pop the element from the stack
void POP()
{
    if(q.empty())
    {
        cout<<"Stack is empty...!"<<endl;

    }
    else
    {
        cout<<q.front()<<" : Popped"<<endl;
        q.pop();
    }
}

void TOP()
{
    if(q.empty())
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else
    {
        cout<<q.front()<<" : TOP"<<endl;
    }
}

//to display the stack
void display()
{
    if(q.empty())
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else
    {
        queue<int> temp = q;
        while(!temp.empty())
        {
            cout<<temp.front()<<endl;
            temp.pop();
        }
    }
}

int main()
{
    PUSH(1);
    PUSH(2);
    PUSH(3);
    PUSH(4);
    display();
    TOP();
    POP();
    TOP();
    display();
}