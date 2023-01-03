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
    vector<int> l1, l2;

public:
    void Inorder1(TreeNode *root1)
    {
        if (root1)
        {
            Inorder1(root1->left);
            l1.push_back(root1->val);
            Inorder1(root1->right);
        }
    }

    void Inorder2(TreeNode *root2)
    {
        if (root2)
        {
            Inorder2(root2->left);
            l2.push_back(root2->val);
            Inorder2(root2->right);
        }
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        Inorder1(root1);
        Inorder2(root2);

        vector<int> ans;
        vector<int>::iterator it1, it2;

        it1 = l1.begin();
        it2 = l2.begin();

        while (it1 != l1.end() && it2 != l2.end())
        {
            if (*it1 < *it2)
            {
                ans.push_back(*it1);
                it1++;
            }
            else
            {
                ans.push_back(*it2);
                it2++;
            }
        }

        while (it1 != l1.end())
        {
            ans.push_back(*it1);
            it1++;
        }

        while (it2 != l2.end())
        {
            ans.push_back(*it2);
            it2++;
        }

        return ans;
    }
};