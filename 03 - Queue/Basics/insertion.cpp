#include<iostream>
using namespace std;

//defining the structure of the node of a queue
struct Node
{
    int data;
    struct Node *next;
    Node(int val)
    {
        data = val ;
        next = NULL;
    }
};

//initializing the the head and the tail elements of the queue
struct Node *front = NULL,*rear=NULL;

//to insert elements into the rear end of the queue
void enqueue(int data)
{
    if(front==NULL)
    {
        front = new Node(data);
        rear = front;
    }
    else
    {
        rear->next = new Node(data);
        rear = rear->next;
    }
}

//to print the front and remove the front element of the queue
void dequeue()
{
    if(front==NULL)
    {
        cout<<"Queue is empty...!"<<endl;
    }
    else
    {
        cout<<front->data<<" is at the front of the queue"<<endl;
        struct Node *temp = front;
        front = front->next;
        delete temp;
    }
}

//prints the front of the queue and do not deletes it
void Front()
{
    if(front==NULL)
    {
        cout<<"Queue is empty...!"<<endl;
        return;
    }
    else
    {
        cout<<front->data<<" is at the front"<<endl;
    }
}

//to print the rear element of the queue
void Rear()
{
    if(front==NULL)
    {
        cout<<"Queue is empty...!"<<endl;
        return;
    }
    else
    {
        cout<<rear->data<<" is at the rear of the queue"<<endl;
    }
}
//to check if the queue is empty or not
bool isEmpty()
{
    if(front==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//to get the size of the queue
int SIze()
{
    int n=0;
    if(front==NULL)
    {
        return n;
    }
    else
    {
        struct Node *temp = front;
        while(temp)
        {
            n++;
            temp = temp->next;
        }
    }
    return n;
}

int main()
{
    bool flag = true;
    int n,val;
    while(flag)
    {
        cout<<"Choose an option : "<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Front"<<endl;
        cout<<"4. Rear"<<endl;
        cout<<"5. ISEmpty"<<endl;
        cout<<"6. Size"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>n;
        switch(n)
        {
            case 1 :
            {
                cout<<"Enter an element to insert : ";
                cin>>val;
                enqueue(val);
                break;
            }
            case 2 : 
            {
                dequeue();
                break;
            }
            case 3 :
            {
                Front();
                break;
            }
            case 4 :
            {
                Rear();
                break;
            }
            case 5 :
            {
                if(isEmpty())
                {
                    cout<<"Queue is empty..!"<<endl;
                }
                else 
                {
                    cout<<"Queue is not empty..!"<<endl;
                }
                break;
            }
            case 6 : 
            {
                cout<<"Size of the queue : "<<SIze()<<endl;
                break;
            }
            case 7 :
            {
                flag = false;
                break;
            }
        }
    }
}