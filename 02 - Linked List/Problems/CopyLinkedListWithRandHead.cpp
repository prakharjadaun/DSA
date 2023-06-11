
#include<iostream>
#include<unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*,int> orig;
        unordered_map<int,Node*> origRand;
        unordered_map<int,Node*> copy;

        Node *copyHead = NULL,*tail = NULL;
        Node *temp = head;
        int i=0;
        while(temp)
        {
            Node *curr = new Node(temp->val);
            orig[temp] = i;
            origRand[i] = temp->random;
            copy[i] = curr;
            if(!copyHead)
            {
                copyHead = curr;
                tail = curr;
            }
            else
            {
                tail->next = curr;
                tail = tail->next;
            }
            i++;
            temp = temp->next;
        }

        temp = head;
        tail = copyHead;
        i=0;
        while(temp)
        {
            if(temp->random == NULL)
                tail->random = NULL;
            else
                tail->random = copy[orig[origRand[i]]];
            tail = tail->next;
            temp = temp->next;
            i++;
        }
        return copyHead;
    }
};