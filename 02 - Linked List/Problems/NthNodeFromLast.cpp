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
//to calculate the length of the list
int lengthOfList()
{
    if(head==NULL)
    {
        return 0;
    }
    int counter=0;
    struct Node *temp=head;
    while(temp)
    {
        counter++;
        temp=temp->next;
    }
    return counter;
}

//to get the nth node from the last
void NthNodeFromLast(int num)
{
    if(head==NULL)
    {
        cout<<"List is empty..!"<<endl;
    }
    else
    {
        struct Node *temp = head; 
        for(int i=0;i<lengthOfList()-num;i++)
        {
            temp = temp->next;
        }
        cout<<num<<"th node from last : "<<temp->data<<endl;
    }
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
        cout<<"2. Nth node from last"<<endl;
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
                int num;
                cout<<"Enter the nth node you want from last : ";
                cin>>num;
                NthNodeFromLast(num);
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