#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
    //function to perform the inorder traversal without recursion
    vector<int> Inorder(TreeNode *root,vector<int> r)
    {
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while(!st.empty() || curr!=NULL)
        {
            while(curr!=NULL)
            {
                st.push(curr);
                curr= curr->left;
            }

            curr = st.top();
            st.pop();
            //pushing the value of leaf nodes in the vector
            if(!curr->left && !curr->right)
                r.push_back(curr->val);
            curr = curr->right;
        }
        //returning the vector
        return r;
    }
    //function to find whether the two vectors are equal
    bool areEqual(vector<int> r1,vector<int> r2)
    {
        if(r1.size()!=r2.size())
        return false;

        for(int i=0;i<r1.size();i++)
        {
            if(r1[i]!=r2[i])
            return false;
        }
        return true;
    }
    //function to return whether the leaf of the two trees are similar or not
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> r1;
        vector<int> r2;

        r1 = Inorder(root1,r1);
        r2 = Inorder(root2,r2);

        return areEqual(r1,r2);

    }
};