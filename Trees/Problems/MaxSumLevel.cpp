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

int MaxSumLevel(struct node *root)
{
    int currSum = 0,maxSum = 0;
    if(!root)
    {
        cout<<"Binary tree is empty....!"<<endl;
        return 0;
    }

    int level=0,maxLevel=0;
    struct node *temp = NULL;
    queue<struct node *> q;
    q.push(root);
    q.push(NULL);       //end of a level

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        if(temp==NULL)
        {
            if(currSum>maxSum)
            {
                maxSum = currSum;
                maxLevel=level;
            }
            currSum = 0;
            if(!q.empty())
                q.push(NULL);
            level++;
        }
        else
        {
            currSum += temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return maxLevel;
}

//main function
int main()
{
    struct node *root = NULL;
    int temp;
    root = create();
    LevelOrder(root);
    cout<<"Level with max sum : "<<MaxSumLevel(root)<<endl;
    return 0;
}