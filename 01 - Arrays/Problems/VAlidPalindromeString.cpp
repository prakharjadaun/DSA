#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) 
    {
        stack<char> st;
        string str="";
        for(int i=0;i<s.size();i++)
        {
            if(iswalnum(s[i]))
            {
                if(isupper(s[i]))
                {
                    str += s[i]+32;
                    st.push(s[i]+32);
                }
                else
                {
                    str += s[i];
                    st.push(s[i]);
                }
            }
        }

        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=st.top())
                return false;
            st.pop();
        }
        return true;
    }
};
int main()
{
    Solution obj;
    string str = "A man, a plan, a canal: Panama";
    cout<<obj.isPalindrome(str);
}