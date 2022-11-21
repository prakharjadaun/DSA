#include<iostream>
#include<queue>
using namespace std;

//definning the structure of the binary tree
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

//function to create the binary tree
struct node *create()
{
    int data;
    struct node *temp;
    cout<<"Enter the data : ";
    cin>>data;
    if(data==-1)
    return 0;
    else
    {
        temp = new node(data);
        cout<<"Enter the left of "<<data<<" : "<<endl;
        temp->left = create();
        cout<<"Enter the right of "<<data<<" : "<<endl;
        temp->right = create();
        return temp;
    }
}

//function to print the level order traversal of the binary tree
void LevelOrderTraversal(struct node *root)
{
    if(!root)
    {
        cout<<"Tree is empty...!"<<endl;
        return;
    }
    cout<<"Level order traversal of the binary tree : "<<endl;
    queue<struct node *> q;
    q.push(root);

    struct node *temp = NULL;
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

//function to print the right view of the binary tree using the level order traversal
void RightView(struct node *root)
{
    if(!root)
    {
        cout<<"Tree is empty..!"<<endl;
        return;
    }
    cout<<"Right view of the binary tree using level order traversal : "<<endl;
    int n;
    queue<struct node *> q;
    q.push(root);
    struct node *temp = NULL;
    while(!q.empty())
    {
        n = q.size();
        while(n--)
        {
            temp = q.front();
            q.pop();
            if(n==0)
            {
                cout<<temp->data<<endl;
            }

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    struct node *root = NULL;
    root = create();

    LevelOrderTraversal(root);
    RightView(root);
    return 0;
}