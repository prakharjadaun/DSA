#include<unordered_set>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) 
    {
        unordered_set<char> hashset;
        for(char ch : brokenLetters)
        {
            hashset.insert(ch);
        }    
        int ans = 0;
        bool flag = true;
        stringstream ss(text);
        string word;
        while(ss>>word)
        {
            flag = true;
            for(int i=0;i<word.size();i++)
            {
                if(hashset.find(word[i])!=hashset.end())
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            ans++;
        }
        return ans;
    }
};