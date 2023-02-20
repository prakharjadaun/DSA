#include<stack>
using namespace std;
#include<iostream>
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
    void reorderList(ListNode* head) 
    {
        if(!head || !head->next)
            return;
        stack<ListNode *> st;

        ListNode *curr = head,*tail = NULL;


        while(curr)
        {
            st.push(curr);
            curr = curr->next;
        }    
        curr = head;
        head = NULL;
        int i = 0;
        while(st.top() != curr && curr!=NULL)
        {
            if(i%2==0)
            {
                if(!head)
                {
                    head = curr;
                    tail = curr;
                }
                else
                {
                    tail->next = curr;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            else
            {
                tail->next = st.top();
                st.pop();
                tail = tail->next;  
            }
            i++;
        }
        tail->next = st.top();
        tail = tail->next;
        tail->next = NULL;
    }
};