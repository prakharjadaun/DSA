#include <queue>
#include <iostream>
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
    int deepestLeavesSum(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
            return 0;

        TreeNode *curr = NULL;
        int levelsum = 0, temp = 0;
        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            curr = q.front();
            q.pop();

            if (curr == NULL)
            {
                if (!q.empty())
                {
                    q.push(NULL);
                }
                levelsum = temp;
                temp = 0;
            }
            else
            {
                temp += curr->val;
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        return levelsum;
    }
};