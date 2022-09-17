#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<climits>
#include<queue>
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
void display(struct node *root)
{
    if(root)
    {
        cout<<root->data<<endl;
        display(root->left);
        display(root->right);
    }
}

//time complexity : O(N)
//space complexity : O(N)
//computing the height of the tree using recursion
int height(struct node *root)
{
    queue<struct node *> q;
    struct node *temp= NULL;
    if(root==NULL)
    return 0;
    int level=0;
    q.push(root);
    //end of first level
    q.push(NULL);

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            if(!q.empty())
            {
                q.push(NULL);
            }
            level++;
        }
        else
        {
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return level;
}

//main function
int main()
{
    struct node *root = NULL;
    int temp;
    root = create();
    display(root);
    cout<<"Height of tree : "<<height(root)<<endl;    
    return 0;
}