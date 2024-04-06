
#include<bits/stdc++.h>
using namespace std;
 // Definition for a binary tree node.
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
    vector<int> solve(TreeNode *root,int &ans)
    {
        if(!root)
            return {};
        
        vector<int> left(solve(root->left,ans)), right(solve(root->right,ans));
        if(left.size()==0 && right.size()==0)
        {
            ans++;
            return {1,root->val};
        }

        int total = 0;
        int cnt = 0;
        if(left.size()>0)
        {
            cnt += left[0];
            total += left[1];
        }

        if(right.size()>0)
        {
            cnt+= right[0];
            total+= right[1];
        }

        if(((root->val + total)/(cnt+1)) == root->val)
            ans++;
        
        return {cnt+1,total+root->val};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int ans = 0;
        solve(root,ans);
        return ans;
    }
};