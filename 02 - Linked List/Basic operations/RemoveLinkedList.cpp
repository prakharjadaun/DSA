#include<iostream>
using namespace std;
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(!head)
            return head;

        ListNode *temp = head;
        while( temp!= NULL && temp->val==val)
        {
            temp = temp->next;
        }    
        head = temp;

        while(temp!=NULL)
        {
            if(temp->next!=NULL)
            {
                if(temp->next->val == val)
                temp->next = temp->next->next;
            }
            if(temp->next == NULL)
                break;
            if(temp->next && temp->next->val!=val)
                temp = temp->next;
        }
        return head;
    }
};