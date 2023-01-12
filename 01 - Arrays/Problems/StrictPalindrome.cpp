#include<stack>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isStrictlyPalindromic(int n) 
    {
        stack<int> st;
        vector<int> num;
        while(n!=0)
        {
            if(n & 1)
            {
                cout<<1;
                num.insert(num.end(),1);
                st.push(1);
            }
            else
            {
                cout<<0;
                num.insert(num.end(),0);
                st.push(0);
            }
            n = n >> 1;
        }    

        for(int i=0;i<num.size();i++)
        {
            if(num[i]!=st.top())
            return false;
            st.pop();
        }
        return true;
    }
};
int main()
{
    Solution sol;
    cout<<endl<<sol.isStrictlyPalindromic(9)<<endl;
}