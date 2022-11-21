#include<iostream>
#include<stdlib.h>
using namespace std;

//Time complexities :
//Insertion at end : O(1)
//Insertion at the beg : O(1)
//NOTE : we have used the head and the tail pointer to take a note at the head and the last element of the circular linked list

//definning the structure
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

//head and tail variable declared globally
struct node *head = NULL,*tail = NULL;

//function to insert a node in the end of the circular linked list
void insertEnd(int val)
{
    if(head==NULL)
    {
        head = new node(val);
        tail = head;
        tail->next = head;
    }
    else
    {
        tail->next = new node(val);
        tail = tail->next;
        tail->next = head;
    }
}

//function to insert a node in the beginning of the circular linked list
void insertBeg(int val)
{
    if(head==NULL)
    {
        head = new node(val);
        tail = head;
        tail->next = head;
    }
    else
    {
        struct node *temp = new node(val);
        tail->next = temp;
        temp->next = head;
        head = temp;
    }
}

void display()
{
    //if head is null that means that our circular linked list is empty...!
    if(head==NULL)
    {
        cout<<"Circular linked list is empty...!"<<endl;
        return;
    }
    else            //else printing the linked list 
    {
        struct node *temp = head;
        cout<<temp->data<<" ";
        temp = temp->next;
        while(temp!=head)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
}

int main()
{
    //flag variable to exit the program when the user needs to
    bool flag = true;
    //two integer variables: one for getting the choice and anther one for the data has to insert in the circular linked list
    int n,temp;
    while(flag)
    {
        cout<<"\n\n1. Insertion at end"<<endl;
        cout<<"2. Insertion at beg"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :
            {
                //getting the input to insert it into the circular linked list
                cout<<"Enter the data : ";
                cin>>temp;
                insertEnd(temp);
                break;
            }
            case 2 :
            {
                //getting the input to insert it into the beginning of the circular linked list
                cout<<"Enter the data : ";
                cin>>temp;
                insertBeg(temp);
                break;
            }
            case 3 : 
            {
                //calling the display function to display all the elements of the circular linked list
                display();
                break;
            }
            case 4 :
            {
                //to exit, making the flag variable false
                flag = false;
                break;
            }
        }
    }
    return 0;
}