#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

//initializing the head and the tail variable 
struct Node *head = NULL,*tail=NULL;

//function to insert data at the end of the linked list
void insertAtEnd(int val)
{
    cout<<"Inserting at the end....."<<endl;
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
//function to insert at the middle of the list
void insertAtMid(int val)
{
    cout<<"INSERTING AT THE MIDDLE OF THE LIST...."<<endl;
    struct Node *temp,*temp2,*mid;
    mid = new Node(val);
    temp = head;
    temp2 = head;
    while(temp->next->next!=NULL)
    {
        temp2 = temp2->next;
        temp = temp->next;
        if(temp->next!=NULL)
        {
            temp = temp->next;
        }
    }
    mid ->next = temp2->next;
    temp2->next = mid;
}

//function to display the linked list
void display()
{
    struct Node *temp=head;
    cout<<"Linked list : ";
    while(temp)
    {
        cout<<temp->data<<" ";
        temp= temp->next;
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
        cout<<"1. Insertion at the end"<<endl;
        cout<<"2. Insertion at the middle"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>n;
        switch(n)
        {
            case 1 : 
            {
                cout<<"Enter a number you have to insert : ";
                cin>>val;
                insertAtEnd(val);
                break;
            }
            case 2 : 
            {
                cout<<"Enter a number to insert at the middle : ";
                cin>>val;
                insertAtMid(val);
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