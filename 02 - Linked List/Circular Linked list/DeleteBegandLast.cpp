#include<iostream>
#include<stdlib.h>
using namespace std;

//definition of a structure
struct node 
{
    int data;
    struct node *next;
    node(int val)       //assigning the values passed while creating a node of a circular linked list
    {
        data = val;
        next = NULL;
    }
};

struct node *head=NULL,*tail=NULL;

//inserting a new node into a circular linked list
void insert(int val)
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

//function to delete the last element of the circular linked list
void DeleteLast()
{
    if(head==NULL)
    {
        cout<<"Circular linked list is empty...!"<<endl;
        return;
    }
    else if(head==tail)
    {
        delete head;
        head = NULL;
    }
    else
    {
        struct node *temp = head->next;
        while(temp->next->next==head)
        {
            temp = temp->next;
        }

        struct node *temp2= temp->next;
        temp->next = head;
        delete temp2;
    }
}

//function to delete the first element of the circular linked list.
void Deletefirst()
{
    if(head==NULL)
    {
        cout<<"Circular linked list is empty...!"<<endl;
        return;
    }
    else if(tail==head)
    {
        delete tail;
        head = NULL;
        tail = NULL;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
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
        cout<<"\n\n1. Insertion"<<endl;
        cout<<"2. Delete First Element."<<endl;
        cout<<"3. Delete Last Element."<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :
            {
                //getting the input to insert it into the circular linked list
                cout<<"Enter the data : ";
                cin>>temp;
                insert(temp);
                break;
            }
            case 2 :
            {
                //to delete the first element of the circular linked list
                Deletefirst();
                break;
            }
            case 3:
            {
                //to delete the last element of the circular linked list
                DeleteLast();
                break;
            }
            case 4 : 
            {
                //calling the display function to display all the elements of the circular linked list
                display();
                break;
            }
            case 5 :
            {
                //to exit, making the flag variable false
                flag = false;
                break;
            }
        }
    }
    return 0;
}