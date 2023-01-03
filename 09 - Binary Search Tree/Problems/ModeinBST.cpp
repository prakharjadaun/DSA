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
private:
    vector<int> num;

public:
    void Inorder(TreeNode *root)
    {
        if (root)
        {
            Inorder(root->left);
            num.push_back(root->val);
            Inorder(root->right);
        }
    }
    vector<int> findMode(TreeNode *root)
    {
        Inorder(root);
        unordered_map<int, int> m;
        int freq = INT_MIN;
        vector<int> ans;
        for (int i = 0; i < num.size(); i++)
        {
            m[num[i]]++;
        }

        for (auto temp : m)
        {
            if (temp.second > freq)
            {
                freq = temp.second;
            }
        }

        for (auto temp : m)
        {
            if (temp.second == freq)
            {
                ans.push_back(temp.first);
            }
        }
        return ans;
    }
};