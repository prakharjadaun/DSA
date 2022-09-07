#include<bits/stdc++.h>
using namespace std;

//definning the structure of the node of a binary tree
struct Node
{
    int data;
    struct Node *left,*right;
};

vector<int> reverseLevelOrder(struct Node *root)
{
    // code here
    stack<struct Node *> s;
    queue<struct Node *> q;
    q.push(root);
    struct Node *temp = NULL;
    while(q.empty()==false)
    {
        temp = q.front();
        s.push(temp);
        q.pop();
        
        if(temp->right)
            q.push(temp->right);
        
        if(temp->left)
            q.push(temp->left);
        
    }
    
    vector<int> v;
    while(s.empty()==false)
    {
        temp = s.top();
        s.pop();
        v.push_back(temp->data);
    }
    
    return v;
}