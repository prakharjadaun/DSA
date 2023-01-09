#include<vector>
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
private:
public:
    //in recursion we used to do
    /*void Preorder(TreeNode *root)
    {
        if(root)
        {
            cout<<root->data<<endl;
            Preorder(root->left);
            Preorder(root->right);
        }
    }
    */
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *curr = root;
        stack<TreeNode *> st;
        vector<int> ans;
        if (!root)
            return ans;

        st.push(root);

        while (!st.empty())
        {
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);
            // we are using stack, and because of that we are pushing the right node first
            if (curr->right)
                st.push(curr->right);
            // and here comes the left node
            if (curr->left)
                st.push(curr->left);
        }
        return ans;
    }
};