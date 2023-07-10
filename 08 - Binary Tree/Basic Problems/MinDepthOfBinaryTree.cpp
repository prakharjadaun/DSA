#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int minDepth(TreeNode* root) 
    {
        if(!root)
            return 0;
        //normal level order traversal with the level starting from 1
        //return the first node's level which is a leaf node
        queue<pair<TreeNode *,int>> q;
        q.push({root,1});

        while(!q.empty())
        {
            auto [node,cnt] = q.front();
            q.pop();

            if(!node->left && !node->right)
                return cnt;

            if(node->left)
                q.push({node->left,cnt+1});

            if(node->right)
                q.push({node->right,cnt+1});

        }
        return -1;

    }
};