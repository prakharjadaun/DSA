#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

//definning the structure of the node of a tree
struct node 
{
    int data;
    struct node *left,*right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//function to create a binary tree using recursion
struct node *create()
{
    int n;
    struct node *temp=NULL;
    cout<<"Enter the node : ";
    cin>>n;
    //if the input is -1, then no node will be created
    if(n==-1)
    {
        return 0;
    }
    else
    {
        //creating a new node of the binary tree
        temp = new node(n);
        //creating the left subtree of the n
        cout<<"Enter the left of "<<n<<" : ";
        temp->left = create();
        //creating the right subtree of the n 
        cout<<"Enter the right of "<<n<<" : ";
        temp->right = create();
        return temp;
    }
}

//function to perform inorder traversal without recursion
void Inorder(struct node *root)
{
    if(root==NULL)
    {
        cout<<"Binary tree is empty...!"<<endl;
        return;
    }

    stack<struct node *> s;
    struct node *curr = root;
    while(s.empty()==false || curr!=NULL)
    {
        while(curr!=NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        cout<<curr->data<<endl;
        curr = curr->right;
    }
}


int main()
{
    //creating the pointer to the root node of the binary tree
    struct node *root= NULL;

    root = create();
    Inorder(root);
    return 0;
}