#include <bits/stdc++.h>
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
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> m;
        if (!root)
            return false;

        stack<TreeNode *> st;
        TreeNode *curr = root;
        st.push(root);

        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (m.find(curr->val) == m.end())
            {
                if (m.find(k - curr->val) != m.end())
                    return true;
            }
            m.insert(curr->val);
            curr = curr->right;
        }
        return false;
    }
};