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

//function returns boolean value on the basis if the value if found or not
//complexity : O(n) worst for skew tree
//space complexity : O(n) for recursive stack
bool Searching(struct node *root,int val)
{
    if(!root)
    {
        return false;
    }
    if(root->data == val)
    {
        return true;
    }
    struct node *temp = NULL;
    temp = root;
    while(temp!=NULL)
    {
        if(temp->data < val)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
            cout<<"hello"<<endl;
        }
        if(temp->data == val && temp!=NULL)
            return true;    
    }
    return false;
}

//main function
int main()
{
    struct node *root = NULL;
    //inserting elements into the tree
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,2);
    root = insert(root,1);
    // root = insert(root,4);

    //printing the elements of the binary search tree using inorder traversal
    InorderTraversal(root);
    
    if(Searching(root,-2))
    {
        cout<<"Element found!"<<endl;
    }
    else
    {
        cout<<"Element not found!"<<endl;
    }
    return 0;
}