#include<vector>
#include<iostream>
#include<stack>
using namespace std;
//   Definition for singly-linked list.
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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> res;
        stack<int> st;
        head = rev(head);
        //5->1->2
        auto curr = head;
        while(curr)
        {
            while(!st.empty() && st.top() <= curr->val)
            {
                st.pop();
            }

            res.insert(res.begin(),st.empty()? 0 : st.top());
            st.push(curr->val);
            curr = curr->next;
        }
        return res;
    }
};