#include<iostream>
#include<stdlib.h>
using namespace std;

//definning the structure
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

//function to create a binary tree
struct node *create()
{
    int n;
    struct node *temp = NULL;
    cout<<"Enter the value : ";
    cin>>n;
    //if the entered value is -1, then no node is created
    if(n==-1)
    {
        return 0;
    }
    else                //in the else part we create the node and calls create() function recursively to create the left and right subtree of the bianry tree
    {
        temp = new node(n);
        cout<<"Enter the left of the "<<n<<" : "<<endl;
        temp->left = create();
        cout<<"Enter the right of the node "<<n<<" : "<<endl;
        temp->right = create();
        return temp;
    }
}

//preorder Traversal of the binary tree
void Preorder(struct node *root)
{
    if(root)
    {
        cout<<root->data<<endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}

//inorder Traversal of the binary tree
void Inorder(struct node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<root->data<<endl;
        Inorder(root->right);
    }
}

//postorder traversal of the binary tree
void postorder(struct node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}

int NumberOfNodes(struct node *root)
{
    static int counter=0;
    if(root)
    {
        NumberOfNodes(root->left);
        NumberOfNodes(root->right);
        counter++;
    }
    return counter;
}

int main()
{
    struct node *root = NULL;
    root = create();
    cout<<"\n\nInorder Traversal"<<endl;
    Inorder(root);

    // cout<<"\n\nPreorder Traversal"<<endl;
    // Preorder(root);

    // cout<<"\n\nPostorder Traversal"<<endl;
    // postorder(root);
    cout<<"Number of nodes in the binary tree : "<<NumberOfNodes(root)<<endl;
    return 0;
}