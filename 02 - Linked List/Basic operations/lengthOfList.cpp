#include<iostream>
using namespace std;

//definning the structure
struct Node 
{
    int data;
    struct Node* next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

//initializing the head and the tail pointers 
struct Node *head=NULL,*tail=NULL;

//display function 
void display()
{
    if(head!=NULL)
    {
        cout<<"Linked List : ";
        struct Node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    else 
    {
        cout<<"Linked list is empty"<<endl;
    }
}

//insertion at the end 
void insert(int val)
{
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

//calculating the length using iteration 
int lengthIter()
{
    int counter=0;
    if(head==NULL)
    {
        cout<<"The linked list is empty"<<endl;
    }
    else 
    {
        struct Node *temp = head;
        while(temp)
        {
            counter++;
            temp=temp->next;
        }
    }
    return counter;
}

//calculating the length using recursion
int lengthRec(struct Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    else 
    {
        return 1+lengthRec(node->next);
    }
}

//main function 
int main()
{
    bool flag=true;
    int n;
    int val;
    while(flag)
    {
        cout<<"Choose an option : "<<endl;
        cout<<"1. Insertion"<<endl;
        cout<<"2. length using iteration"<<endl;
        cout<<"3. Length using recursion"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
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
                cout<<"Length using iteration : "<<lengthIter()<<endl;
                break;
            }
            case 3 :
            {
                cout<<"Length using recursion : "<<lengthRec(head)<<endl;
                break;
            }
            case 4 :
            {
                display();
                break;
            }

            case 5 :
            {
                flag=false;
                break;
            }
        }
    }
}