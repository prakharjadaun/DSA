#include<bits/stdc++.h>
using namespace std;
//priority queue using linked list has following time complexities in following operations : 
// push : O(n)
// pop : O(1)
// peek: O(1)


//definning the structure
struct Node
{
    int data;
    int priority;
    struct Node *next;

    Node(int d,int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }
};

struct Node *head = NULL;
struct Node *tail = NULL;
int maxP = INT_MIN;
void push(int val, int p)
{
    if(head==NULL)
    {
        head = new Node(val,p);
        tail = head;
        maxP = p;
    }
    else if(head->priority > p)
    {
        struct Node *temp = new Node(val,p);
        temp ->next = head;
        head = temp;
    }
    else if(maxP < p)
    {
        tail->next = new Node(val,p);
        tail = tail->next;
        maxP = p;
    }
    else
    {
        struct Node *temp = head;
        struct Node *temp2 = new Node(val,p);
        struct Node *temp3;
        while(temp->next!=NULL && temp->next->priority < p)
        {
            temp = temp->next;
        }

        temp3 = temp->next;
        temp->next = temp2;
        temp2->next = temp3;
    }
}

//function to get the top element of the priority queue
void peek()
{
    if(head)
    {
        cout<<"Top element : "<<head->data<<endl;
    }
    else
    {
        cout<<"Priority queue is empty"<<endl;
    }
}

//function to delete the element with the top priority
void pop()
{
    if(head)
    {
        struct Node *temp = head;
        head = head->next;
        delete temp;
        
    }
    else
    {
        cout<<"Priority Queue is empty"<<endl;
    }
}
//displaying the priority queue
void display()
{
    if(head)
    {
        struct Node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" : "<<temp->priority<<endl;
            temp = temp->next;
        }
        cout<<endl;
    }
    else
    {
        cout<<"Queue is empty..!"<<endl;
    }
}
int main()
{
    push(1,0);
    push(2,1);
    push(3,3);
    push(4,4);
    display();
    push(9,2);
    display();
    pop();
    peek();
    display();

}