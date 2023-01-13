#include<iostream>
#include<stack>
#include<vector>
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
    int pairSum(ListNode* head) 
    {
        stack<int> st;
        vector<int> num;
        //storing all the elements into the stack and vector
        while(head!=NULL)
        {
            st.push(head->val);
            num.push_back(head->val);
            head = head->next;
        }    

        int ans = 0;
        for(int i=0;i<num.size()/2;i++)
        {
            //now getting the twin sums and storing the max in the ans variable
            if(num[i] + st.top() > ans)
            {
                ans = num[i] + st.top();
            }
            st.pop();
        }
        //returning the max twin sum
        return ans;
    }
};