#include<iostream>
using namespace std;
//Definition for singly-linked list.
      struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* rev(ListNode *head,ListNode *tail)
    {
        if(!head)
            return head;

        ListNode *curr = head,*prev = NULL, *temp = NULL;
        while(curr!=tail)
        {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(!head)
            return head;
        
        if(!head->next)
            return head;

        ListNode *curr = head, *start=NULL, *end = NULL,*prev=NULL;
        bool s = false;
        int i=1;
        while(curr)
        {
            if(i == left && s==false)
            {
                start = curr;
                s = true;
            }
            if(i == right)
            {
                end = curr->next;
                break;
            }
            if(!s)
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        if(prev == NULL)
        {
            head = rev(start,end);
        }
        else
        {
            curr = rev(start,end);
            cout<<prev->val<<endl;
            cout<<curr->val<<endl;
            prev->next = curr;
        }
        start->next = end;
        cout<<head->val<<endl;
        return head;
    }
};