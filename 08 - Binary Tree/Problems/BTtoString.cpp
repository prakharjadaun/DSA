#include<iostream>
#include<string>
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
private:
    string ans;
public:
    Solution()
    {
        ans = "";
    }
    void PreOrder(TreeNode *root)
    {
        if(root)
        {
            ans += to_string(root->val);
            if(root->left)
            {
                ans += "(";
                PreOrder(root->left);
                ans+=")";
            }
            if(root->right)
            {
                if(!root->left)
                ans+="()";
                ans+= "(";
                PreOrder(root->right);
                ans+=")";
            }
        }
    }
    string tree2str(TreeNode* root) 
    {
        PreOrder(root);
        return ans;    
    }
};