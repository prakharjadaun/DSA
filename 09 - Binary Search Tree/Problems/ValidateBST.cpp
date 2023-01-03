#include<iostream>
#include<vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<int> num;
public:
    //since inorder traversal of bst is always an increasing order array
    void Inorder(TreeNode* root)
    {
        if(root)
        {
            Inorder(root->left);
            num.push_back(root->val);
            Inorder(root->right);
        }
    }
    
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
            return false;
        
        bool flag = true;
        Inorder(root);
        //checking if the inorder traversal results in an increasing order array
        for(int i=0;i<num.size()-1;i++)
        {
            if(num[i] >= num[i+1])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};