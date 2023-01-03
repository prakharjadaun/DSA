#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    //the logic is reverse of inorder traversal 
    // we will access the elements in decreasing order and will add all the elements and then assign new values
    void assignVal(TreeNode *root, int &ans)
    {
        if (root)
        {
            assignVal(root->right, ans);
            ans += root->val;
            root->val = ans;
            assignVal(root->left, ans);
        }
    }
    TreeNode *convertBST(TreeNode *root)
    {
        int ans = 0;
        assignVal(root, ans);
        return root;
    }
};