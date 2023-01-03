#include <bits/stdc++.h>
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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = NULL;
        stack<TreeNode *> st;
        int ans = 0;
        if (root)
        {
            st.push(root);
            curr = root;
            while (!st.empty() || curr != NULL)
            {
                while (curr != NULL)
                {
                    st.push(curr);
                    curr = curr->left;
                }

                curr = st.top();
                st.pop();
                k--;
                if (k == 0)
                {
                    ans = curr->val;
                    break;
                }
                curr = curr->right;
            }
        }
        return ans;
    }
};