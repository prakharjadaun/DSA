#include <iostream>
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
    int ans;

public:
    Solution()
    {
        ans = 0;
    }
    int tilt(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = tilt(root->left);
        int right = tilt(root->right);
        ans += (abs(left - right));
        return root->val + left + right;
    }
    int findTilt(TreeNode *root)
    {
        tilt(root);
        return ans;
    }
};