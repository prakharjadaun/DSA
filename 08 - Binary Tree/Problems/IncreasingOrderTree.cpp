#include <iostream>
#include<stack>
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
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root;
        TreeNode *head = NULL;
        TreeNode *tail = NULL;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        //approach -> iterate through simple algorithm of inorder traversal of binary tree and link all the nodes in increasing order
        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            if (head == NULL)
            {
                head = curr;
                tail = head;
                head->left = NULL;
            }
            else
            {
                tail->right = curr;
                tail = tail->right;
                tail->left = NULL;
            }

            curr = curr->right;
        }

        return head;
    }
};