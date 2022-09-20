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

//function to check whether the two functions are mirror of each other or not
int AreMirrors(struct node *root1,struct node *root2)
{
    if(root1 && root2)
        return 1;
    if(root1 || root2)
        return 0;
    if(root1->data != root2->data)
        return 0;
    return AreMirrors(root1->left,root2->right) && AreMirrors(root1->right,root2->left);
}

//main function
int main()
{
    struct node *root1 = NULL,*root2 = NULL;

    root1 = create();
    cout<<"Tree 1 : "<<endl;
    LevelOrder(root1);

    root2 = create();
    cout<<"Tree2 : "<<endl;
    LevelOrder(root2);

    if(AreMirrors(root1,root2))
    {
        cout<<"Both the trees are mirror of each other"<<endl;
    }
    else
    {
        cout<<"Both the trees are not mirror of each other"<<endl;
    }
    return 0;
}