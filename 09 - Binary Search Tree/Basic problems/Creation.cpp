#include<iostream>
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
}