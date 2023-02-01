//A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; 

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        solve(node);
    }
    
    int solve(Node *node)
    {
        if(!node)
            return 0;
            
        int temp = node->data;
        node->data = solve(node->left) + solve(node->right);
        
        return node->data + temp;
    }
};