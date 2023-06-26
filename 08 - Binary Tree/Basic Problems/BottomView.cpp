#include <bits/stdc++.h> 
using namespace std;

template <typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

//idea is to follow the simple level order traversal 
vector<int> bottomView(BinaryTreeNode<int> * root)
{
    queue<pair<BinaryTreeNode<int> *,int>> q;
    q.push({root,0});
    map<int,int> hashmap;
    pair<BinaryTreeNode<int> *,int> temp;

    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        hashmap[temp.second] = temp.first->data;

        if(temp.first->left)
            q.push({temp.first->left,temp.second-1});
        if(temp.first->right)
            q.push({temp.first->right,temp.second + 1});

    }

    vector<int> res;
    for(auto m : hashmap)
        res.push_back(m.second);

    return res;
    
}
