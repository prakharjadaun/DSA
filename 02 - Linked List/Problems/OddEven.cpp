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
    ListNode* oddEvenList(ListNode* head) 
    {
        if(!head)
            return head;
        if(!head->next)
            return head;

        ListNode *odd = NULL,*tailodd=NULL, *even = NULL,*taileven = NULL;
        int i = 1;
        while(head!=NULL)
        {
            if(i%2==0)
            {
                if(even==NULL)
                {
                    even = head;
                    taileven = head;
                }
                else
                {

                    taileven->next = head;
                    taileven = taileven->next;
                }
            }
            else
            {
                if(odd == NULL)
                {
                    odd = head;
                    tailodd = head;
                }
                else
                {
                    tailodd->next = head;
                    tailodd = tailodd->next;
                }
            }
            i++;
            head = head->next;
        }    
        tailodd->next = even;
        taileven->next = NULL;
        return odd;
    }
};