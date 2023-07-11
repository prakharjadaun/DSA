#include<bits/stdc++.h>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
    vector<int> res;
public:
    //function to perform BFS to store the parent nodes
    void BFS(unordered_map<TreeNode*,TreeNode*> &hashmap,TreeNode *root)
    {   
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            if(node->left)
            {
                q.push(node->left);
                hashmap[node->left] = node;
            }
            if(node->right)
            {
                q.push(node->right);
                hashmap[node->right] = node;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        //hashmap to store the parent mapping
        unordered_map<TreeNode*,TreeNode*> hashmap;
        //mapping the parents
        BFS(hashmap,root);
        //hashmap to store the visited nodes
        unordered_map<TreeNode*,bool> vis;
        vector<int> res;

        //pushing the target to the queue
        queue<TreeNode*> q;
        vis[target] = true;
        q.push(target);
        //setting the dis to 0
        int cnt = 0;

        //simple level order traversal in three direction
        while(!q.empty())
        {
            int s = q.size();
            //after each level increase the counter
            if(cnt++ == k)
                break;
            for(int i=0;i<s;i++)
            {
                auto node = q.front();
                q.pop();
                //check in all three direction whether the node exists or not and is visited or not
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(hashmap.find(node)!=hashmap.end() && !vis[hashmap[node]])
                {
                    q.push(hashmap[node]);
                    vis[hashmap[node]] = true;
                }
            }
        }   
        //after cnt == k
        //all the elements in queue will be at distance k from the target
        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            res.push_back(node->val);
        }
        return res;
    }
};