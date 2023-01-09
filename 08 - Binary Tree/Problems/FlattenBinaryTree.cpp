#include<stack>
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
    void flatten(TreeNode* root) 
    {
        if(!root )
            return;
        if(!root->left && !root->right)
            return;

        TreeNode *curr = root,*tail = NULL,*temp;
        root = NULL;

        stack<TreeNode *> st;
        st.push(curr);
        while(!st.empty())
        {
            temp = st.top();
            st.pop();
            if(temp->right)
                st.push(temp->right);
            if(temp->left)
                st.push(temp->left);
            if(root==NULL)
            {
                root = temp;
                root->left = NULL;
                root->right = NULL;
                tail = root;
            }
            else
            {
                tail->right = temp;
                tail = tail->right;
                tail->left = NULL;
                tail->right = NULL;
            }
        }
    }
};