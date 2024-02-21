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
    ListNode *rev(ListNode *head)
    {
        ListNode *curr = head, *prev = NULL;
        while(curr)
        {
            auto temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    ListNode* doubleIt(ListNode* head) 
    {
        head = rev(head);
        int c = 0;
        auto temp = head;
        ListNode *tail;
        while(temp)
        {
            if(!temp->next)
                tail = temp;
            c += (temp->val*2);
            temp->val = c % 10;
            c/=10;
            temp = temp->next;
        }
        while(c)
        {
            tail->next = new ListNode(c%10);
            tail = tail->next;
            c/=10;
        }
        return rev(head);
    }
};