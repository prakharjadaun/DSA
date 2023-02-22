#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    bool digitCount(string num) 
    {
        string temp = num;
        for(int i=0;i<num.size();i++)
        {
            temp[num[i]-48]--;
        }   

        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]!='0')
                return false;
        } 
        return true;
    }
};