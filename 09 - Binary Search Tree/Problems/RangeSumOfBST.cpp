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
    //approach : inorder traversal without recursion 
    // keep on adding elements when you encounter the value inclusive in high and low
    //time complexity : O(n)
    // space complexity : O(1)
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        TreeNode *curr = root;
        stack<TreeNode *> st;
        st.push(root);
        bool flag = false;
        int ans = 0;
        while (!st.empty() || curr != NULL)
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            if ((curr->val >= low) && (curr->val <= high))
            {
                ans += curr->val;
                if (curr->val == high)
                    break;
            }
            curr = curr->right;
        }
        return ans;
    }
};