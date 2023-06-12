#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
            return NULL;
        vector<Node *> store;
        queue<Node *> q;
        Node *curr = NULL;
        q.push(root);

        while(!q.empty())
        {
            int len = q.size();
            for(int i=0;i<len;i++)
            {
                curr = q.front();
                q.pop();
                store.push_back(curr);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            store.push_back(NULL);

            for(int i=0;i<store.size()-1;i++)
            {
                store[i]->next = store[i+1];
            }
            store.clear();
        }
        return root;
    }
};