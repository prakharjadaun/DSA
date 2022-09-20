#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<climits>
#include<queue>
#include<stack>
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

//time complexity : O(n)
//space complexity : O(n)
void LevelOrder(struct node *root)
{
    if(root==NULL)
    {
        cout<<"Binary Tree is empty....!"<<endl;
        return;
    }
    //creating a queue to implement the level order traversal
    queue<struct node *> q;
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

//function to print all the ancestors of a node
int PrintAllAncestor(struct node *root,struct node *n)
{
    if(root==NULL)
    return 0;

    if((root->left->data == n->data)||(root->right->data == n->data)||(PrintAllAncestor(root->left,n))||(PrintAllAncestor(root->right,n)))
    {
        cout<<root->data<<endl;
        return 1;
    }

    return 0;
}

//main function
int main()
{
    struct node *root = NULL,*n=NULL;
    int temp;
    root = create();
    //level order traversal function
    LevelOrder(root);
    //getting the value of the node for which we have to print all of its ancestor
    cout<<"Enter a node : ";
    cin>>temp;
    n = new node(temp);
    //calling the function to print all the ancestor of a node 
    PrintAllAncestor(root,n);

    return 0;
}