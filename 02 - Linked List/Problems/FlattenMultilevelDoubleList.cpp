
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void solve(Node *head,vector<Node *> &list)
    {
        if(!head)
            return;
        
        Node *curr = head;
        while(curr)
        {
            list.push_back(curr);
            if(curr->child)
                solve(curr->child,list);
            
            curr = curr->next;
        }
    }
    Node* flatten(Node* head) 
    {
        vector<Node *> list;
        solve(head,list);

        if(list.size()==0)
            return NULL;
        head = NULL;
        Node *tail = NULL;
        for(int i=0;i<list.size();i++)
        {
            if(i==0)
            {
                head = list[i];
                tail = head;
                head->prev = NULL;
                head->child=NULL;
            }
            else
            {
                list[i]->child = NULL;
                tail->next = list[i];
                tail->next->prev = tail;
                tail = tail->next;
            }
        }
        tail->next = NULL;
        return head;
    }
};