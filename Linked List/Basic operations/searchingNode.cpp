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

//searching item in linked list using iteration 
void SearchIter(int num)
{

    if(head==NULL)
    {
        cout<<"The linked list is empty"<<endl;
    }
    else 
    {
        bool flag = false;
        struct Node *temp = head;
        while(temp)
        {
            if(temp->data== num)
            {
                cout<<"Element found....!"<<endl;
                flag = true;
                break;
            }
            temp=temp->next;
        }
        if(flag==false)
        {
            cout<<"Element not found...!"<<endl;
        }
    }
}



//Searching an item using recursion
void SearchRec(struct Node *node,int num)
{
    if(node==NULL)
    {
        return;
    }
    else 
    {
        if(node->data==num)
        {
            cout<<"Element found...!"<<endl;
        }
        else
        {
            SearchRec(node->next,num);
        }
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
        cout<<"2. Search using iteration"<<endl;
        cout<<"3. Search using recursion"<<endl;
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
                SearchIter(3);
                break;
            }
            case 3 :
            {
                SearchRec(head,3);
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