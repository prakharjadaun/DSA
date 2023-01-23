#include<queue>
#include<iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    //level order traversal approach
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode *>  q;
        TreeNode *curr = NULL;
        q.push(root);
        int ans;
        while(!q.empty())
        {
            int s = q.size();
            for(int i=0;i<s;i++)
            {
                curr = q.front();
                q.pop();
                if(i==0)
                    ans = curr->val;
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }   
        return ans; 
    }
};