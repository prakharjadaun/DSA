#include<bits/stdc++.h>
using namespace std;

//definning the structure for the node of the linked list
struct node 
{
    int data;
    struct node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//declaration of the head and the tail pointer of the linked list
struct node *head = NULL,*tail = NULL;

//program to insert the node in a linked list
void insert(int val)
{
    if(head==NULL)
    {
        head = new node(val);
        tail = head;
    }
    else 
    {
        tail->next = new node(val);
        tail = tail->next;
    }
}

//display function for the linked list
void display()
{
    if(head==NULL)
    {
        cout<<"Linked list is empty...!"<<endl;
        return;
    }
    else
    {
        struct node *temp = head;
        cout<<"Linked list : ";
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}
//1 2 3 4 5 6 7
//size = 7
//nth node = 3

//function to find the nth node from the end of the linked list
void NthNodeFromEnd(int n)
{
    if(head==NULL)
    {
        cout<<"Linked list is empty....!"<<endl;
        return;
    }
    
    //computing the size of the linked list
    int s=0;
    struct node *temp=head;
    while(temp)
    {
        temp = temp->next;
        s++;
    }

    if(s<n)
    {
        cout<<"Number n is greater than the size of the linked list"<<endl;
        return;
    }
    else
    {
        if(n==s)
        {
            cout<<head->data<<endl;
        }
        else if(n==1)
        {
            cout<<tail->data<<endl;
        }
        else
        {
            temp = head;
            for(int i=0;i<s-n-1;i++)
            {
                temp = temp->next;
            }
            cout<<temp->next->data<<endl;
        }
    }
}

// main function
int main()
{
    int n,temp;
    bool flag = true;
    while(flag)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Nth node from end"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :
            {
                cout<<"Enter the data : ";
                cin>>temp;
                insert(temp);
                break;
            }
            case 2 :
            {
                display();
                break;
            }
            case 3 : 
            {
                cout<<"Enter the n : ";
                cin>>temp;
                NthNodeFromEnd(temp);
                break;
            }
            case 4 : 
            {
                flag = false;
                break;
            }
        }
    }
}