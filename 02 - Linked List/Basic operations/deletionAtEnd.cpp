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
//deleting the end element of the linked list
void deletionAtEnd()
{
    if(head==NULL)
    {
        cout<<"LinkedList is empty"<<endl;
        return;
    }

    struct Node *ptr=head,*ptr1;
    while(ptr->next!=NULL)
    {
        ptr1 = ptr;
        ptr = ptr->next;
    }

    ptr1->next=NULL;
    delete ptr;
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
        cout<<"2. Deletion at the end"<<endl;
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
                deletionAtEnd();
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