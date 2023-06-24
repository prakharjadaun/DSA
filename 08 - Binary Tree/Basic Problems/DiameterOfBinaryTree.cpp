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
    int height(TreeNode *root)
    {
        if(!root)
            return 0;
        
        int l = height(root->left);
        int r = height(root->right);

        if(l>r)
            return 1+l;
        return 1+r;
    }
    int diameter(TreeNode *root)
    {
         if(!root)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        int ld = diameter(root->left);
        int rd = diameter(root->right);

        return max(lh + rh + 1, max(ld,rd));
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans = diameter(root);
        return ans==0? 0 : ans-1;
    }
};