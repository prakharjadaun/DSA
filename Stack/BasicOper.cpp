#include<bits/stdc++.h>
using namespace std;
//definning the structure
struct node 
{
    int data;
    struct node *next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct node *top = NULL;

//to push element into the stack
void push(int val)
{
    if(top==NULL)
    {
        top = new node(val);
    }
    else
    {
        struct node *temp = new node(val);
        temp->next = top;
        top = temp;
    }
}

//to pop element into the stack
void pop()
{
    if(top==NULL)
    {
        cout<<"Stack is empty..!"<<endl;
    }
    else
    {
        cout<<top->data<<" : popped!"<<endl;
        struct node *temp = top;
        top = top->next;
        delete temp;
    }
}

//displaying the stack
void display()
{
    if(top==NULL)
    {
        cout<<"Stack is empty....!"<<endl;
    }
    else
    {
        struct node *temp = top;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
int main()
{
    push(1);
    push(2);
    push(3);
    push(5);
    display();
    pop();
    display();
    pop();
}