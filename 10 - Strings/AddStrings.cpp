#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string str = "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int i=0, j=0;
        int carry = 0;
        while(i<num1.size() && j<num2.size())
        {
            int temp = (num1[i]-'1' + 1) + (num2[i] - '1' + 1) + carry;
            carry = temp / 10;
            temp = temp % 10;
            str += to_string(temp);
            i++;
            j++;
        }

        while(i<num1.size())
        {
            int temp = (num1[i]-'1' + 1) + carry;
            carry = temp / 10;
            temp = temp % 10;
            str += to_string(temp);
            i++;
        }

        while(j<num2.size())
        {
            int temp = (num2[j]-'1' + 1) + carry;
            carry = temp / 10;
            temp = temp % 10;
            str += to_string(temp);
            j++;
        }

        if(carry == 1)
            str+="1";
        reverse(str.begin(),str.end());
        return str;
    }
};