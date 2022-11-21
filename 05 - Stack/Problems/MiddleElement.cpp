#include<bits/stdc++.h>
using namespace std;

//defininning the structure
struct node
{
    int data;
    struct node* prev;
    struct node *next;

    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//initializing the top and the middle pointers as NULL
struct node *top = NULL,*mid=NULL;
int SIZE=0;

//to push into the stack
void push(int val)
{
    if(top==NULL)
    {
        top = new node(val);
        mid = top;
        SIZE++;
    }
    else
    {
        struct node *temp = new node(val);
        top->prev = temp;
        temp->next = top;
        top = temp;
        if(SIZE%2==1)
        {
            mid = mid->prev;
        }
        SIZE++;
    }
    cout<<"Pushed...!"<<endl;
}

//to print the middle element of the stack
void findMiddle()
{
    if(top==NULL)
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else
    {
        cout<<"Middle element : "<<mid->data<<endl;
    }
}

//to pop the top element of the stack
void pop()
{
    if(top==NULL)
    {
        cout<<"Stack is empty....!"<<endl;
    }
    else
    {
        struct node *temp=top;
        top->next->prev = NULL;
        top = top->next;
        cout<<temp->data<<" : Popped"<<endl;
        delete temp;
        SIZE--;
        if(SIZE%2==0)
        {
            mid = mid->next;
        }
    }
}

//to delete the middle element of the stack
void deleteMiddle()
{
    if(top==NULL)
    {
        cout<<"Stack is empty...!"<<endl;
    }
    else if(top->next==NULL)
    {
        SIZE=0;
        cout<<top->data<<" : deleted"<<endl;
        delete top;
        top=NULL;
    }
    else
    {
        struct node *temp = mid;
        if(SIZE%2==1)
        {
            temp->prev->next = mid->next;
            mid->next->prev = temp->prev;
            mid = mid->next;
            delete temp;
            SIZE--;
        }
        else
        {
            temp->prev->next = mid->next;
            mid->next->prev = temp->prev;
            mid =  mid->prev;
            SIZE--;
        }
    }
}

//to display the stack
void display()
{
    if(top==NULL)
    {
        cout<<"STack is empty...!"<<endl;
    }
    else
    {
        struct node *temp = top;
        while(temp)
        {
            cout<<temp->data<<endl;
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
    push(4);
    push(5);
    display();

    findMiddle();
    deleteMiddle();

    display();
    findMiddle();
    deleteMiddle();

    display();
    findMiddle();

    return 0;
}