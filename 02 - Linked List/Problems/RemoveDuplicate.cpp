#include<iostream>
#include<unordered_set>
#include<stdlib.h>
// #include<bits/stdc++.h>
using namespace std;

//a structure is a user defined data type
//a structure is used to group different data types
struct Node 
{
    char data;
    struct Node* next;

    Node(char x)
    {
        data=x;
        next=NULL;
    }
};

//globally initializing the head and the tail pointer
struct Node *head=NULL,*tail=NULL;

//inserting at the end
void insert(char val)
{
    cout<<"Inserting...."<<endl;
    if(head==NULL)
    {
        head = new Node(val);
        tail = head;
    }
    else 
    {
        tail->next = new Node(val);
        tail = tail->next;
    }
}

//function to display the linked list
void display()
{
    struct Node *temp=head;
    cout<<"Linked List : ";
    while(temp)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl<<endl;
}

void removeDuplicate()
{
    if(head==NULL)
    {
        cout<<"Linked list is empty..!"<<endl;
        return;
    }
    else
    {
        unordered_set<char> s;
        struct Node *temp = head,*prev=NULL;

        while(temp)
        {
            if(s.find(temp->data)!=s.end())
            {
                prev->next = temp->next;
                delete temp;
            }
            else
            {
                s.insert(temp->data);
                prev = temp;
            }
            temp = temp->next;
        }
    }
}

int main()
{
    bool flag=true;
    int n;
    char val;
    while(flag)
    {
        cout<<"Choose an option : "<<endl;
        cout<<"1. Insertion."<<endl;
        cout<<"2. Remove Duplicate"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>n;
        switch(n)
        {
            case 1 : 
            {
                cout<<"Enter a number you have to insert : ";
                cin>>val;
                insert(val);
                break;
            }
            case 2 : 
            {
                removeDuplicate();
                break;
            }
            case 3 :
            {
                display();
                break;
            }

            case 4 :
            {
                flag=false;
                break;
            }
        }
    }
}


