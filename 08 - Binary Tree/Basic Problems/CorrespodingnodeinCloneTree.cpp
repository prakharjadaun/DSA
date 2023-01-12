#include <queue>
#include<iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        queue<TreeNode *> q;
        TreeNode *temp = NULL;
        q.push(cloned);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->val == target->val)
                return temp;

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        return temp;
    }
};