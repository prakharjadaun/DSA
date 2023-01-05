#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(a.size()==1 && a[0]=='0')
            return b;
        if(b.size()==1 && b[0]=='0')
            return a;
        
        string ans;
        int m = a.size()-1,n = b.size()-1,carry = 0;
        while(m>=0 || n>=0 || carry!=0)
        {
            if(m>=0)
            {
                carry += a[m] - '0';
                m--;
            }
            if(n>=0)
            {
                carry += b[n] - '0';
                n--;
            }

            ans += (carry%2 + '0');
            carry = carry/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};