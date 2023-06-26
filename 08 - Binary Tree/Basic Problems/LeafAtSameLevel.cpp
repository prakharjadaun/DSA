//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


//The structure of the binary tree is as follows
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//insert all the levels in the hashset if the current node is a leaf node, if the hashset has size greater than 1, then return false
//other return true
//we achieve this by simple level order traversal
class Solution{
  public:
    bool check(Node *root)
    {
        //Your code here
        queue<pair<Node *,int>> q;
        q.push({root,0});
        unordered_set<int> hashset;
        pair<Node*, int> temp;
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            
            if(!temp.first->left && !temp.first->right) 
                hashset.insert(temp.second);
            else
            {
                if(temp.first->left)
                    q.push({temp.first->left,temp.second+1});
                if(temp.first->right)
                    q.push({temp.first->right,temp.second+1});
            }
            if(hashset.size()>1)
                return false;
        }
        
        return true;
    }
};

