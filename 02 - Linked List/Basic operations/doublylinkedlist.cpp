#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
    Node(int d)
    {
        data = d;
        prev = NULL;
        next = NULL;
    }
};

struct Node *head = NULL;
struct Node *tail = NULL;

//to insert element at the front of the doubly linked list
void insertFront(int val)
{
    if(head==NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else
    {
        struct Node *temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

//to insert element at the end of the doubly linked list
void insertEnd(int val)
{
    if(head==NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else
    {
        struct Node *temp = new Node(val);
        temp->prev = tail;
        tail->next = temp;
        tail = tail->next;
    }
}

//to display the doubly linked list from front
void displayForward()
{
    if(head)
    {
        struct Node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    else
    {
        cout<<"List is empty...!"<<endl;
    }
}

//to display the doubly linked list from back
void displayBack()
{
    if(head)
    {
        struct Node *temp = tail;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->prev;
        }
        cout<<endl;
    }
    else
    {
        cout<<"List is empty...!"<<endl;
    }
}

//to get the front element of the doubly linked list
void front()
{
    if(head)
    {
        cout<<"Front : "<<head->data<<endl;
    }
    else
    {
        cout<<"List is empty..!"<<endl;
    }
}

//to get the rear element of the doubly linked list
void rear()
{
    if(head)
    {
        cout<<"Rear : "<<tail->data<<endl;
    }
    else
    {
        cout<<"List is empty...!"<<endl;
    }
}

//to delete the front element 
void deleteFront()
{
    if(head)
    {
        struct Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    else
    {
        cout<<"List is empty..!"<<endl;
    }
}

//to delete the rear element 
void deleteRear()
{
    if(head)
    {
        struct Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
    else
    {
        cout<<"List is empty..!"<<endl;
    }
}

int main()
{
    insertFront(3);
    insertFront(2);
    insertFront(1);
    insertEnd(4);
    insertEnd(5);
    insertEnd(6);
    displayForward();
    displayBack();

    deleteRear();
    displayBack();

    deleteFront();
    displayForward();
}