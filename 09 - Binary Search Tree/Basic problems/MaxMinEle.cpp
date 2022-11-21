#include<iostream>
#include<climits>
using namespace std;

//definning the structure of the node of a binary search tree
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

//function to insert the data into the binary search tree
struct node *insert(struct node *root, int val)
{
    if(root==NULL)
    {
        root = new node(val);
    }
    else
    {
        if(val<root->data)
            root->left = insert(root->left,val);
        else if(val>root->data)
            root->right = insert(root->right,val);
    }
    return root;
}

//function to traverse the binary search tree
//inorder traversal gives the sorted element in the output
void InorderTraversal(struct node *root)
{
    if(root)
    {
        InorderTraversal(root->left);
        cout<<root->data<<endl;
        InorderTraversal(root->right);
    }
}

//function to print the maximum element of the binary search tree
void MaxElementOfTree(struct node *root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty...!"<<endl;
        return;
    }

    struct node *temp = root;
    while(temp->right!=NULL)
    {
        temp = temp->right;
    }
    cout<<"Max element in the binary search tree : "<<temp->data<<endl;
}

//function to find the minimum element of the binary search tree
void MinElementOfTree(struct node *root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty..!"<<endl;
        return;
    }

    struct node *temp = root;
    while(temp->left!=NULL)
    {
        temp = temp->left;
    }
    cout<<"Min element in the binary search tree : "<<temp->data<<endl;
}

int main()
{
    struct node *root = NULL;
    //inserting elements into the tree
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,2);
    root = insert(root,1);
    root = insert(root,4);

    //printing the elements of the binary search tree using inorder traversal
    InorderTraversal(root);
    //printing the max and the minimum element of the binary tree
    MaxElementOfTree(root);
    MinElementOfTree(root);
}