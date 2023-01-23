#include<iostream>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool evaluateTree(TreeNode* root) 
    {
        if(!root->left && !root->right)
        {
            return root->val;
        }    

        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);

        if(root->val == 2)
        {
            root->val = left || right;
        }
        else
        {
            root->val = left && right;
        }

        return root->val;
    }
};