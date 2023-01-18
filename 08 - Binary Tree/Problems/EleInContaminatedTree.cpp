#include <unordered_set>
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

class FindElements
{
    //using unordered_set for storing the unique values
    unordered_set<int> s;

public:
    //using preorder traversal for iterating to all the nodes of the tree
    void preOrder(TreeNode *root)
    {
        if (root)
        {
            if (root->left)
            {
                root->left->val = (2 * root->val) + 1;
                s.insert(root->left->val);
            }
            if (root->right)
            {
                root->right->val = (2 * root->val) + 2;
                s.insert(root->right->val);
            }

            preOrder(root->left);
            preOrder(root->right);
        }
    }
    //calling the preorder traversal function from the constructor
    FindElements(TreeNode *root)
    {
        //assigning 0 to the root node
        root->val = 0;
        s.insert(0);
        preOrder(root);
    }

    //using unordered_set to find whether the tree contains that element or not
    bool find(int target)   
    {
        if (s.find(target) != s.end())
            return true;
        return false;
    }
};
