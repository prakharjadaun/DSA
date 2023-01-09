#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        vector<int> temp;
        queue<TreeNode *> q;
        TreeNode *curr;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            curr = q.front();
            q.pop();

            if(curr==NULL)
            {
                if(!q.empty())
                {
                    q.push(NULL);
                }
                ans.push_back(temp);
                temp.clear();
            }
            else
            {
                temp.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

        }    
        reverse(ans.begin(),ans.end());
        return ans;
    }
};