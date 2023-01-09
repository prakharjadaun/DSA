#include<iostream>
#include<vector>
#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        vector<int> temp;
        int i=0;
        if(!root)    
            return ans;
        TreeNode *curr;
        q.push(root);
        //represents the ending of a level
        q.push(NULL);
        //starting with the basic level order traversal
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            //if curr is null, that means a level has ended
            if(curr==NULL)
            {
                //if the queue is not yet empty, push null to it
                if(!q.empty())
                {
                    q.push(NULL);
                }
                //if the level (0-indexed) is even, we will reverse the temp and add it to the ans vector
                if(i%2==1)
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                temp.clear();
                //incrementing the level
                i++;
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
        return ans;
    }
};