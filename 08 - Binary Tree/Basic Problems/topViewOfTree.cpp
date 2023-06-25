#include<vector>
#include<map>
#include<queue>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

//function to get the top view from left to right
vector<int> getTopView(TreeNode<int> *root) 
{
    if(!root)
      return {};
    //consider two DS
    //1. queue : to store the node and the vertical level it belongs to (say root is 0, root->left is -1 and root->right is +1)
    //2. map : to store the first encountered vertical level values 
    queue<pair<TreeNode<int>*,int>> q;
    map<int,int> hashmap;
    q.push({root,0});
    hashmap[0] = root->val;

    pair<TreeNode<int>*,int> temp;
    //follow the simple level order traversal
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        //if the map do not contain that vertical level, insert that node value against that vertical level key
        if(hashmap.find(temp.second)==hashmap.end())
            hashmap[temp.second] = temp.first->val;
        
        //if the current node has left, push it into the queue with vertical_level-1
        if(temp.first->left)
            q.push({temp.first->left,temp.second-1});
        //if the current node has right, push it into the queue with vertical_level+1
        if(temp.first->right)
            q.push({temp.first->right,temp.second+1});
    }

    vector<int> res;
    //now insert all the keys of map to the resultant vector
    for(auto m : hashmap)
        res.push_back(m.second);
    return res;
}