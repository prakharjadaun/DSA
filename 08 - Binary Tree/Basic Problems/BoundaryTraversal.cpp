//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

//time complexity: O(h) (left boundary)+ O(h)(right boundary) + O(n)(inorder traversal)

class Solution {
public:
    //function to check whether the passed node is leaf or not
    bool isLeaf(Node *root)
    {
        if(!root->left && !root->right)
            return true;
        return false;
    }
    
    //function to add all the left boundary elements
    void addLeftBoundary(vector<int> &res, Node *root)
    {
        Node *curr = root->left;
        while(curr)
        {
            //if it is not leaf, then only we add it 
             if(!isLeaf(curr))
            res.push_back(curr->data);
            if(curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }
    
    //function to add all the right boundary elemnts in reverse manner (because we are implementing the anticlockwise boundary traversal, and the right side of the boundary will be reversed)
    void addRightBoundary(vector<int> &res,Node *root)
    {
        vector<int> temp;
        Node *curr = root->right;
        while(curr)
        {
            //it should not be a leaf node
            if(!isLeaf(curr))
                temp.push_back(curr->data);
            if(root->right) 
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--)
            res.push_back(temp[i]);
    }
    //to add all the leaf nodes we just have to follow inorder traversal and if we encounter any leaf node we just have to add it to our result vector
    void addLeaves(vector<int> &res,Node *root)
    {
        
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)
        addLeaves(res,root->left);
        if(root->right)
        addLeaves(res,root->right);
    }
    //function to call the above sub functions
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int> res;
        if(!isLeaf(root))
            res.push_back(root->data);
        
        addLeftBoundary(res,root);
        addLeaves(res,root);
        addRightBoundary(res,root);
        
        return res;
    }
};
