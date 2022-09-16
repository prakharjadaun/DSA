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

//function to find the maximum element of the binary tree without recursion
int findMaxEle(struct node *root)
{
    int maxN = INT_MIN;
    if(root)
    {
        struct node *temp = NULL;
        //creating a queue data structure to implement the level order traversal
        queue<struct node *> q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            //if any data comes with greater value than the maxN then we store that data value in the maxN
            if(temp->data > maxN)
            {
                maxN = temp->data;
            }

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return maxN;
}

//main function
int main()
{
    struct node *root = NULL;
    root = create();
    display(root);
    cout<<"Max element "<<findMaxEle(root)<<endl;
    return 0;
}