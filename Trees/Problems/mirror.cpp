#include<bits/stdc++.h>
using namespace std;

//definning the structure of the node of a binary tree
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
    struct node *root=NULL;
    int n;
    cout<<"Enter the data : ";
    cin>>n;
    if(n==-1)
    {
        return 0;
    }
    else
    {
        root = new node(n);
        cout<<"Enter the left of the "<<n<<" : ";
        root->left = create();
        cout<<"Enter the right of the "<<n<<" : ";
        root->right = create();
        return root;
    }
}

void display(struct node *root)
{
    if(root==NULL)
    return;
    //inorder traversal
    display(root->left);
    cout<<root->data<<endl;
    display(root->right);
}

//converting the tree to its mirror location
void MirrorOfTree(struct node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        struct node *temp;
        MirrorOfTree(root->left);
        MirrorOfTree(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

//main function 
int main()
{
    struct node *root= NULL;
    root = create();
    display(root);
    MirrorOfTree(root);
    display(root);
    return 0;
}