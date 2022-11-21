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

//function to identify whether the two binary trees are identical or 
//time complexity : O(n)
//space complexity : O(n) (for recursive stack)
int Identical(struct node *root1,struct node *root2)
{
    if(root1==NULL and root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    return (root1->data==root2->data && Identical(root1->left,root2->left) && Identical(root1->right,root2->right));
}

//main function
int main()
{
    struct node *root1 = NULL,*root2 = NULL;
    int temp;
    root1 = create();
    cout<<"Binary tree 1 : "<<endl;
    LevelOrder(root1);

    root2 = create();
    cout<<"Binary Tree 2 : "<<endl;
    LevelOrder(root2);

    if(Identical(root1,root2))
    {
        cout<<"Binary Trees are identical"<<endl;
    }
    else
    {
        cout<<"Binary Tree are not identical"<<endl;
    }
    
    return 0;
}