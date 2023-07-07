
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
    int sumOfLeftLeaves(TreeNode* root) {
        queue<pair<TreeNode *,int>> q;
        int res = 0;
        q.push({root,0});
        while(!q.empty())
        {
            auto [node,n] = q.front();
            q.pop();

            if(!node->left && !node->right && n)
                res+= node->val;

            if(node->left)
                q.push({node->left,1});
            if(node->right)
                q.push({node->right,0});
        }
        return res;
    }
};