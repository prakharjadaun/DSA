#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<climits>
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

//function to find the maximum element of the binary tree
int findMaxEle(struct node *root)
{
    int root_val, left, right, maxNum = INT_MIN;
    if(root)
    {
        root_val = root->data;
        left = findMaxEle(root->left);
        right = findMaxEle(root->right);

        if(left > right)
        {
            maxNum = left;
        }
        else
        {
            maxNum = right;
        }
        if(root_val > maxNum)
        {
            maxNum = root_val;
        }
    }
    return maxNum;
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