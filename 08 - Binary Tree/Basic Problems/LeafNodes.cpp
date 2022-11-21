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

//function to count the number of leaf nodes in a binary tree
int LeafNodes(struct node *root)
{
    if(!root)
        return 0;

    queue<struct node *> q;
    struct node *temp = NULL;
    q.push(root);
    int leaves = 0;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp->left==NULL && temp->right==NULL)
            leaves++;
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return leaves;
}
//we can use the similar logic to find the half nodes and the full nodes in a binary tree

//main function
int main()
{
    struct node *root = NULL;
    int temp;
    root = create();
    LevelOrder(root);
    cout<<"Number of leaf nodes : "<<LeafNodes(root)<<endl;
    return 0;
}