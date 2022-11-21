#include<bits/stdc++.h>
using namespace std;

//NOTE : all the traversals that is inorder,postorder and preorder are done by using the recursion 

//definition of the structure
struct node 
{
    int data;
    struct node *left,*right;
    //constructor to assign the inital values
    node(int val)
    {
        //assiging the passed val to the data part of the node
        data = val;
        //assigning NULL to the left and the right pointer
        left = NULL;
        right = NULL;
    }
};

//function to create a binary tree
struct node *create()
{
    int n;
    struct node *temp;
    cout<<"Enter the node : ";
    cin>>n;
    //if the choice is -1 then we don't want to extend our tree
    if(n==-1)
        return 0;   
    else
    {
        //creating a node of the binary tree
        temp = new node(n);
        cout<<"Enter the left child of "<<n<<" : "<<endl;
        temp->left = create();
        cout<<"Enter the right child of "<<n<<" : "<<endl;
        temp->right = create();
        return temp;
    }
}

//function for inorder traversal in binary tree
void Inorder(struct node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<root->data<<endl;
        Inorder(root->right);
    }
}

//function for preorder traversal in binary tree
void Preorder(struct node *root)
{
    if(root)
    {
        cout<<root->data<<endl;
        Preorder(root->left);
        Preorder(root->right);
    }
}
//function for postorder traversal in binary tree
void Postorder(struct node *root)
{
    if(root)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<endl;
    }
}

//main function 
int main()
{
    //creating a pointer to the node of the binary tree
    struct node *root = NULL;
    //calling the create() function to create a binary tree
    root = create();
    //printing the elements of the tree using inorder traversal
    cout<<"Inorder Traversal"<<endl;
    Inorder(root);
    //printing the element of the tree using preorder traversal
    cout<<"\n\nPreorder Traversal"<<endl;
    Preorder(root);
    //printing the element of the tree using the postorder traversal
    cout<<"\n\nPostorder Traversal"<<endl;
    Postorder(root);
    return 0;
}