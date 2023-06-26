#include<iostream>
using namespace std;
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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *p = head, *f = head;
        //first move the f pointer to n-1 times starting from 1
        for(int i=1;i<=n-1;i++)
        {
            f = f->next;
        }

        //then move f and p together and when f reaches the last node (not null), p reaches the nth node from last
        while(f->next!=NULL)
        {
            p = p->next;
            f = f->next;
        }

        //now p holds the node which has to be deleted
        f = head;   
        //if p is the first node, return the pointer to the next node (can be null)
        if(f == p)
            return f->next;
        while(f!=NULL)
        {
            //else check if f->next contains p, and if it does then remove it from the list
            if(f->next == p){
                f->next = f->next->next;
                break;
            }
            f = f->next;
        }
        return head;
    }
};