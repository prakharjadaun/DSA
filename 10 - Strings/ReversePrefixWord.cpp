#include<iostream>
using namespace std;
#include<algorithm>
class Solution {
public:
    string reversePrefix(string word, char ch) 
    {
        bool flag = false;
        int index;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                index = i;
                flag = true;
                break;
            }
        }

        if(!flag)
            return word;
        
        string pre = word.substr(0,index+1);
        string last = word.substr(index+1,word.size()-index+1);
        reverse(pre.begin(),pre.end());
        return pre+last;
    }
};