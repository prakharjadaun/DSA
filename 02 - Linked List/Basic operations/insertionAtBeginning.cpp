#include<iostream>
#include<stdlib.h>
using namespace std;

//definning the structure
struct Node 
{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val;
        next=NULL;
    }
};

//initializing the head and the tail pointers of the linked list
struct Node *head=NULL,*tail=NULL;

//inserting at the beginning of the linked list
void insert(int val)
{
    struct Node *temp;
    cout<<"Insertion at the beginning....!";
    if(head==NULL)
    {
        head = new Node(val);
        tail=head;
    }
    else 
    {
        temp = new Node(val);
        temp->next = head;
        head = temp;
    }
}

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
        cout<<"1. Insertion at the beginning"<<endl;
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