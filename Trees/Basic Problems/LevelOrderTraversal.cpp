#include<iostream>
#include<stdlib.h>
#include<queue>
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

//function to perform the level order traversal
void LevelOrderTraversal(struct node *root)
{
    queue<struct node*> q;
    struct node *temp = NULL;
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        cout<<temp->data<<endl;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}
//function to display the inorder traversal of binary tree
void Inorder(struct node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<root->data<<endl;
        Inorder(root->right);
    }
}

int main()
{
    //creating the pointer to the root node of the binary tree
    struct node *root= NULL;

    root = create();
    LevelOrderTraversal(root);
    return 0;
}