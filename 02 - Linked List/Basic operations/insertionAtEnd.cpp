#include<iostream>
#include<stdlib.h>
using namespace std;

//a structure is a user defined data type
//a structure is used to group different data types
struct Node 
{
    int data;
    struct Node* next;

    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

//globally initializing the head and the tail pointer
struct Node *head=NULL,*tail=NULL;

//inserting at the end
void insert(int val)
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

int main()
{
    bool flag=true;
    int n;
    int val;
    while(flag)
    {
        cout<<"Choose an option : "<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Exit"<<endl;
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
                display();
                break;
            }

            case 3 :
            {
                flag=false;
                break;
            }
        }
    }
}