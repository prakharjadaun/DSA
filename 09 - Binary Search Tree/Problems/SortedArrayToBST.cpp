#include<iostream>
#include<vector>
using namespace std;
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
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        TreeNode *root = NULL;
        int mid = nums.size() / 2;
        root = new TreeNode(nums[mid]);

        vector<int> l(nums.begin(), nums.begin() + mid);
        vector<int> r(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(l);
        root->right = sortedArrayToBST(r);

        return root;
    }
};