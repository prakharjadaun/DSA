#include<vector>
using namespace std;
#include<iostream>
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        if(!head || !head->next)
            return head;
        vector<ListNode *> vec;
        ListNode *curr = head,*tail = NULL;
        while(curr)
        {
            vec.push_back(curr);
            curr = curr->next;
        }

        head = NULL;
        for(int i=0;i<vec.size();i+=2)
        {
            if(i+1 < vec.size())
            {
                if(head==NULL)
                {
                    head = vec[i+1];
                    tail = vec[i+1];
                }
                else
                {
                    tail->next = vec[i+1];
                    tail = tail->next;
                }
            }

            tail->next = vec[i];
            tail = tail->next;  
        }
        tail->next = NULL;
        return head;
    }
};