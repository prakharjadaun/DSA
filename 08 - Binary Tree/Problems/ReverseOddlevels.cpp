#include<queue>
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
    TreeNode* reverseOddLevels(TreeNode* root) 
    {
        queue<TreeNode *> q;
        TreeNode *curr = NULL;
        stack<int> st;
        //approach : simply level order traversal with the track of node 
        //taking root node as level 0 and incrementing it
        //when level is even, push them into stack too
        //when level is odd, pop the stack value and assign them to the current queue value
        //all odd levels reversed!
        int i=0;
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
                    i++;
                }
            }
            else
            {
                if(i%2==0)
                {   
                    if(curr->left)
                    st.push(curr->left->val);
                    if(curr->right)
                    st.push(curr->right->val);
                }
                else
                {
                    curr->val = st.top();
                    st.pop();
                }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }    
        return root;
    }
};