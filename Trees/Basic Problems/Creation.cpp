#include<iostream>
#include<stdlib.h>
using namespace std;

//definning the structure
struct Node
{
    //to store the data 
    int data;
    //to point to the left pointer
    struct Node *left;
    //to point to the right pointer
    struct Node *right;
    //to assign the initial values to the structure variables 
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//function to create a binary tree
struct Node* create()
{
    int n;
    cout<<"Enter the node : ";              //getting the node value
    cin>>n;
    if(n==-1)                //if the value is -1 then we have to 
    {
        return 0;
    }
    else
    {
        struct Node *temp = new Node(n);
        cout<<"Enter the left node of "<<n<<" : ";
        temp->left = create();
        cout<<"Enter the right node of "<<n<<" : ";
        temp->right = create();
        return temp;
    }
}

void display(struct Node* root)
{
    if(root==NULL)
    {
        
    }
}

int main()
{
    struct Node *root = NULL;
    root = create();
}