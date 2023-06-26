#include <bits/stdc++.h> 
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

//level order traversal
//when move left, increment the diagonal level and insert it into that 
vector<int> diagonalTraversal(TreeNode<int> *root) 
{
    if(!root)
        return {};

    queue<pair<TreeNode<int>*,int>> q;
    q.push({root,0});
    map<int,vector<int>> hashmap;

    pair<TreeNode<int>*,int> temp;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        hashmap[temp.second].push_back(temp.first->data);

        if(temp.first->left)
          q.push({temp.first->left,temp.second+1});
        if(temp.first->right)
            q.push({temp.first->right,temp.second});
    }

    vector<int> res;
    for(auto m : hashmap)
    {
        res.insert(res.end(),m.second.begin(),m.second.end());
    }

    return res;
}




