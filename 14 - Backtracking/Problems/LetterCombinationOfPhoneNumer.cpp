#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void letterCombine(string digits,vector<string> &output, string &temp,vector<string> &pad,int index)
    {
        if(index == digits.size())
        {
            output.push_back(temp);
            return;
        }

        string val = pad[digits[index]-'0'];
        for(int i=0;i<val.size();i++)
        {
            temp.push_back(val[i]);
            letterCombine(digits,output, temp, pad, index+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.empty())
            return {};

        vector<string> pad = {"", "", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string temp;
        vector<string> output;
        letterCombine(digits,output,temp,pad,0);
        return output;
    }
};