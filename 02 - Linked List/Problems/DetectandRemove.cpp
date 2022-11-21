#include<iostream>
#include<stdlib.h>
#include<unordered_set>
#include<unordered_map>
// #include<bits/stdc++.h>
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

//detecting a loop in a linked list
void DetectandRemoveLoop()
{
    if(head)
    {
        bool flag=false;
        unordered_map<struct Node*,int> m;
        struct Node *temp=head,*last=NULL;
        while(temp)
        {
            if(m.find(temp)==m.end())
            {
                m[temp]++;
                last = temp;
                temp = temp->next;
            }
            else 
            {
                last->next=NULL;
                cout<<"Loop removed...!"<<endl;
                flag = true;
                break;
            }
        }

        if(!flag)
        {
            cout<<"No Loop Detected..!"<<endl;
        }
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
        cout<<"1. Insertion."<<endl;
        cout<<"2. Detect and remove Loop."<<endl;
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
                //uncomment this line to form a loop in the list
                tail->next = head;
                //Note : if you uncomment the line then your display function will keep on printing the list because there is no end of the list remained.
                DetectandRemoveLoop();
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