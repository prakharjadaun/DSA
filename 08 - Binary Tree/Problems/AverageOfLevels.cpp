#include<iostream>
#include<vector>
#include<queue>
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

    vector<double> averageOfLevels(TreeNode* root) 
    {
        queue<TreeNode *> q;
        TreeNode *curr = NULL;
        vector<double> ans;
        q.push(root);
        //using the simple level order traversal
        while(!q.empty())
        {
            long temp = 0;
            int s = q.size();

            for(int i=0;i<s;i++)
            {
                curr = q.front();
                q.pop();
                temp += curr->val;

                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }

            ans.push_back((double)((double)temp/(double)s));
        }
        return ans;
    }

};