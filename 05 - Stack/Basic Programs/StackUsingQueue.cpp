#include<bits/stdc++.h>
using namespace std;

queue<int> q1,q2;

//to push into the stack
void Push(int val)
{
    while(!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    q1.push(val);

    while(!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

//popping the element 
void Pop()
{
    if(q1.empty())
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else
    {
        cout<<"Top Element : "<<q1.front()<<endl;
        q1.pop();
    }
}

void display()
{
    if(q1.empty())
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else
    {
        queue<int> temp = q1;
        while(!temp.empty())
        {
            cout<<temp.front()<<" ";
            temp.pop();
        }
        cout<<endl;
    }
}

int main()
{
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    Push(5);

    display();

    Pop();
    Pop();

    display();

    return 0;
}