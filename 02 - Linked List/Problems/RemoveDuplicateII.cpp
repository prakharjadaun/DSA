#include<unordered_map>
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

    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)
            return NULL;
        unordered_map<int,int> hashmap;
        ListNode *temp = head,*tail=NULL;
        while(temp)
        {
            hashmap[temp->val]++;
            temp = temp->next;
        } 

        temp = head;
        head = NULL;
        while(temp)
        {
            if(hashmap[temp->val]==1)
            {
                if(head==NULL)
                {
                    head = temp;
                    tail = temp;
                }
                else
                {
                    tail->next = temp;
                    tail = tail->next;
                }
            }
            temp = temp->next;
        }
        if(head)
        tail->next = NULL;
        return head;
    }
};