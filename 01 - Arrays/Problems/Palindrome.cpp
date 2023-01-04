#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) 
    {
        //if a number is negative then it will never be a palindrome
        if(x<0)
            return false;

        //converting the number to string 
        string str = to_string(x);
        //definning a stack
        stack<char> st;
        //pushing all the characters into the stack
        for(int i=0;i<str.size();i++)
        {
            st.push(str[i]);
        }
        //checking whether the each element of the string is equal from backwards that is the palindrome condition
        for(int i=0;i<str.size();i++)
        {
            //if it is not equal then return false
            if(str[i]!=st.top())
                return false;
            st.pop();
        }
        //otherwise your number is palindrome!
        return true;
    }
};