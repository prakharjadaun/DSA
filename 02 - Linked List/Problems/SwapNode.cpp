#include<iostream>

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

void SwapNode(char a,char b)
{
    if(head==NULL)
    {
        cout<<"List is empty..!"<<endl;
        return;
    }

    //checking if a and b are same. if a and b are same then there is no use of swapping
    if(a==b)
        return;
    
    //checking if a and b are present in list or not
    struct Node *prevA=NULL,*currA = head;
    struct Node *prevB=NULL,*currB = head;

    //checking if a is present or not
    while(currA && currA->data!=a)
    {
        prevA = currA;
        currA = currA->next;
    }

    //checking if b is present or not
    while(currB && currB->data!=b)
    {
        prevB = currB;
        currB = currB->next;
    }

    //if either of them is not present return 
    if(currA==NULL && currB==NULL)
    {
        cout<<"Not present"<<endl;
        return;
    }

    //checking if a is head or not
    if(prevA!=NULL)
        prevA->next = currB;
    else
        head = currB;

    if(prevB!=NULL)
        prevB->next = currA;
    else
        head = currA;

    struct Node *temp;
    temp = currA->next;
    currA->next = currB->next;
    currB->next = temp;

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
        cout<<"2. Swap elements"<<endl;
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
                SwapNode('a','d');
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