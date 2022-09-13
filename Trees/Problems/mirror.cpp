#include<iostream>
#include<stdlib.h>
using namespace std;

//definning the structure of the node of the binary tree
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

//creating a binary tree using recursion
struct node *create()
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    if(data==-1)
    {
        return 0;
    }
    else
    {
        struct node *temp = new node(data);
        cout<<"Enter the left of "<<data<<" : ";
        temp->left = create();
        cout<<"Enter the rigt of "<<data<<" : ";
        temp->right = create();
        return temp;
    }
}

//preorder traversal
void Preorder(struct node *root)
{
    if(root)
    {
        cout<<root->data<<endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}

//transforming the binary tree into the mirror of it
void mirrorOfTree(struct node *root)
{
    if(root)
    {
        struct node *temp=NULL;
        mirrorOfTree(root->left);
        mirrorOfTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    else
    {
        return;
    }
}

//main function 
int main()
{
    struct node *root= NULL;
    root= create();
    cout<<"\nPreorder Traversal : "<<endl;
    Preorder(root);
    cout<<"\nMirroring the binary tree.....!"<<endl;
    mirrorOfTree(root);
    cout<<"\nPreorder Traversal : "<<endl;
    Preorder(root);
    return 0;
}