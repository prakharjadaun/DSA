#include<iostream>
#include<queue>
using namespace std;

struct node 
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


//          1
//      2       3 NULL
//    4   5   6    7 NULL

void LevelOrder(struct node *root)
{
    if(!root)
    {
        return;
    }
    int level = 0;

    queue<struct node*> q;
    struct node *temp = NULL;
    q.push(root);
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
            cout<<temp->data<<endl;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}