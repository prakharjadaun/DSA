#include<iostream>
#include<stack>
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

//function to check if a single linked list is palindrome or not
void checkPalindrome()
{
    //checking if head is equal to null or not
    if(head==NULL)
    {
        cout<<"Linked List is empty...!"<<endl;
        return;
    }
    else
    {
        struct Node *temp=head;
        stack<char> s;
        bool flag = true;
        //initially pushing all the elements into the stack
        while(temp)
        {
            s.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(temp)
        {
            if(temp->data != s.top())
            {
                flag = false;
                cout<<"List is not a Palindrome"<<endl;
                break;
            }
            else
            {
                temp = temp->next;
                s.pop();
            }
        }

        if(flag)
        {
            cout<<"List is Palindrome"<<endl;
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
        cout<<"2. Check Palindrome."<<endl;
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
                checkPalindrome();
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