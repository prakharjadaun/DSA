#include<unordered_set>
using namespace std;
#include<iostream>
class Solution {
public:
    string greatestLetter(string s) 
    {
        unordered_set<char> h1,h2;
        for(int i=0;i<s.size();i++)
        {
            if(islower(s[i]))
            {
                h1.insert(s[i]);
            }
            else
            {
                h2.insert(s[i]);
            }
        }
        string greater = "";
        char c = '0';
        for(char ch : h1)
        {
            if(h2.find(ch-32)!=h2.end())
            {
                if(c < ch - 32)
                {
                    c = ch - 32;
                }
            }
        }

        if(c=='0')
            return "";
        greater = c;
        return greater;
    }
};