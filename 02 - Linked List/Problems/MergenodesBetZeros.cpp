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
    ListNode* mergeNodes(ListNode* head) 
    {
        //approach : storing the answer in the nodes having zeros
        ListNode *fast = head->next,*slow = head,*ans = head;
        while(fast!=NULL)
        {
            if(fast->val!=0)
            {
                slow->val += fast->val;
            }
            else if(fast->val == 0 && fast->next!=NULL)
            {
                slow->next = fast;
                slow = slow->next;
            }
            else if(fast->val == 0 && fast->next==NULL)
            {
                slow->next = NULL;
            }
            fast = fast->next;
        }
        return ans;
    }
};