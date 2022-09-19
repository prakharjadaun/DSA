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
//steps of deletion
//1. find the deepest node of the binary tree
//2. find the node you have to delete
//3. swap the deepest node and the node that you want to delete such that the node you want to delete becomes the deepest node 
//4. delete the deepest node

void Deletion(struct node *root,int val)
{
    if(!root)
    {
        cout<<"Binary Tree is empty....!"<<endl;
        return;
    }    

    struct node *temp = NULL,*deepest = NULL, *n;
    bool flag = false;
    queue<struct node *> q;
    q.push(root);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->data == val)
        {
            n = temp;
            flag = true;
        }

        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    //storing the deepest node 
    deepest = temp;

    if(flag)
    {
        n->data = deepest->data;
        delete deepest;
        deepest = NULL;
    }
    else
    {
        cout<<"Value not found in the binary tree. Deletion not possible"<<endl;
        return;
    }
}

//main function
int main()
{
    struct node *root = NULL;
    int temp;
    root = create();
    LevelOrder(root);

    cout<<"Enter the node to be deleted : ";
    cin>>temp;
    Deletion(root,temp);

    LevelOrder(root);
    return 0;
}