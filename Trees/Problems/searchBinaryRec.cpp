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
//time complexity : O(n)
//space complexity : O(n)
//function to search an element in a binary tree
int searchEle(struct node *root,int val)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(root->data==val)
        {
            return 1;
        }
        else
        {
            int temp = searchEle(root->left,val);
            if(temp!=0)
            return 1;
            else
            {
                temp = searchEle(root->right,val);
                if(temp!=0)
                {
                    return temp;
                }
            }
        }
        return 0;
    }
}

//main function
int main()
{
    struct node *root = NULL;
    int temp;
    root = create();
    display(root);
    cout<<"Enter the value you need to search : ";
    cin>>temp;
    if(searchEle(root,temp))
    {
        cout<<"Element found...!"<<endl;
    }
    else
    {
        cout<<"Element not found...!"<<endl;
    }
    return 0;
}