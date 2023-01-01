/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<math.h>
#include<iostream>
struct ListNode {
         int val;
    ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int len=0;
        ListNode *curr = head;
        if(head->next == NULL && head->val==0)
        return 0;
        //computing the length of the linked list
        while(curr)
        {
            curr = curr->next;
            len++;
        }    

        len = len - 1;

        curr = head;
        int ans = 0;
        while(curr)
        {
            ans = ans + (pow(2,len)*curr->val);
            len--;
            curr = curr->next;
        }

        return ans;
    }
};