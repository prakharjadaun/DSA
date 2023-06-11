// Definition for a binary tree node.
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
    //function to check if their exist a path between root and leaf having sum equal to targetSum
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        //check if root is null, if null the sum do not exist
        if (!root)
            return false;
        //if you have reached a leaf node and root value is equal to targetsum, then a path exists
        if (!root->left && !root->right && root->val == targetSum)
            return true;
        //if you have reached a leaf node and root value is not equal to targetsum, then path do not exists
        if (!root->left && !root->right && root->val != targetSum)
            return false;
        //if you have not reached the leaf node then check if the left and right subtree has path which is equal to target sum
        //subtract the target sum with the current root value
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};