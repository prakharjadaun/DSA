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
//time complexity : O(n)
//space complexity : O(n)
//function to search an element in a binary tree without recursion
int searchEle(struct node *root,int val)
{
    if(root)
    {
        if(root->data==val)
        return 1;

        struct node *temp = NULL;
        queue<struct node *> q;
        q.push(root);
        while(!q.empty())
        {
            temp = q.front();
            q.pop();

            if(temp->data == val)
            return 1;

            if(temp->left)
            q.push(temp->left);

            if(temp->right)
            q.push(temp->right);
        }
        return 0;
    }
    else
    {
        cout<<"binary tree is empty...!";
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