#include<iostream>
using namespace std;

//definning the structure for a node in the linked list
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

//definning the head and tail as NULL initially 
struct node *head = NULL,*tail = NULL;

//function to insert a node into the linked list
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

//function to display the linked list 
void display()
{
    //if the head is null then it points that there is no node present in the linked list
    if(head==NULL)
    {
        cout<<"Linked list is empty...!"<<endl;
        return;
    }
    else
    {
        //if head is not pointing to the NULL, then it points that there exist atleast one node
        //displaying the nodes of the linked list
        cout<<"\n\nLinked list : ";
        struct node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

//function to rotate the linked list 
void rotate(int n)
{
    //if head is null then the linked list is empty...!
    if(head==NULL)
    {
        cout<<"Linked is empty...!"<<endl;
        return;
    }
    else
    {
        //else rotating the linked list according to the n passed to the function 
        struct node *temp = head;
        struct node *temp2 = head;
        for(int i=1;i<=n;i++)
        {
            if(i<n)
            temp2 = temp2->next;
            temp = temp->next;
        }

        temp2->next = NULL;
        tail->next = head;
        head = temp;
    }

}

int main()
{
    int n,temp;
    bool flag = true;
    while(flag)
    {
        //choices of the program
        cout<<"1. Insert"<<endl;
        cout<<"2. Rotate"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>n;
        switch(n)
        {
            case 1 :
            {
                //getting the value for creating a node
                cout<<"Enter the value : ";
                cin>>temp;
                insert(temp);
                break;
            }
            case 2 : 
            {
                //getting the number to rotate
                cout<<"Enter n (for rotation) : ";
                cin>>temp;
                rotate(n);
                break;
            }
            case 3 : 
            {
                //displaying the elements of the linked list
                display();
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